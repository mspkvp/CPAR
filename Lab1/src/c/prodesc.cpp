#include <omp.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <thread>
#include "myClass.h"
#define MIN(a,b) a<b ? a:b
#pragma comment(linker, "/STACK:3246391296") // ~3GB | Precisamos de mais do que 2GB para fazer 10000 x 10000

using namespace std;

struct thread_args {
	int posi;
	int posf;
	int size;
	CdMatriz *A;
	CdMatriz *B;
	CdMatriz *C;
};

int DifTime(SYSTEMTIME &Time1, SYSTEMTIME &Time2)
{
	int temp, factor, total=0;

	temp = Time2.wMilliseconds - Time1.wMilliseconds;
	factor = 0;
	if (temp < 0)
	{	temp += 1000;
		factor = 1;
	}
	total = temp;

	temp = Time2.wSecond - Time1.wSecond - factor;
	factor = 0;
	if (temp < 0)
	{	temp += 60;
		factor = 1;
	}
	total += temp * 1000;

	temp = Time2.wMinute - Time1.wMinute - factor;
	factor = 0;
	if (temp < 0)
	{	temp += 60;
		factor = 1;
	}
	total += temp * 60 * 1000;

	temp = Time2.wHour - Time1.wHour - factor;
	if (temp < 0) temp += 60;
	total += temp * 60 * 60 * 1000; 

	return(total);
}

void threadMult(thread_args args) {
	int i, j, k;
	for (i = args.posi; i<args.posf; i++)
	{
		for (k = 0; k<args.size; k++)
		{
			for (j = 0; j<args.size; j++)
			{
				args.C->operator()(i, j, args.C->operator()(i, j) + args.A->operator()(i, k) * args.B->operator()(k, j));
			}
		}
	}
}

void OnMult(int m_ar, int m_br, int nt) 
{
	// TODO: Add your command handler code here
	SYSTEMTIME Time1, Time2;
	
	char st[100];
	double temp;
	int i, j, k;

	HGLOBAL ha, hb, hc;
	double *pha, *phb, *phc;
	

	if (1)
	{
		ha = GlobalAlloc(GMEM_FIXED, (m_ar * m_ar) * sizeof(double));
		hb = GlobalAlloc(GMEM_FIXED, m_br * m_br * sizeof(double));
		hc = GlobalAlloc(GMEM_FIXED, m_ar * m_br * sizeof(double));
		
		pha = (double *)GlobalLock(ha);
		phb = (double *)GlobalLock(hb);
		phc = (double *)GlobalLock(hc);
	
		CdMatriz A(pha, m_ar, m_ar);
		CdMatriz B(phb, m_br, m_br);
		CdMatriz C(phc, m_ar, m_br);


		for(i=0; i<m_ar; i++)
			for(j=0; j<m_ar; j++)
				A(i,j,(double)1.0);


		for(i=0; i<m_br; i++)
			for(j=0; j<m_br; j++)
				B(i,j,(double)(i+1));


		GetLocalTime(&Time1);

		// OpenMP version 
		#pragma omp parallel for shared(A,B,C) private(k,j) num_threads(nt) // 1...4 threads
		for(i=0; i<m_ar; i++)
		{	for( k=0; k<m_br; k++)
			{	
				for( j=0; j<m_ar; j++)
				{	
					C(i, j, C(i,j) + A(i, k) * B(k, j));
				}
			}
		}

		/* ------ Explicit Thread version ------ */
		/*
		const int nr_threads = 4; //1...4
		const int n_per_thread = m_br / nr_threads;
		
		thread threadList[nr_threads];

		for (int tn = 0; tn < nr_threads; tn++){
			thread_args t_args;
			t_args.posi = tn * n_per_thread;
			t_args.posf = (1 + tn)*n_per_thread;
			t_args.size = m_br;
			t_args.A = &A;
			t_args.B = &B;
			t_args.C = &C;
			threadList[tn] = thread (threadMult, t_args);
		}

		for (int tn = 0; tn < nr_threads; tn++){
			threadList[tn].join();
		}
		*/

		GetLocalTime(&Time2);
		sprintf(st, "Time: %3.3f seconds\n", ((float) DifTime(Time1, Time2)/1000.0));
		cout << st;

		/*
		cout << "Result matrix: " << endl;
		for(i=0; i<1; i++)
		{	for(j=0; j<min(10,m_br); j++)
				cout << C(i,j) << " ";
		}
		cout << endl;*/

		GlobalUnlock(ha);
		GlobalUnlock(hb);
		GlobalUnlock(hc);

		::GlobalFree(ha);
		::GlobalFree(hb);
		::GlobalFree(hc);


	}
	
}

void OnMultblock(int m_ar, int m_br, int nt) 
{
	// TODO: Add your command handler code here

	SYSTEMTIME Time1, Time2;
	char st[100];
	double temp, wlimit, qlimit, elimit;
	int i, j, k, N, w,e,q, Bsize;
	int iBase, jBase, kBase;
	int m_block;
	
	HGLOBAL ha, hb, hc;
	double *pha, *phb, *phc;


	if (1)
	{
	   	printf("Block size? ");
	   	scanf_s("%d", &m_block);

		ha = GlobalAlloc(GMEM_FIXED, (m_ar * m_ar) * sizeof(double));
		hb = GlobalAlloc(GMEM_FIXED, m_br * m_br * sizeof(double));
		hc = GlobalAlloc(GMEM_FIXED, m_ar * m_br * sizeof(double));
		
		pha = (double *)GlobalLock(ha);
		phb = (double *)GlobalLock(hb);
		phc = (double *)GlobalLock(hc);
	
		CdMatriz A(pha, m_ar, m_ar);
		CdMatriz B(phb, m_br, m_br);
		CdMatriz C(phc, m_ar, m_br);
	
		


		for(i=0; i<m_ar; i++)
		{	for(j=0; j<m_ar; j++)
			{	A(i,j,(double)1.0);
				C(i,j,(double)0.0);
			}
		}



		for(i=0; i<m_ar; i++)
			for(j=0; j<m_br; j++)
				B(i,j,(double)(i+1));


		GetLocalTime(&Time1);


		N = m_ar / m_block;

		Bsize = m_block;


		for(i=0; i<=N; i++)
		{	
			for(j=0; j<=N; j++)
			{		
				for(k=0; k<=N; k++)
				{

				}
			}
		}



		GetLocalTime(&Time2);
		sprintf(st, "Time: %3.3f seconds\n", ((float) DifTime(Time1, Time2)/1000.0));
		cout << st;

		cout << "Result matrix: " << endl;
		for(i=0; i<1; i++)
		{	for(j=0; j<MIN(10,m_br); j++)
				cout << C(i,j) << " ";
		}
		cout << endl;

		GlobalUnlock(ha);
		GlobalUnlock(hb);
		GlobalUnlock(hc);

		::GlobalFree(ha);
		::GlobalFree(hb);
		::GlobalFree(hc);
	}

	
}

float produtoInterno(float *v1, float *v2, int col)
{
	int i;
	float soma=0.0;	

	for(i=0; i<col; i++)
		soma += v1[i]*v2[i];
	
	return(soma);

}

int main (int argc, char *argv[])
{

	double area, pi, x;
	int i, n;
	char c;
	int lin, col, nt=1;
	int op;

	cout <<  "Lines: " << argv[1] << endl
		<< "Columns: " << argv[2] << endl
		<< "Nr Threads: " << argv[3] << endl;
	lin = atoi(argv[1]);
	col = atoi(argv[2]);
	nt = atoi(argv[3]);

	OnMult(lin, col, nt);
	
	op=1;
	/*do {
		cout << endl << "1. Multiplication" << endl;
		cout << "2. Block Multiplication" << endl;
		cout << "Selection?: ";
		scanf_s("%d", &op);
		if (op == 0)
			break;
		printf("Dimensions: lins cols ? ");
   		scanf_s("%d %d", &lin, &col);


		switch (op){
			case 1: 
				OnMult(lin, col, nt);
				break;
			case 2:
				OnMultblock(lin, col, nt);
				break;
		}
	}while (op != 0);
	*/

	/*
	cout << "Enter to continue ...";
	cin.get(c);*/
	return 0;
}
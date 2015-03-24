// matrixMult.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma comment(linker, "/STACK:3246391296")
#define matrixSize 10000
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double A[matrixSize][matrixSize],
		B[matrixSize][matrixSize],
		C[matrixSize][matrixSize];
	int l=10000, c=10000, i, j, k;
	/*cout << "Lines x Columns?\n> ";
	
	cin >> l >> c;

	A = new double*[l];
	B = new double*[l];
	C = new double*[l];

	for (i = 0; i < l; i++){
		A[i] = new double[c];
	}

	for (i = 0; i < l; i++){
		B[i] = new double[c];
	}

	for (i = 0; i < l; i++){
		C[i] = new double[c];
	}*/

	cout << "lines: " << l << " cols: " << c << endl;

	for (i = 0; i < l; i++){
		for (int j = 0; i < l; i++){
			A[i][j] = 1.0;
		}
	}

	for (i = 0; i < l; i++){
		for (int j = 0; i < l; i++){
			B[i][j] = 1.0+i;
		}
	}

	for (i = 0; i<matrixSize; i++)
	{
		for (k = 0; k<matrixSize; k++)
		{
			for (j = 0; j < matrixSize; j++)
			{
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}

	system("PAUSE");
	return 0;
}


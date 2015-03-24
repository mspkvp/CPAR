// matrixMult.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double **A, **B, **C;
	int l, c;
	cout << "Lines x Columns?\n> ";
	
	cin >> l >> c;

	cout << "lines: " << l << " cols: " << c << endl;

	A = new double*[l];
	B = new double*[l];
	C = new double*[c];

	for (int i = 0; i < l; i++){
		A[i] = new double[c];
	}

	for (int i = 0; i < l; i++){
		B[i] = new double[c];
	}

	for (int i = 0; i < c; i++){
		C[i] = new double[l];
	}

	for (int i = 0; i < l; i++){
		for (int j = 0; i < l; i++){
			A[i][j] = 1.0;
		}
	}

	for (int i = 0; i < l; i++){
		for (int j = 0; i < l; i++){
			B[i][j] = 1.0+i;
		}
	}



	system("PAUSE");
	return 0;
}


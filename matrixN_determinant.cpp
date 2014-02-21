// matrixN_determinant.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

#define N 3
#define EPSILON 1e-10

typedef enum { 
	FALSE, 
	TRUE
} booliane;

void print(double a[][N]) {
	/*
	* print the matrix.
	*/
	int i, j;

	for (i = 0; i<N; ++i) {
		for (j = 0; j<N; ++j)
			printf("%8.4g ", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

void divRow(double a[][N], int row, double divisor) {
	/*
	* divides row of a by divisor.
	*/
	int j;
	for (j = 0; j<N; ++j)
		a[row][j] /= divisor;
}

void subRow(double a[][N], int row1, int row2) {
	/*
	* row1 -= row2.
	*/
	int j;
	for (j = 0; j<N; ++j)
		a[row1][j] -= a[row2][j];
}

bool anyZero(double a[][N]) {
	/*
	* returns TRUE if any diagonal entry of a is zero (less than EPSILON).
	*/
	int i;
	for (i = 0; i<N; ++i)
	if (fabs(a[i][i]) <= EPSILON)
		return TRUE;
	return FALSE;
}

double makeUpper(double a[][N]) {
	/*
	* makes a an upper-triangular matrix.
	* returns 0 if any of the diagonal entries are 0; 1 otherwise.
	*/
	int i, j;
	double factor = 1.0;
	double temp;

	for (i = 1; i<N; ++i)    // dont worry about row 0.
	for (j = 0; j<i; ++j) {
		temp = a[i][j];
		if (fabs(temp) > EPSILON) {
			printf("factor=%g dividing row %d by %g...\n", factor, i, temp);
			divRow(a, i, temp);
			print(a);
			factor *= temp;
		}
		temp = a[j][j];
		if (fabs(temp) > EPSILON && fabs(temp - 1.0) > EPSILON) {
			printf("factor=%g dividing row %d by %g...\n", factor, j, temp);
			divRow(a, j, temp);
			print(a);
			factor *= temp;
		}
		if (fabs(a[i][j]) > EPSILON) {
			printf("factor=%g row[%d] -= row[%d]...\n", factor, i, j);
			subRow(a, i, j);
			print(a);
		}
		if (anyZero(a) == TRUE)
			return 0;
	}
	a[N - 1][N - 1] *= factor;        // all but(?) last element of row N-1 are zero.

	return 1;
}

double multDia(double a[][N]) {
	/*
	* returns multiplication of diagonal elements.
	*/
	int i;
	double factor = 1;

	for (i = 0; i<N; ++i)
		factor *= a[i][i];
	return factor;
}

int _tmain(int argc, _TCHAR* argv[])
{
	double a[N][N] = { { 8, 0, 1 },
					   { 2, 1, 3 },
					   { 5, 3, 9 }
					 };
	double factor;
	print(a);
	factor = makeUpper(a);
	print(a);
	printf("determinant = %g.\n", factor*multDia(a));

	cin.get();
	cin.ignore();
	return 0;
}

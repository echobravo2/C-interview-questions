// matrixRotate90.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

#define N 3

void print(int a[][N]) {
	/*
	* print the matrix.
	*/
	int i, j;

	for (i = 0; i<N; ++i) {
		for (j = 0; j<N; ++j)
			printf("%4d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

void cyclic_roll(int &a, int &b, int &c, int &d)
{
	int temp = a;
	a = b;
	b = c;
	c = d;
	d = temp;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int i, j;

	int m[N][N] = { 
					   { 8, 0, 1 },
					   { 2, 1, 3 },
					   { 5, 3, 9 }
					 };

	print(m);

	for (int i = 0; i<N / 2; i++)
	for (int j = 0; j<(N + 1) / 2; j++)
		cyclic_roll(
			m[i][j], 
			m[N - 1 - j][i], 
			m[N - 1 - i][N - 1 - j], 
			m[j][N - 1 - i]
			);

	/*Explaining the indexes.. well, think where the location at (i,j) goes when 
	rotating 90 degrees. Just imagine the picutre. (i,j)->(end-j, i). As high as 
	the original was far from the left, and as far from the left as it was from 
	the bottom of the matrix
	http://stackoverflow.com/questions/2893101/how-to-rotate-a-n-x-n-matrix-by-90-degrees
	*/
	print(m);

	cin.get();
	cin.ignore();
	return 0;
}

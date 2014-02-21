// arrayFnc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

void read(int *, int);
void dis(int *, int);
void  inverse(int *, int);
void inverseHold(int a[], int inverse_b[], int j);

int _tmain(int argc, _TCHAR* argv[])
{
	int a[5], b[5], sum = 0, i;

	//clrscr();
	printf("Enter the elements of array \n");
	read(a, 5);      /*read the array*/
	printf("The array elements are \n");
	dis(a, 5);

	for (i = 0; i<5; i++)
	{
		sum += a[i];
	}
	printf("The sum of the elements of the list is %d\n", sum);

	inverse(a, 5);
	dis(a, 5);

	inverseHold(a, b, 5);
	dis(b, 5);


	cin.get();
	return 0;
}

void read(int c[], int i)
{
	int j;
	for (j = 0; j<i; j++)
		scanf_s("%d", &c[j]);

	fflush(stdin);
}

void dis(int d[], int i)
{
	int j;
	for (j = 0; j<i; j++)
		printf("%d ", d[j]);
	printf("\n");
}

void inverse(int inver_a[], int j)
{
	int i, temp;
	j--;

	for (i = 0; i<(j / 2); i++)
	{
		temp = inver_a[i];
		inver_a[i] = inver_a[j];
		inver_a[j] = temp;
		j--;
	}
}

void inverseHold(int a[], int inverse_b[], int j)
{
	int i, k;
	k = j - 1;
	for (i = 0; i<j; i++)
	{
		inverse_b[i] = a[k];
		k-- ;
	}
}

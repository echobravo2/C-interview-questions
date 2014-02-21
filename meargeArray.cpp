// arrayFnc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

void read(int *, int);
void dis(int *, int);
void inverse(int *, int);
void inverseHold(int a[], int inverse_b[], int j);
void merge(int *, int *, int *, int);
void sort(int arr[], int k);

int _tmain(int argc, _TCHAR* argv[])
{
	int a[5], b[5], c[10];

	printf("Enter the elements of first list \n");
	read(a, 5);      /*read the list*/
	printf("The elements of first list are \n");
	dis(a, 5);  /*Display the first list*/
	printf("Enter the elements of second list \n");
	read(b, 5);   /*read the list*/
	printf("The elements of second list are \n");
	dis(b, 5);  /*Display the second list*/
	sort(a, 5);
	printf("The sorted list a is:\n");
	dis(a, 5);
	sort(b, 5);
	printf("The sorted list b is:\n");
	dis(b, 5);

	merge(a, b, c, 5);
	printf("The elements of merged list are \n");
	dis(c, 10);  /*Display the merged list*/


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
void sort(int arr[], int k)
{
	int temp;
	int i, j;
	for (i = 0; i<k; i++)
	{
		for (j = 0; j<k - i - 1; j++)
		{
			if (arr[j]<arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void merge(int a[], int b[], int c[], int k)
{
	int ptra = 0, ptrb = 0, ptrc = 0;
	while (ptra<k && ptrb<k)
	{
		if (a[ptra] < b[ptrb])
		{
			c[ptrc] = a[ptra];
			ptra++;
		}
		else
		{
			c[ptrc] = b[ptrb];
			ptrb++;
		}
		ptrc++;
	}
	while (ptra<k)
	{
		c[ptrc] = a[ptra];
		ptra++; ptrc++;
	}
	while (ptrb<k)
	{
		c[ptrc] = b[ptrb];
		ptrb++;  ptrc++;
	}
}

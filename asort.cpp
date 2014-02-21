// asort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

#define MAX 10
void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
int getkeyposition(int i, int j)
{
	return((i + j) / 2);
}
void qsort(int list[], int m, int n)
{
	int key, i, j, k;
	if (m < n)
	{
		k = getkeyposition(m, n);
		swap(&list[m], &list[k]);
		key = list[m];
		i = m + 1;
		j = n;
		while (i <= j)
		{
			while ((i <= n) && (list[i] <= key))
				i++;
			while ((j >= m) && (list[j] > key))
				j-- ;
			if (i < j)
				swap(&list[i], &list[j]);
		}
		swap(&list[m], &list[j]);
		qsort(list, m, j - m);
		qsort(list, j + 1, n);
	}
}
void readlist(int list[], int n)
{
	int i;
	printf("Enter the elements\n");
	for (i = 0; i<n; i++)
		scanf_s("%d", &list[i]);
}
void printlist(int list[], int n)
{
	int i;
	printf("The elements of the list are: \n");
	for (i = 0; i<n; i++)
		printf("%d\t", list[i]);
}



int _tmain(int argc, _TCHAR* argv[])
{
	int list[MAX], n;
	printf("Enter the number of elements in the list max = 10\n");
	scanf_s("%d", &n);
	readlist(list, n);
	printf("The list before sorting is:\n");
	printlist(list, n);
	qsort(list, 0, n - 1);
	printf("\nThe list after sorting is:\n");
	printlist(list, n);

	cin.get();
	cin.ignore();
	return 0;
}


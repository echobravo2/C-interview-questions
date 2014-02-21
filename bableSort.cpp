// bableSort.cpp : Defines the entry point for the console application.
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
void bsort(int list[], int n)
{
	int i, j;
	for (i = 0; i<(n - 1); i++)
	for (j = 0; j<(n - (i + 1)); j++)
	if (list[j] > list[j + 1])
		swap(&list[j], &list[j + 1]);
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
	bsort(list, n);
	printf("The list after sorting is:\n");
	printlist(list, n);

	cin.get();
	cin.ignore();
	return 0;
}


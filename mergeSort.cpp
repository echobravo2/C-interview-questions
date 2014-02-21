// mergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

#define MAX 10
void merge(int list[], int list1[], int k, int m, int n)
{
	int i, j;
	i = k;
	j = m + 1;
	while (i <= m && j <= n)
	{
		if (list[i] <= list[j])
		{
			list1[k] = list[i];
			i++;
			k++;
		}
		else
		{
			list1[k] = list[j];
			j++;
			k++;
		}
	}
	while (i <= m)
	{
		list1[k] = list[i];
		i++;
		k++;
	}
	while (i <= n)
	{
		list1[k] = list[j];
		j++;
		k++;
	}
}

void mpass(int list[], int list1[], int l, int n)
{
	int i;
	i = 0;
	while (i <= (n - 2 * l + 1))
	{
		merge(list, list1, i, (i + l - 1), (i + 2 * l - 1));
		i = i + 2 * l;
	}
	if ((i + l - 1) < n)
		merge(list, list1, i, (i + l - 1), n);
	else
	while (i <= n)
	{
		list1[i] = list[i];
		i++;
	}
}
void msort(int list[], int n)
{
	int l;
	int list1[MAX];
	l = 1;
	while (l <= n)
	{
		mpass(list, list1, l, n);
		l = l * 2;
		mpass(list1, list, l, n);
		l = l * 2;
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
	msort(list, n - 1);
	printf("The list after sorting is:\n");
	printlist(list, n);

	cin.get();
	cin.ignore();
	return 0;
}


// smallestMissingN_inArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

/* Utility to swap to integers */
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int findSmallestMissingNumber(int a[], const int n)
{
	int i = 0, j = 0;



	//Place all element at the position same as its value 
	while (i<n)
	{ 
		printf("n = %d, i = %d  a[i] = %d\n", n, i, a[i]);
		for (j = 0; j < n; j++) printf("%d ,", a[j] );		printf("\n");

		//Skip the element if its already in correct position 
		//Or its value is out of array index range 
		//Consider zero is not the positive value 
		if (a[i] < 1 || a[i] > n - 1 || a[i] == i)
		{
			i++;
			printf("not entering swap\n");
		}
		//Swap the element with it's proper position 
		else
		{
			printf("before swaping\n");
			printf("%d , %d\n", a[i], a[a[i]]);
			swap(&a[i], &a[a[i]]);
			printf("after swaping\n");
			printf("%d , %d\n", a[i], a[a[i]]);
			for (j = 0; j < n; j++) printf("%d ,", a[j]);		printf("\n");
		}
	}
	
	for (i=1; i<n; i++) { 
		if (a[i] != i) 
			return i; 
	}


	return n;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[] = { 7,6,5,4,3,2,1,0 };
	int arr_size = sizeof(arr) / sizeof(arr[0]); printf("array size: %d\n", sizeof(arr) / sizeof(arr[0]));
	int missing = findSmallestMissingNumber(arr, arr_size);
	printf("The smallest positive missing number is %d ", missing);
	
	
	getchar();

	//cin.get();
	//cin.ignore();
	return 0;

}

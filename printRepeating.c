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

//void printRepeating(int arr[], int size)
//{
//	int i, j;
//
//	printf("The repeating elements are: \n");
//	for (i = 0; i < size; i++)
//	{
////		printf("size = %d, i = %d  arr[%d] = %d  arr[abs(arr[%d])] = %d\n", size, i, i, arr[i], i, arr[abs(arr[i])]);
////		for (j = 0; j < size; j++) printf("%d ,", arr[j]);		printf("\n");
//
//		if (arr[abs(arr[i])] >= 0)
//		{
////			printf("arr[abs(arr[%d])] %d ==> -arr[abs(arr[%d])] = %d\n", i, arr[abs(arr[i])], i, -arr[abs(arr[i])]);
//			arr[abs(arr[i])] = -arr[abs(arr[i])];
//		}
//		else
//			printf("--> %d \n", abs(arr[i]));
//	}
//}

void toBin(int num)
{
	int remainder;

	if (num <= 1)
	    {
			cout << num;
		}

	remainder = num % 2;
	toBin(num >> 1);
	cout << remainder;
}

void printRepeating1(int arr[], int size)
{
	int temp = 0;
	int t = 0;
	
	printf("The repeating elements are: \n");
	for (int i = 0; i < size; i++)
	{
		printf("i = %d, temp = %d, t = %d, (1 << arr[i]) = %d, (temp & (1 << arr[i])) = %d\n", i, temp, t, 1 << arr[i], temp & (1 << arr[i]));
//		toBin(1 << arr[i]); printf("\n");
//		toBin(temp & (1 << arr[i])); printf("\n");

		if (temp & (1 << arr[i]))
		{
			if (t &(1 << arr[i]))
			{
//				printf("temp = %d t = %d\n", temp, t);
//				printf("--->%d \n", arr[i]);
				t = t ^ (1 << arr[i]);
				printf("t = %d \n", t);
			}
		}

		else
		{
//			printf("\n");
			temp = (temp | (1 << arr[i]));
			t = (t | (1 << arr[i]));
//			printf("i = %d, temp = %d, t = %d\n", i, temp, t);
//			toBin(1 << arr[i]); printf("\n");
//			toBin(temp | (1 << arr[i])); printf("\n");
//			toBin(t | (1 << arr[i])); printf("\n");
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int arr[] = { 1, 2, 3, 1, 6, 3 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	printRepeating1(arr, arr_size);

	getchar();

	//cin.get();
	//cin.ignore();
	return 0;

}

// MaximumRepeatingInteger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

int maxRepeating(int* arr, int n, int k);

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[] = { 2, 3, 3, 5, 3, 4, 1, 7, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 9;
	
	cout << sizeof(arr) << " " << sizeof(arr[0]) << endl;
	cout << n << endl;

	cout << "The maximum repeating number is " <<
		maxRepeating(arr, n, k) << endl;
	cin.get();
	return 0;
}

// Returns maximum repeating element in arr[0..n-1].
// The array elements are in range from 0 to k-1
int maxRepeating(int* arr, int n, int k)
{
	// Iterate though input array, for every element
	// arr[i], increment arr[arr[i]%k] by k
	for (int i = 0; i< n; i++)
		arr[arr[i] % k] += k;

	// Find index of the maximum repeating element
	int max = arr[0], result = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			result = i;
			cout << i << " " << arr[i] << ", ";
		}
	}
	cout << endl;

	/* Uncomment this code to get the original array back
	for (int i = 0; i< n; i++)
	arr[i] = arr[i]%k; */

	// Return index of the maximum element
	return result;
}

// FindMeargeArrMedian.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int median(int arr[], int k);

int _tmain(int argc, _TCHAR* argv[])
{
	int const N = 9;
	int array1[] = { 2, 6, 4, 9, 5, 8, 4, 2, 9 };
	int array2[] = { 22, 16, 14, 19, 15, 18, 14, 12, 19 };
	int median1, median2;
	median1 = median(array1, N);
	median2 = median(array2, N);
	cout << median1 << " " << median2 << endl;
	cin.get();
	return 0;
}

int median(int arr[], int k) {

	int temp;
	int minIndex;
	int minValue;

	for (int i = 1; i < k; i++){
		minIndex = i;
		minValue = arr[i];
		for (int j = i + 1; j < k; j++){
			if (arr[j] < minValue){
				minIndex = j;
				minValue = arr[j];
				temp = arr[i];
				arr[i] = arr[minIndex];
				arr[minIndex] = temp;
			}
		}
		return arr[k];
	}
}


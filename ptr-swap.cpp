// ptr-swap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void swap1(int left, int right);
void swap2(int *p_left, int *p_right);
void swap3(int &left, int &right);

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 1, y = 2;
	int &w = x, &z = y;

	//local change only - local copy
	swap1(x, y);
	cout << x << " " << y << '\n';
	
	//by pointer
	swap2(&x, &y);
	cout << x << " " << y << '\n';

	//by reference
	swap3(w, z);
	cout << w << " " << z << '\n';

	cin.get();
	cin.ignore();
	return 0;
}

void swap1(int left, int right)
{
	int temp;
	temp = left;
	left = right;
	right = temp;
}
void swap2(int *p_left, int *p_right)
{
	int temp = *p_left;
	*p_left = *p_right;
	*p_right = temp;
}

void swap3(int &left, int &right)
{
	int temp = left;
	left = right;
	right = temp;
}

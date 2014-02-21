// TwoStackUsingArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;

#define N 10                   // combined size of the two stacks.
#define SUCCESS 0              // success code.

typedef int type;              // type of each data item.

type twostacks[N];             // stacks implemented using array.
int stop1 = -1;                // pointer for stack 1.
int stop2 = N;                 // pointer for stack 2.
const int EINDEXOUTOFBOUND = -1;				   // error code on overflow in the stacks.

int sPush(int stacki, type data) {
	/*
	* pushes data on top of stacki.
	* returns error on overflow.
	*/
	if (stop2 - stop1 == 1) // overflow.
		return EINDEXOUTOFBOUND;

	if (stacki == 1) { // first stack.
		twostacks[++stop1] = data;
	}
	else {             // second stack.
		twostacks[--stop2] = data;
	}
	return SUCCESS;
}

int sDelete(int stacki) {
	/*
	* deletes element at top from stacki.
	*/
	printf("deleting from stack %d...\n", stacki);

	if (stacki == 1) { // first stack.
		if (stop1 >= 0)
			--stop1;
		else
			return EINDEXOUTOFBOUND;

	}
	else {          // second stack.
		if (stop2 < N)
			++stop2;
		else
			return EINDEXOUTOFBOUND;
	}
	return SUCCESS;
}
void sPrint() {
	/*
	* prints the two stacks.
	*/
	int i;
	for (i = 0; i <= stop1; ++i)
		printf("%d ", twostacks[i]);
	printf(": ");
	for (i = stop2; i<N; ++i)
		printf("%d ", twostacks[i]);
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	sPush(1, 1);
	sPrint();
	sPush(2, 1);
	sPrint();
	sPush(1, 4);
	sPrint();
	sPush(2, 5);
	sPrint();
	sDelete(2);
	sDelete(2);
	sPrint();
	sDelete(2);
	sDelete(1);
	sDelete(1);
	sDelete(1);
	sPrint();
	sPush(2, 2);
	sPush(1, 9);
	sPrint();
	sDelete(1);
	sPrint();
	sDelete(2);
	sPrint();
	sPush(2, 0);
	sPush(1, 5);
	sPush(1, 3);
	sPrint();
	sDelete(2);
	sPrint();

	//getchar();
	cin.get();
	cin.ignore();
	return 0;
}

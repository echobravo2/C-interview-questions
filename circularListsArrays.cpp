// circularListsArrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;

#define N 10                // size of the list.
#define FIRSTINDEX 0 // index of first element in the list.
#define ILLEGALINDEX -1     // illegal index - for special cases.
#define EINDEXOUTOFBOUND -1 // error code on overflow in the list.
#define SUCCESS 0           // success code.

typedef int type;           // type of each data item.

type clist[N];          // list implemented using array.
int front = ILLEGALINDEX;   // points to first element in the list.
int rear;                           // points to last element in the list.

int lPush(type data) {
	/*
	* appends 'data' to the end of the list if space is available.
	* otherwise returns error.
	*/
	if (front == ILLEGALINDEX) { // list empty.
		front = rear = FIRSTINDEX;
	}
	else if ((rear + 1) % N == front) { // list overflow.
		return EINDEXOUTOFBOUND;
	}
	else      // normal case.
		rear = (rear + 1) % N;   // %N for wrapping around of index.
	clist[rear] = data;
	return SUCCESS;
}

int lGetNElements() {
	/*
	* returns no of elements in the list.
	*/
	if (front == ILLEGALINDEX)       // empty list.
		return 0;
	else if (front <= rear) // no wrapping of rear.
		return (rear - front + 1);
	else                                             // wrapping of rear.
		return (N - front + rear + 1);
}

void lPrint() {
	/*
	* prints elements in the list from front to rear.
	*/
	int i;
	int nelem = lGetNElements();

	for (i = 0; i<nelem; ++i)
		printf("%d ", clist[(front + i) % N]);
	printf("\n");
}

int lDeleteK(int k) {
	/*
	* deletes k'th element in the list if present.
	* otherwise returns error.
	* k starts from 1.
	* this procedure may be improved by checking for number of elements
	* to be shifted after deleting k'th element. thus we can shift either
	* k+1..N elements or 1..K-1 elements.
	*/
	int index, i;
	int nelem = lGetNElements();
	printf("deleting %d'th element...\n", k);
	if (k > nelem || k < 1)
		return EINDEXOUTOFBOUND;

	index = (front + k - 1) % N;   // index of the element to be deleted.

	for (i = k + 1; i <= nelem; ++i)
		clist[(front + i - 2) % N] = clist[(front + i - 1) % N];

	if (nelem == 1) // list is empty now.
		front = ILLEGALINDEX;
	else if (k == 1)
		front = (front + 1) % N;
	else
		rear = (rear - 1 + N) % N;

	return SUCCESS;
}

int lInsertAfterK(type data, int k) {
	/*
	* inserts 'data' after k'th element in the list.
	* if list is full or k is out of bounds, error is returned.
	* k starts from 0.
	*/
	int i, index;

	int nelem = lGetNElements();
	printf("inserting %d after %d'th element...\n", data, k);
	if (k > nelem || k < 0 || nelem == N)
		return EINDEXOUTOFBOUND;
	if (nelem == 0) // list empty.
		front = rear = FIRSTINDEX;
	else
		rear = (rear + 1) % N;

	index = (front + k) % N;   // index at which data should be inserted.

	for (i = nelem; i>k; --i)
		clist[(front + i) % N] = clist[(front + i - 1) % N];
	clist[(front + k) % N] = data;
}


int _tmain(int argc, _TCHAR* argv[])
{
	lInsertAfterK(100, 0);
	lPrint();
	lPush(0);
	lPush(4);
	lPush(7);
	lPush(1);
	lPush(13);
	lPush(2);
	lPush(5);
	lPrint();
	lInsertAfterK(2, 1);
	lPrint();
	lDeleteK(4);
	lPrint();
	lPush(6);
	lPush(3);
	lPush(23);
	lPrint();
	lDeleteK(9);
	lPrint();
	lInsertAfterK(20, 9);
	lPrint();
	lDeleteK(10);
	lPrint();
	lInsertAfterK(20, 0);
	lPrint();

	cin.get();
	cin.ignore();
	return 0;

}


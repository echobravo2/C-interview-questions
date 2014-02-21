// queueNoneCirc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

#define MAX 10 /* The maximum size of the queue */
#include <stdlib.h>

void q_insert(int queue[], int *rear, int value)
{
	if (*rear < MAX - 1)
	{
		*rear = *rear + 1;
		queue[*rear] = value;
	}
	else
	{
		printf("The queue is full can not insert a value\n");
		exit(0);
	}
}

void q_delete(int queue[], int *front, int rear, int * value)
{
	if (*front == rear)
	{
		printf("The queue is empty can not delete a value\n");
		exit(0);
	}
	*front = *front + 1;
	*value = queue[*front];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int queue[MAX];
	int front, rear;
	int n, value;
	front = rear = (-1);
	do
	{
		do
		{
			printf("Enter the element to be inserted\n");
			scanf_s("%d", &value);
			q_insert(queue, &rear, value);
			printf("Enter 1 to continue\n");
			scanf_s("%d", &n);
		} while (n == 1);

		printf("Enter 1 to delete an element\n");
		scanf_s("%d", &n);
		while (n == 1)
		{
			q_delete(queue, &front, rear, &value);
			printf("The value deleted is %d\n", value);
			printf("Enter 1 to delete an element\n");
			scanf_s("%d", &n);
		}
		printf("Enter 1 to continue\n");
		scanf_s("%d", &n);
	} while (n == 1);


	cin.get();
	cin.ignore();
	return 0;
}

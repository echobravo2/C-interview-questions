// stackArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define MAX 10 /* The maximum size of the stack */
#include <stdlib.h>

void push(int stack[], int *top, int value)
{
	if (*top < MAX)
	{
		*top = *top + 1;
		stack[*top] = value;
	}
	else
	{
		printf("The stack is full can not push a value\n");
		exit(0);
	}
}

void pop(int stack[], int *top, int * value)
{
	if (*top >= 0)
	{
		*value = stack[*top];
		*top = *top - 1;
	}
	else
	{
		printf("The stack is empty can not pop a value\n");
		exit(0);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int stack[MAX];
	int top = -1;
	int n, value;
	do
	{
		do
		{
			printf("Enter the element to be pushed\n");
			scanf_s("%d", &value);
			push(stack, &top, value);
			printf("Enter 1 to continue\n");
			scanf_s("%d", &n);
		} while (n == 1);

		printf("Enter 1 to pop an element\n");
		scanf_s("%d", &n);
		while (n == 1)
		{
			pop(stack, &top, &value);
			printf("The value poped is %d\n", value);
			printf("Enter 1 to pop an element\n");
			scanf_s("%d", &n);
		}
		printf("Enter 1 to continue\n");
		scanf_s("%d", &n);
	} while (n == 1);


	cin.get();
	cin.ignore();
	return 0;
}

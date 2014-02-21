// stackLinked.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct node
{
	int data;
	struct node *link;
};
struct node *push(struct node *p, int value)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	/* creates new node
	using data value
	passed as parameter */
	if (temp == NULL)
	{
		printf("No Memory available Error\n");
		exit(0);
	}
	temp->data = value;
	temp->link = p;
	p = temp;
	return(p);
}

struct node *pop(struct node *p, int *value)
{
	struct node *temp;
	if (p == NULL)
	{
		printf(" The stack is empty can not pop Error\n");
		exit(0);
	}
	*value = p->data;
	temp = p;
	p = p->link;
	free(temp);
	return(p);
}


int _tmain(int argc, _TCHAR* argv[])
{
	struct node *top = NULL;
	int n, value;
	do
	{
		do
		{
			printf("Enter the element to be pushed\n");
			scanf_s("%d", &value);
			top = push(top, value);
			printf("Enter 1 to continue\n");
			scanf_s("%d", &n);
		} while (n == 1);

		printf("Enter 1 to pop an element\n");
		scanf_s("%d", &n);
		while (n == 1)
		{
			top = pop(top, &value);
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

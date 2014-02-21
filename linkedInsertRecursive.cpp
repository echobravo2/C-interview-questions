// linkedInsertRecursive.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;
struct node
{
	int data;
	struct node *link;
};
struct node *insert(struct node *p, int n)
{
	if (p == NULL)
	{
		p = (struct node *)malloc(sizeof(struct node));
		if (p == NULL)
		{
			printf("Error\n");
			exit(0);
		}
		p->data = n;
		p->link = NULL;
	}
	else
		p->link = insert(p->link, n);/* the while loop replaced by
									 recursive call */
	return (p);
}
void printlist(struct node *p)
{
	printf("The data values in the list are\n");
	while (p != NULL)
	{
		printf("%d\t", p->data);
		p = p->link;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int x;
	struct node *start = NULL;
	printf("Enter number of nodes to be created \n");
	scanf_s("%d", &n);
	while (n-- > 0)
	{
		printf("Enter the data values to be placed in a node\n");
		scanf_s("%d", &x);
		start = insert(start, x);
	}
	printf("The created list is\n");
	printlist(start);


	cin.get();
	cin.ignore();
	return 0;
}

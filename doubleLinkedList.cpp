// doubleLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;
struct dnode
{
	int data;
	struct dnode *left, *right;
};
struct dnode *insert(struct dnode *p, struct dnode **q, int n)
{
	struct dnode *temp;
	/* if the existing list is empty then insert a new node as the
	starting node */
	if (p == NULL)
	{
		p = (struct dnode *)malloc(sizeof(struct dnode)); /* creates new node data value passed as parameter */
		if (p == NULL)
		{
			printf("Error\n");
			exit(0);
		}
		p->data = n;
		p->left = p->right = NULL;
		*q = p;
	}
	else
	{
		temp = (struct dnode *)malloc(sizeof(struct dnode)); /* creates new node using data value passed as parameter and puts its address in the temp */
		if (temp == NULL)
		{
			printf("Error\n");
			exit(0);
		}
		temp->data = n;
		temp->left = (*q);
		temp->right = NULL;
		(*q)->right = temp;
		(*q) = temp;
	}
	return (p);
}
void printfor(struct dnode *p)
{
	printf("The data values in the list in the forward order are:\n");
	while (p != NULL)
	{
		printf("%d\t", p->data);
		p = p->right;
	}
}
void printrev(struct dnode *p)
{
	printf("The data values in the list in the reverse order are:\n");
	while (p != NULL)
	{
		printf("%d\t", p->data);
		p = p->left;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int x;
	struct dnode *start = NULL;
	struct dnode *end = NULL;
	printf("Enter the nodes to be created \n");
	scanf_s("%d", &n);
	while (n-- > 0)
	{
		printf("Enter the data values to be placed in a node\n");
		scanf_s("%d", &x);
		start = insert(start, &end, x);
	}
	printf("The created list is\n");
	printfor(start);
	printrev(end);

	cin.get();
	cin.ignore();
	return 0;
}

// doubleLinkedInsertNew.cpp : Defines the entry point for the console application.
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
		p = (struct dnode *)malloc(sizeof(struct dnode)); /* creates new
														  node data value
														  passed as parameter */

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
		temp = (struct dnode *)malloc(sizeof(struct dnode)); /* creates
															 new node using
															 data value passed as
															 parameter and puts its
															 address in the temp
															 */
		if (temp == NULL)
		{
			printf("Error\n");
			exit(0);
		}
		temp->data = n;
		temp->left = (*q);
		temp->right = NULL;
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
/* A function to count the number of nodes in a doubly linked list */
int nodecount(struct dnode *p)
{
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->right;
	}
	return(count);
}

/* a function which inserts a newly created node after the specified node in a doubly linked list */
struct dnode * newinsert(struct dnode *p, int node_no, int value)
{
	struct dnode *temp, *temp1;
	int i;
	if (node_no <= 0 || node_no > nodecount(p))
	{
		printf("Error! the specified node does not exist\n");
		exit(0);
	}
	if (node_no == 0)
	{
		temp = (struct dnode *)malloc(sizeof (struct dnode));
		if (temp == NULL)
		{
			printf(" Cannot allocate \n");
			exit(0);
		}
		temp->data = value;
		temp->right = p;
		temp->left = NULL;
			p = temp;
	}
	else
	{
		temp = p;
		i = 1;
		while (i < node_no)
		{
			i = i + 1;
			temp = temp->right;
		}
		temp1 = (struct dnode *)malloc(sizeof(struct dnode));
		if (temp1 == NULL)
		{
			printf("Cannot allocate \n");
			exit(0);
		}
		temp1->data = value;
		temp1->right = temp->right;
		temp1->left = temp;
		temp1->right->left = temp1;
		temp1->left->right = temp1;
	}
	return (p);
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
	printf("enter the node number after which the new node is to be	inserted\n");
		scanf_s("%d", &n);
	printf("enter the data value to be placed in the new node\n");
	scanf_s("%d", &x);
	start = newinsert(start, n, x);
	printfor(start);

	cin.get();
	cin.ignore();
	return 0;
}

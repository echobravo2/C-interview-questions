// doubleLinkedListDelete.cpp : Defines the entry point for the console application.
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
		p = (struct dnode *)malloc(sizeof(struct dnode)); /* creates new node
														  data value
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

/* a function which inserts a newly created node after the specified
node in a doubly
linked list */
struct dnode * double_delete(struct dnode *p, int node_no, int *val)
{
	struct dnode *temp, *prev = NULL;
	int i;
	if (node_no <= 0 || node_no > nodecount(p))
	{
		printf("Error! the specified node does not exist\n");
		exit(0);
	}
	if (node_no == 0)
	{
		temp = p;
		p = temp->right;
		p->left = NULL;
		*val = temp->data;
		return(p);
	}
	else
	{
		temp = p;
		i = 1;
		while (i < node_no)
		{
			i = i + 1;
			prev = temp;
			temp = temp->right;
		}
		prev->right = temp->right;
		if (temp->right != NULL)
			temp->right->left = prev;
		*val = temp->data;
		free(temp);
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
	printf("enter the number of the node which is to be deleted\n");
	scanf_s("%d", &n);
	start = double_delete(start, n, &x);
	printf("The data value of the node deleted from list is :%d\n",x);
		printf("The list after deletion of the specified node is :\n");
	printfor(start);

	cin.get();
	cin.ignore();
	return 0;
}

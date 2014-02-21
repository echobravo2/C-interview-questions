// linkedEraseList.cpp : Defines the entry point for the console application.
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
struct node *insert(struct node *, int);
void erase(struct node **, struct node **);
void printlist(struct node *);

void erase(struct node **p, struct node **free)
{
	struct node *temp;
	temp = *p;
	while (temp->link != NULL)
		temp = temp->link;
	temp->link = (*free);
	*free = *p;
	*p = NULL;
}

struct node *insert(struct node *p, int n)
{
	struct node *temp;
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
	{
		temp = p;
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = (struct node *)malloc(sizeof(struct node));
		if (temp->link == NULL)
		{
			printf("Error\n");
			exit(0);
		}
		temp = temp->link;
		temp->data = n;
		temp->link = NULL;
	}
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
	struct node *free = NULL;

	/* this code will create a free list for the test purpose*/
	printf("Enter the number of nodes in the initial free list \n");
	scanf_s("%d", &n);
	while (n-- > 0)
	{
		printf("Enter the data values to be placed in a node\n");
		scanf_s("%d", &x);
		free = insert(free, x);
	}

	/* this code will create a list to be erased*/
	printf("Enter the number of nodes in the list to be created for	erasing \n");
		scanf_s("%d", &n);
	while (n-- > 0)
	{
		printf("Enter the data values to be placed in a node\n");
		scanf_s("%d", &x);
		start = insert(start, x);
	}
	printf("The free list islist is:\n");
	printlist(free);
	printf("The list to be erased is:\n");
	printlist(start);
	erase(&start, &free);
	printf("The free list after adding all the nodes from the list to be erased is : \n");
	printlist(free);

	cin.get();
	cin.ignore();
	return 0;
}



// linkedInsert2sortedList.cpp : Defines the entry point for the console application.
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
struct node *sinsert(struct node*, int);
void printlist(struct node *);
struct node *sortlist(struct node *);
int nodecount(struct node*);

/* A function to count the number of nodes in a singly linked list */
int nodecount(struct node *p)
{
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->link;
	}
	return(count);
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

/* a function to sort a list */
struct node *sortlist(struct node *p)
{
	struct node *temp1, *temp2, *min, *prev, *q;
	q = NULL;
	while (p != NULL)
	{
		prev = NULL;
		min = temp1 = p;
		temp2 = p->link;
		while (temp2 != NULL)
		{
			if (min->data > temp2->data)
			{
				min = temp2;
				prev = temp1;
			}
			temp1 = temp2;
			temp2 = temp2->link;
		}
		if (prev == NULL)
			p = min->link;
		else
			prev->link = min->link;
		min->link = NULL;
		if (q == NULL)
			q = min; /* moves the node with lowest data value in the list
					 pointed to by p to the list
					 pointed to by q as a first node*/
		else
		{
			temp1 = q;
			/* traverses the list pointed to by q to get pointer to its
			last node */
			while (temp1->link != NULL)
				temp1 = temp1->link;
			temp1->link = min; /* moves the node with lowest data value
							   in the list pointed to
							   by p to the list pointed to by q at the end of list pointed by
							   q*/
		}
	}
	return (q);
}

/* a function to insert a node with data value n in a sorted list pointed to by p*/
struct node *sinsert(struct node *p, int n)
{
	struct node *curr, *prev;
	curr = p;
	prev = NULL;
	while (curr->data < n)
	{
		prev = curr;
		curr = curr->link;
	}
	/* the element is to be inserted at the start of the list because it is less than the data value of the first node*/
	if (prev == NULL) 
	{
		curr = (struct node *) malloc(sizeof(struct node));
		if (curr == NULL)
		{
			printf("error cannot allocate\n");
			exit(0);
		}
		curr->data = n;
		curr->link = p;
		p = curr;
	}
	else
	{
		curr = (struct node *) malloc(sizeof(struct node));
		if (curr == NULL)
		{
			printf("error cannot allocate\n");
			exit(0);
		}
		curr->data = n;
		curr->link = prev->link;
		prev->link = curr;
	}
	return(p);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int x;
	struct node *start = NULL;
	printf("Enter the nodes to be created \n");
	scanf_s("%d", &n);
	while (n-- > 0)
	{
		printf("Enter the data values to be placed in a node\n");
		scanf_s("%d", &x);
		start = insert(start, x);
	}
	printf("The created list is\n");
	printlist(start);
	start = sortlist(start);
	printf("The sorted list is\n");
	printlist(start);
	printf("Enter the value to be inserted\n");
	scanf_s("%d", &n);
	start = sinsert(start, n);
	printf("The list after insertion is\n");
	printlist(start);

	n = nodecount(start);
	printf("The number of nodes in a list are: %d\n", n);

	cin.get();
	cin.ignore();
	return 0;
}

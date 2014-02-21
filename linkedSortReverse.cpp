// linkedSortReverse.cpp : Defines the entry point for the console application.
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
	return(p);
}

/* a function to compute the length of a linked list */
int length(struct node *p)
{
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->link;
	}
	return (count);
}

/* a function which inserts a newly created node after the specified node */
struct node * newinsert(struct node *p, int node_no, int value)
{
	struct node *temp, *temp1;
	int i;
	if (node_no <= 0 || node_no > length(p))
	{
		printf("Error! the specified node does not exist\n");
		exit(0);
	}
	if (node_no == 0)
	{
		temp = (struct node *)malloc(sizeof (struct node));
		if (temp == NULL)
		{
			printf(" Cannot allocate \n");
			exit(0);
		}
		temp->data = value;
		temp->link = p;
		p = temp;
	}
	else
	{
		temp = p;
		i = 1;
		while (i < node_no)
		{
			i = i + 1;
			temp = temp->link;
		}
		temp1 = (struct node *)malloc(sizeof(struct node));
		if (temp1 == NULL)
		{
			printf("Cannot allocate \n");
			exit(0);
		}
		temp1->data = value;
		temp1->link = temp->link;
		temp->link = temp1;
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

void reversePrintlist(struct node *p)
{
	if (p == NULL)
	{
		return;
	}
	reversePrintlist(p->link);
	printf("%d\t", p->data);
}


/* a function to sort reverse list */
struct node *reverse(struct node *p)
{
	struct node *prev, *curr;
	prev = NULL;
	curr = p;
	while (curr != NULL)
	{
		p = p->link;
		curr->link = prev;
		prev = curr;
		curr = p;
	}
	return(prev);
}

struct node *reverseRecursive(struct node *p)
{
	if (p->link == NULL) {
		return p;
	}
	else {
		struct node *t = reverse(p->link);
		p->link->link = p;
		p->link = NULL;
		return(t);
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

/* a function to delete the specified node*/
struct node *delet(struct node *p, int node_no)
{

	struct node *prev, *curr;
	int i;

	if (p == NULL)
	{
		printf("There is no node to be deleted \n");
	}
	else
	{
		if (node_no > length(p))
		{
			printf("Error\n");
		}
		else
		{
			prev = NULL;
			curr = p;
			i = 1;
			while (i < node_no)
			{
				prev = curr;
				curr = curr->link;
				i = i + 1;
			}
			if (prev == NULL)
			{
				p = curr->link;
				free(curr);
			}
			else
			{
				prev->link = curr->link;
				free(curr);
			}
		}
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
		printf("Enter the data values to be placed in a	node\n");
		scanf_s("%d", &x);
		start = insert(start, x);
	}
	printf("The created list is\n");
	printlist(start);
	start = sortlist(start);
	printf("The sorted list is\n");
	printlist(start);
	//start = reverse(start);
	start = reverseRecursive(start);
	printf("The reversed list is\n");
	printlist(start);

	printf(" The list before deletion id\n");
	printlist(start);
	printf("% \n Enter the node no to delete\n");
	scanf_s(" %d", &n);
	start = delet(start, n);
	printf(" The list after deletion is\n");
	printlist(start);

	printf(" \n Enter the node no after which the insertion is to be done\n"); 
	scanf_s(" %d", &n);
	printf("Enter the value of the node\n");
	scanf_s("%d", &x);
	start = newinsert(start, n, x);
	printf("The list after insertion is \n");
	printlist(start);

	cin.get();
	cin.ignore();
	return 0;
}

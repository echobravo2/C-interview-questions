// linkedMerge2lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct node *merge(struct node *, struct node *);

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

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int x;
	struct node *start1 = NULL;
	struct node *start2 = NULL;
	struct node *start3 = NULL;
	/* The following code creates and sorts the first list */
	printf("Enter the number of nodes in the first list \n");
	scanf_s("%d", &n);
	while (n-- > 0)
	{
		printf("Enter the data value to be placed in a node\n");
		scanf_s("%d", &x);
		start1 = insert(start1, x);
	}
	printf("The first list is\n");
	printlist(start1);
	start1 = sortlist(start1);
	printf("The sorted list1 is\n");
	printlist(start1);
	/* the following creates and sorts the second list*/
	printf("Enter the number of nodes in the second list \n");
	scanf_s("%d", &n);
	while (n-- > 0)
	{
		printf("Enter the data value to be placed in a node\n");
		scanf_s("%d", &x);
		start2 = insert(start2, x);
	}
	printf("The second list is\n");
	printlist(start2);
	start2 = sortlist(start2);
	printf("The sorted list2 is\n");
	printlist(start2);
	start3 = merge(start1, start2);
	printf("The merged list is\n");
	printlist(start3);

	cin.get();
	cin.ignore();
	return 0;
}


/* A function to merge two sorted lists */
struct node *merge(struct node *p, struct node *q)
{
	struct node *r = NULL, *temp;
	if (p == NULL)
		r = q;
	else
	if (q == NULL)
		r = p;
	else
	{
		if (p->data < q->data)
		{
			r = p;
			temp = p;
			p = p->link;
			temp->link = NULL;
		}
		else
		{
			r = q;
			temp = q;
			q = q->link;
			temp->link = NULL;
		}
		while ((p != NULL) && (q != NULL))
		{
			if (p->data < q->data)
			{
				temp->link = p;
				p = p->link;
				temp = temp->link;
				temp->link = NULL;
			}
			else
			{
				temp->link = q;
				q = q->link;
				temp = temp->link;
				temp->link = NULL;
			}
		}
		if (p != NULL)
			temp->link = p;
		if (q != NULL)
			temp->link = q;
	}
	return(r);
}

// splitLinked2TwoLists.cpp : Defines the entry point for the console application.
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
void split(struct node *p, struct node **q, int n)
{
	struct node *temp;
	int i = 1;
	temp = p;

	/*iterate to the middle of the whole list*/
	while (i < n)

	{
		temp = temp->link;
		i++;  
	}
	/*will make q pointer point to that middle node*/
	*q = temp->link;
	
	/*branch the whole list from the middle by setting the middle node pointer to point its head p*/
	temp->link = p;
	/*for the second list, temp going to be a head*/
	temp = *q;
	/*iterate to the end of the second list till we reach the head p it is pointing to*/
	while (temp->link != p)
		temp = temp->link;

	/*disconnect the loop from the end of whole list by setting the last pointer to point the head of q*/
	temp->link = *q;
}

struct node *insert(struct node *p, int n)
{
	struct node *temp;
	/* if the existing list is empty then insert a new node as the
	starting node */
	if (p == NULL)
	{
		p = (struct node *)malloc(sizeof(struct node)); /* creates new node
														data value passes
														as parameter */

		if (p == NULL)
		{
			printf("Error\n");
			exit(0);
		}
		p->data = n;
		p->link = p; /* makes the pointer point to itself because it is
					 a circular list*/
	}
	else
	{
		temp = p;
		/* traverses the existing list to get the pointer to the last node of
		it */
		while (temp->link != p)
			temp = temp->link;
		temp->link = (struct node *)malloc(sizeof(struct node)); /*
																 creates new node using
																 data value passes as
																 parameter and puts its
																 address in the link field
																 of last node of the
																 existing list*/
		if (temp->link == NULL)
		{
			printf("Error\n");
			exit(0);
		}
		temp = temp->link;
		temp->data = n;
		temp->link = p;
	}
	return (p);
}

void printlist(struct node *p)
{
	struct node *temp;
	temp = p;
	printf("The data values in the list are\n");
	if (p != NULL)
	do
	{
		printf("%d\t", temp->data);
		temp = temp->link;
	} while (temp != p);
	else
		printf("The list is empty\n");
}



int _tmain(int argc, _TCHAR* argv[])
{
	int n, num;
	int x;
	struct node *start = NULL;
	struct node *start1 = NULL;
	printf("Enter the value of n \n");
	scanf_s("%d", &n);
	num = n;
	n *= 2;
	/* this will create a circular list with 2n nodes*/
	while (n-- > 0)
	{
		printf("Enter the data values to be placed in a node\n");
		scanf_s("%d", &x);
		start = insert(start, x);
	}
	printf("The created list is\n");
	printlist(start);
	split(start, &start1, num);
	printf("The first list is:\n");
	printlist(start);
	printf("The second list is:\n");
	printlist(start1);

	cin.get();
	cin.ignore();
	return 0;
}

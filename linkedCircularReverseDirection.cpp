// linkedCircularReverseDirection.cpp : Defines the entry point for the console application.
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
/* A function to reverse a singly linked circular list */
struct node *reverselist(struct node *p)
{
	struct node *temp;
	struct node *prev = NULL;
	struct node *curr;
	if (p != NULL)
	{
		curr = p;
		temp = curr;
		while (curr->link != p)
		{
			curr = curr->link;
			temp->link = prev;
			prev = temp;
			temp = curr;
		}
		temp->link = prev;
		p->link = temp;
		p = temp;
	}
	return(p);
}

struct node *reverseRecursive(struct node *p)
{
	if (p->link == NULL) {
		return p;
	}
	else {
		struct node *t = reverseRecursive(p->link);
		p->link->link = p;
		p->link = NULL;
		return(t);
	}
}

//struct node *reverseRecursive(struct node *p)
//{
//	struct node *tmpnode = NULL;
//	struct node *headnode = NULL;
//	if (p->link)
//	{
//		reverseRecursive(p->link);
//		tmpnode->link = p;
//		tmpnode = tmpnode->link;
//	}
//	else
//	{
//		headnode = p;
//		tmpnode = headnode;
//	}
//	tmpnode->link = NULL;
//	return headnode;
//
//}


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
	{
		do
		{
			printf("%d\t", temp->data);
			temp = temp->link;
		} while (temp != p);
	}
	else
		printf("The list is empty\n");
}


int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	int x;
	struct node *start = NULL;
	struct node *start1 = NULL;
	/* this will create at circular list */
	printf("Enter the number of nodes in the list \n");
	scanf_s("%d", &n);
	while (n-- > 0)
	{
		printf("Enter the data value to be placed in a node\n");
		scanf_s("%d", &x);
		start = insert(start, x);
	}
	printf("The list is\n");
	printlist(start);
	//start1 = reverselist(start);
	start1 = reverseRecursive(start);
	printf("The reversed list is:\n");
	printlist(start1);

	cin.get();
	cin.ignore();
	return 0;
}

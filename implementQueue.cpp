// queueLinked.cpp : Defines the entry point for the console application.
//

// circularQueueArray.cpp : Defines the entry point for the console application.
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

void ql_insert(struct node **front, struct node **rear, int value)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	/* creates new node
	using data value
	passed as parameter */
	if (temp == NULL)
	{
		printf("No Memory available Error\n");
		exit(0);
	}
	temp->data = value;
	temp->link = NULL;
	if (*rear == NULL)
	{
		*rear = temp;
		*front = *rear;
	}
	else
	{
		(*rear)->link = temp;
		*rear = temp;
	}
}

void ql_delete(struct node **front, struct node **rear, int *value)
{
	struct node *temp;
	if ((*front == *rear) && (*rear == NULL))
	{
		printf(" The queue is empty cannot delete Error\n");
		exit(0);
	}
	*value = (*front)->data;
	temp = *front;
	*front = (*front)->link;
	if (*rear == temp)
		*rear = (*rear)->link;
	free(temp);
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct node *front = NULL, *rear = NULL;
	int n, value;
	do
	{
		do
		{
			printf("Enter the element to be inserted\n");
			scanf_s("%d", &value);
			ql_insert(&front, &rear, value);
			printf("Enter 1 to continue\n");
			scanf_s("%d", &n);
		} while (n == 1);

		printf("Enter 1 to delete an element\n");
		scanf_s("%d", &n);
		while (n == 1)
		{
			ql_delete(&front, &rear, &value);
			printf("The value deleted is %d\n", value);
			printf("Enter 1 to delete an element\n");
			scanf_s("%d", &n);
		}
		printf("Enter 1 to continue\n");
		scanf_s("%d", &n);
	} while (n == 1);

	cin.get();
	cin.ignore();
	return 0;
}

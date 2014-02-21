// reverseSingleLinkedListRec.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>  /*for malloc()*/
#include <conio.h>    /*for getch() ( not mandatory to use) */

using namespace std;

typedef struct  _NODE
{
	int data;
	struct _NODE *next;
}NODE;

NODE *create_list(NODE *start);
NODE *add_at_beg(NODE *start, int data);
NODE *add_at_end(NODE *start, int data);
void   display(NODE *start);
NODE *RevList(NODE *start);

int _tmain(int argc, _TCHAR* argv[])
{
	NODE *start = NULL;
	/*creating the list */
	start = create_list(start);

	/*display the list */
	printf("\nlist elements are :");
	display(start);
	/*reverse the list */
	start = RevList(start);
	/*displaying the list elements in reverse order*/
	printf("\nlinked list elements (reverse order) :");
	display(start);
	//getch();

	cin.get();
	cin.ignore();
	return 0;
}

/* reversing the list*/
NODE *RevList(NODE *ptr)
{
	NODE *temp;
	if (ptr->next == NULL)
		return ptr;
	temp = RevList(ptr->next);
	ptr->next->next = ptr;
	ptr->next = NULL;
	return temp;
}

NODE *create_list(NODE *start)
{
	int i = 1, n, data;
	printf("Enter the number of nodes : ");
	scanf_s("%d", &n);
	start = NULL;
	if (n == 0)
		return start;

	printf("[node - %d]   Enter the element : ", i);
	scanf_s("%d", &data);
	start = add_at_beg(start, data);

	for (i = 2; i <= n; i++)
	{
		printf("[node - %d]   Enter the element : ", i);
		scanf_s("%d", &data);
		start = add_at_end(start, data);
	}
	return start;
}

NODE *add_at_beg(NODE *start, int data)
{
	NODE *tmp;
	tmp = (NODE *)malloc(sizeof(NODE));
	tmp->data = data;
	tmp->next = start;
	start = tmp;
	return start;
}

NODE *add_at_end(NODE *start, int data)
{
	NODE *p, *tmp;
	tmp = (NODE *)malloc(sizeof(NODE));
	tmp->data = data;
	p = start;
	while (p->next != NULL)
		p = p->next;
	p->next = tmp;
	tmp->next = NULL;
	return start;
}

void display(NODE *ptr)
{
	if (NULL == ptr)
		return;
	printf("-> %d ", ptr->data);
	display(ptr->next);
}

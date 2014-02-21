// hashing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define SIZE 50
#define MAX 10
typedef struct node
{
	char symbol[MAX];
	int value;
	struct node *next;
} entry;
typedef entry *entry_ptr;

int hash_value(char * name)
{
	int sum = 0;
	while (*name != '\0')
	{
		sum += *name;
		name++;
	}
	return(sum % SIZE);
}

void initialize(entry_ptr table[])
{
	int i = 0;
	for (i = 0; i<SIZE; i++)
		table[i] = NULL;
}

void insert(entry_ptr table[], char *name, int val)
{
	int h, flag = 1;
	entry_ptr temp;
	h = hash_value(name);
	temp = table[h];
	while (temp != NULL && flag)
	{
		if (strcmp(temp->symbol, name) == 0)
		{
			printf("The symbol %s is already present in the	table\n",name);
				flag = 0;;
		}
		temp = temp->next;
	}
	if (flag)
	{
		temp = (entry_ptr)malloc(sizeof(entry));
		if (temp == NULL)
		{
			printf("ERRRR .......\n");
			exit(0);
		}
		strcpy_s(temp->symbol, name);
		temp->value = val;
		temp->next = table[h];
		table[h] = temp;
	}
}

void retrieve(entry_ptr table[], char *name)
{
	int h, flag = 1;
	entry_ptr temp;
	h = hash_value(name);
	temp = table[h];
	while (temp != NULL && flag)
	{
		if (strcmp(temp->symbol, name) == 0)
		{
			printf("The symbol %s is present in the table and having value =%d\n",	name, temp->value);
			flag = 0;
		}
		temp = temp->next;
	}
	if (flag == 1)
		printf("The symbol %s is not present in the table\n",name);
}

int _tmain(int argc, _TCHAR* argv[])
{
	entry_ptr table[SIZE];
	char name[MAX];
	int value, n;
	initialize(table);
	do
	{
		do
		{
			printf("Enter the symbol and value pair to be inserted\n");
			scanf_s("%s %d", name, &value);
			insert(table, name, value);
			printf("Enter 1 to continue\n");
			scanf_s("%d", &n);
		} while (n == 1);
		do
		{
			printf("Enter the symbol whose value is to be retrieved\n");
			scanf_s("%s", name);
			retrieve(table, name);
			printf("Enter 1 to continue\n");
			scanf_s("%d", &n);
		} while (n == 1);
		printf("Eneter 1 to continue\n");
		scanf_s("%d", &n);
	} while (n == 1);


	cin.get();
	cin.ignore();
	return 0;
}

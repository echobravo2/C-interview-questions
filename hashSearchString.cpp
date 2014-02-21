// hashSearchString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAXLEN 80
#define HASHSIZE 23             // some prime val.
#define SHIFTBY 3               // each group size in hashing.
#define ERR     -1               // error

typedef struct node node;
typedef char *type;

struct node {
	int val;
	char *key;
	node *next;
};

typedef node *hashtable[HASHSIZE];

int hGetIndex(char *key) {
	/*
	* returns index into hashtable applying hash function.
	* uses shift-folding followed by mod function for hashing.
	*/
	int i, n, finaln = 0;
	char *keyptr;

	for (keyptr = key; *keyptr; finaln += n)
	for (i = 0, n = 0; i<SHIFTBY && *keyptr; ++i, ++keyptr)
		n = n * 10 + *keyptr;
	finaln %= HASHSIZE;

	return finaln;
}

void hInsert(hashtable h, char *key, int val) {
	/*
	* insert s in hashtable h.
	* use shift-folding followed by mod function for hashing.
	* does NOT check for duplicate insertion.
	*/
	node *ptr = (node *)malloc(sizeof(node));
	int index = hGetIndex(key);

	ptr->key = _strdup(key);
	ptr->val = val;
	ptr->next = h[index];

	h[index] = ptr;
	printf("h[%d] = %s.\n", index, key);
}

int hGetVal(hashtable h, char *key) {
	/*
	* returns val corresponding to key if present in h else −1.
	*/
	node *ptr;

	for (ptr = h[hGetIndex(key)]; ptr && strcmp(ptr->key, key); ptr = ptr->next)
		;
	if (ptr)
		return ptr->val;
	return ERR;
}

void printHash(hashtable h) {
	/*
	* print the hashtable rowwise.
	*/
	int i;
	node *ptr;

	for (i = 0; i<HASHSIZE; ++i) {
		printf("%d: ", i);
		for (ptr = h[i]; ptr; ptr = ptr->next)
			printf("%s=%d ", ptr->key, ptr->val);
		printf("\n");
	}
}


using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	char s[MAXLEN];
	int i = 0;
	char *in = "asd";
	hashtable h = (in);

	printf("Enter the string to be hashed: ");
	gets(s);

	while (*s) {
		hInsert(h, s, i++);
		printf("Enter the string to be hashed(enter to end): ");
		gets(s);
	}
	printf("Enter the string to be searched: ");
	gets(s);

	while (*s) {
		printf("%s was inserted at number %d.\n", s, hGetVal(h, s));
		printf("\nEnter the string to be searched(enter to end): ");
		gets(s);
	}
	//printHash(h);

	getchar();
//	cin.get();
//	cin.ignore();
	return 0;
}

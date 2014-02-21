// binarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*A complete C program to create a binary search tree follows :*/
struct tnode
{
	int data;
	struct tnode *lchild, *rchild;
};

struct tnode *find_max(struct tnode *p)
{
	if (p == NULL)
	{
		return NULL;
	}
	if (p->rchild == NULL)
	{
		return p;
	}
	return find_max(p->rchild);
}

struct tnode *find_min(struct tnode *p)
{
	if (p == NULL)
	{
		return NULL;
	}
	if (p->lchild == NULL)
	{
		return p;
	}
	return find_min(p->lchild);
}

struct tnode *getptr(struct tnode *p, int key, struct tnode **y)
{
	struct tnode *temp;
	if (p == NULL)
		return(NULL);
	temp = p;
	*y = NULL;
	while (temp != NULL)
	{
		if (temp->data == key)
			return(temp);
		else
		{
			*y = temp; /*store this pointer as root */
			if (temp->data > key)
				temp = temp->lchild;
			else
				temp = temp->rchild;
		}
	}
	return(NULL);
}

/* A function to delete the node whose data value is given */
struct tnode *delete_node(struct tnode *p, int val)
{
	struct tnode *x, *y, *temp;
	x = getptr(p, val, &y);
	if (x == NULL)
	{
		printf("The node does not exists\n");
		return(p);
	}
	else
	{
		/* this code is for deleting root node*/
		if (x == p)
		{
			temp = x->lchild;
			y = x->rchild;
			p = temp;
			while (temp->rchild != NULL)
				temp = temp->rchild;
			temp->rchild = y;
			free(x);
			return(p);
		}
		/* this code is for deleting node having both children */
		if (x->lchild != NULL && x->rchild != NULL)
		{

			if (y->lchild == x)
			{
				temp = x->lchild;
				y->lchild = x->lchild;
				while (temp->rchild != NULL)
					temp = temp->rchild;
				temp->rchild = x->rchild;
				x->lchild = NULL;
				x->rchild = NULL;
			}
			else
			{
				temp = x->rchild;
				y->rchild = x->rchild;
				while (temp->lchild != NULL)
					temp = temp->lchild;
				temp->lchild = x->lchild;
				x->lchild = NULL;
				x->rchild = NULL;
			}

			free(x);
			return(p);
		}
		/* this code is for deleting a node with on child*/
		if (x->lchild == NULL && x->rchild != NULL)
		{
			if (y->lchild == x)
				y->lchild = x->rchild;
			else
				y->rchild = x->rchild;
			
			x->rchild = NULL;
			free(x);
			return(p);
		}
		if (x->lchild != NULL && x->rchild == NULL)
		{
			if (y->lchild == x)
				y->lchild = x->lchild;
			else
				y->rchild = x->lchild;
			x->lchild = NULL;
			free(x);
			return(p);
		}
		/* this code is for deleting a node with no child*/
		if (x->lchild == NULL && x->rchild == NULL)
		{
			if (y->lchild == x)
				y->lchild = NULL;
			else
				y->rchild = NULL;
			free(x);
			return(p);
		}
	}
}

struct tnode *delete_node_recursive(struct tnode *p, int val)
{
	if (p == NULL)
	{
		return NULL;
	}
	if (p->data == val)
	{
		// the first two cases handle having zero or one child node
		if (p->lchild == NULL)
		{
			struct tnode *p_right_subtree = p->rchild;
			delete p;
			// this might return NULL if there are zero child nodes,
			// but that is what we want anyway
			return p_right_subtree;
		}
		if (p->rchild == NULL)
		{
			struct tnode *p_left_subtree = p->lchild;
			delete p;
			// this will always return a valid node, since we know
			// is not NULL from the previous if statement
			return p_left_subtree;
		}
		struct tnode *p_max_node = find_max(p->lchild);
		p_max_node->lchild = p->lchild;  //or --->     p_max_node->p_left =	remove_max_node(p_tree->p_left, p_max_node);
		p_max_node->rchild = p->rchild;
		delete p;
		return p_max_node;
	}
	else if (val < p->data)
	{
		p->lchild = delete_node_recursive(p->lchild, val);
	}
	else
	{
		p->rchild = delete_node_recursive(p->rchild, val);
	}
	return p;
}

struct tnode * insertRecursive(struct tnode *p_tree, int key)
{
	// base case--we have reached an empty tree and need to insert our new
	// node here
	if (p_tree == NULL)
	{
		struct tnode *p_new_tree = new struct tnode;
		p_new_tree->lchild = NULL;
		p_new_tree->rchild = NULL;
		p_new_tree->data = key;
		return p_new_tree;
	}
	// decide whether to insert into the left subtree of the right subtree
	// depending on the value of the node
	if (key < p_tree->data)
	{
		// build a new tree from p_tree->left, but add the key
		// replace the existing p_tree->left pointer with a pointer
		// to the new tree. We need to set the p_tree->p_left pointer
		// in case p_tree->left is NULL. (If it is not NULL,
		// p_tree->p_left won't actually change but it doesn’t hurt to
		// set it.)
		p_tree->lchild = insertRecursive(p_tree->lchild, key);
	}
	else
	{
		// Insertion into the right is exactly symmetric to insertion
		// into the left
		p_tree->rchild = insertRecursive(p_tree->rchild, key);
	}
	return p_tree;
}
struct tnode *insert(struct tnode *p, int val)
{
	struct tnode *temp1, *temp2;
	if (p == NULL)
	{
		p = (struct tnode *) malloc(sizeof(struct tnode)); /* insert the new node as root node*/
		if (p == NULL)
		{
			printf("Cannot allocate\n");
			exit(0);
		}
		p->data = val;
		p->lchild = p->rchild = NULL;
	}
	else
	{
		temp1 = p;
		temp2 = temp1;
		/* traverse the tree to get a pointer to that node whose child will be the newly created node*/
		while (temp1 != NULL)
		{
			temp2 = temp1;
			if (temp1->data > val)
				temp1 = temp1->lchild;
			else
				temp1 = temp1->rchild;
		}
		if (temp2->data > val)
		{
			temp2->lchild = (struct tnode*)malloc(sizeof(struct tnode));/*inserts the newly created node as left child*/
			temp2 = temp2->lchild;
			if (temp2 == NULL)
			{
				printf("Cannot allocate\n");
				exit(0);
			}
			temp2->data = val;
			temp2->lchild = temp2->rchild = NULL;
		}
		else
		{	/*inserts the newly created node as right child*/
			temp2->rchild = (struct tnode*)malloc(sizeof(struct tnode)); 
				temp2 = temp2->rchild;
			if (temp2 == NULL)
			{
				printf("Cannot allocate\n");
				exit(0);
			}
			temp2->data = val;
			temp2->lchild = temp2->rchild = NULL;
		}
	}
	return(p);
}

/*A non-recursive/iterative function for traversing a binary tree in inorder */
void inorder(struct tnode *p)
{
	struct tnode *stack[100];
	int top;
	top = -1;
	if (p != NULL)
	{
		top++;
		stack[top] = p;
		p = p->lchild;
		while (top >= 0)
		{
			while (p != NULL)/* push the left child onto stack*/
			{
				top++;
				stack[top] = p;
				p = p->lchild;
			}
			p = stack[top];
			top-- ;
			printf("%d\t", p->data);
			p = p->rchild;
			if (p != NULL) /* push right child*/
			{
				top++;
				stack[top] = p;
				p = p->lchild;
			}
		}
	}
}


/* a function to binary tree in inorder */
void inorderRecursive(struct tnode *p)
{
	if (p != NULL)
	{
		inorderRecursive(p->lchild);
		printf("%d\t", p->data);
		inorderRecursive(p->rchild);
	}
}

/*A function for preorder traversal of a binary tree */

void preorderRecursive(struct tnode *p)
{
	if (p != NULL)
	{
		printf("%d\t", p->data);
		preorderRecursive(p->lchild);
		preorderRecursive(p->rchild);
	}
}
/*A function for postorder traversal of a binary tree */

void postorderRecursive(struct tnode *p)
{
	if (p != NULL)
	{
		postorderRecursive(p->lchild);
		postorderRecursive(p->rchild);
		printf("%d\t", p->data);
	}
}

int countRecursive(struct tnode *p)
{
	if (p == NULL)
		return(0);
	else
	if (p->lchild == NULL && p->rchild == NULL)
		return(1);
	else
		return(1 + (countRecursive(p->lchild) + countRecursive(p->rchild)));

}

/*recursively swaps the left and right subtrees, starting from the root*/
struct tnode *swaptree(struct tnode *p)
{
	struct tnode *temp1 = NULL, *temp2 = NULL;
	if (p != NULL)
	{
		temp1 = swaptree(p->lchild);
		temp2 = swaptree(p->rchild);
		p->rchild = temp1;
		p->lchild = temp2;
	}
	return(p);
}

/* recursive function to serch for a given data value in a binary search tree*/
struct tnode *searchRecursive(struct tnode *p, int key)
{
	if (p == NULL) 
		return NULL;
	else if (p->data == key) 
		return(p);
	else if (p->data > key) 
		searchRecursive(p->lchild, key);
	else 
		searchRecursive(p->rchild, key);
}

/* A function to serch for a given data value in a binary search tree*/
struct tnode *search(struct tnode *p, int key)
{
	struct tnode *temp;
	temp = p;
	while (temp != NULL)
	{
		if (temp->data == key)
			return(temp);
		else
		if (temp->data > key)
			temp = temp->lchild;
		else
			temp = temp->rchild;
	}
	return(NULL);
}

void destroy_tree(struct tnode *p)
{
	if (p != NULL)
	{
		destroy_tree(p->lchild);
		destroy_tree(p->rchild);
			delete p;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct tnode *root = NULL, *temp = NULL;
	int n, x;
	printf("Enter the number of nodes\n");
	scanf_s("%d", &n);
	while (n-- > 0)
	{
		printf("\nEnter the data value\n");
		scanf_s("%d", &x);
		//root = insert(root, x);
		root = insertRecursive(root, x);
	}
	printf("\nInorder Recursive\n");
	inorderRecursive(root);

	printf("\nInorder Regular\n");
	inorder(root);

	printf("\nPreorder\n");
	preorderRecursive(root);
	printf("\nPostorder\n");
	postorderRecursive(root);

	printf("\nThe number of nodes in tree are :%d\n", countRecursive(root));

	printf("The tree after swapping is :\n");
	root = swaptree(root);
	inorder(root);
	printf("\nThe original tree is \n");
	root = swaptree(root);
	inorder(root);

	printf("\n Enter the value of the node to be searched\n");
	scanf_s("%d", &n);
	//temp = search(root, n);
	temp = searchRecursive(root, n);
	if (temp != NULL)
		printf("The data value is present in the tree \n");
	else
		printf("The data value is not present in the tree \n");

	printf("\n Enter the value of the node to be deleted\n");
	scanf_s("%d", &n);
	//root = delete_node(root, n);
	root = delete_node_recursive(root, n);
	printf("The tree after deletion is \n");
	inorder(root);

	destroy_tree(root);

	cin.get();
	cin.ignore();
	return 0;
}

// binaryTree2DoublyLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



/************ data types *****************/ 
struct node { 
	int data; 
	struct node *left, *right; 
}; 

struct LL{ 
	int data; 
	struct LL *prev, *next; 
};


/************** prototypes ***************/ 
int isNull(struct node *); 
struct node * place_data(int, struct node *); 
void convert(struct node *); 
void extract(struct node *); 
void connect(int, struct LL *); 
void showlist(struct LL *);


/********** function places data at appropriate place - just for tree construction ***********/ 
struct node * place_data(int data_rec, struct node *root){

	if (isNull(root)){ 
		root = (struct node *)malloc(sizeof(struct node)); 
		root->data = data_rec; 
		root->left = NULL; 
		root->right = NULL; 
		return root; 
	} 
	/**** end of root allocation ****/ 
	else{
		if (root->data > data_rec){ 
			//send left 
			root->left = place_data(data_rec,root->left); 
		} else if(root->data < data_rec){
			//send right 
			root->right = place_data(data_rec,root->right); 
		} else { 
			printf("\ndata cannot be equal to the previous data/key\nprogram is exiting.."); 
			exit(1); 
		}
		
		return root;
		} /**** end of else and place option ****/
}


/******** simply helper function *********/ 
int isNull(struct node *ptr){ 
	if (ptr == NULL) 
		return 1; 
	return 0; 
}


/**** globals for extract function ****/ 
int flip = 0; 
struct LL *mainNode; 
/*********/


/********** Extracts data and places it in the dll ***********/ 
void extract(struct node *temp) {
int data = temp->data; 
struct LL * temp1; 
	if (flip == 0){ 
		/******* <====== indicates that the DLL has yet to be created ***/
		temp1 = (struct LL *)malloc(sizeof(struct LL)); 
		temp1->data = data; 
		temp1->next = NULL; 
		temp1->prev = NULL; 
		mainNode = temp1; 
		flip = 1; 
		/***** flip it ******/
		}
		else if (flip = 1){ 
			/****** <======= indicates that the root node of dll has already been created *******/ 
			connect(data, mainNode);/***** so simply connect it now ********/ 
		}
} //void extract ends


	/*********** called from main - subdivieds the work with inorder traversal ************/ 
void convert(struct node *root){ 
	if (root){ 
		convert(root->left); 
		/*** <=== inorder part *****/ 
		extract(root); 
		convert(root->right); 
		/*** <=== inorder part *****/ 
	} else 
		return; 
}//void convert ends


	/************ simply connects two nodes of a DLL *************/ 
void connect(int data, struct LL * temp){
			struct LL * temp1 = (struct LL *)malloc(sizeof(struct LL)); 
			struct LL * behind; 
			behind = temp;
			while (temp != NULL)
			{ 
				behind = temp; 
				temp = temp->next; 
			} 
			temp1->data = data; 
			temp1->next = NULL; 
			temp1->prev = behind; 
			behind->next = temp1;
		}//void connect ends


/*************** function to show list contents ****************/ 
void showlist(struct LL * root){
			struct LL * last; 
			printf("\nShowing foreward : ");
			
			last = root;
			while (root != NULL){
				printf("%d\t", root->data); 
				last = root; 
				root = root->next; 
			}
			printf("\nShowing reverse : "); 
			
			while (last != NULL){ 
				printf("%d\t", last->data); 
				last = last->prev; 
			}
}


/************************** MAIN ***************************/ 
int _tmain(int argc, _TCHAR* argv[])
{
	// Let us construct the tree given in the above diagram 
	int arr[8] = { 20, 8, 4, 12, 10, 14, 22, 25 };
	int i;

	struct node *root = NULL;
	/************* tree placemnt **************/
	for (i = 0; i<8; i++){
		//printf("%d\n",i); 
		root = place_data(arr[i], root);
	}
	/******************************************/
	convert(root);
	printf("\nshowing list : ");
	showlist(mainNode);

	getchar();
	return 0;
}


//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 1
//Due 2/14/16

#include "headers.h"
#include "treenode.h"

//create and insert node
treeNode* insertNode(treeNode *node, char* word){
	
	//if node is null then create a new node
	if(node == NULL){
		//make node and allocate memory
		treeNode *new_node;
		new_node = (treeNode *)malloc(sizeof(treeNode));

		//check if malloc fails
		if(new_node == NULL){
			printf("Malloc error.");
			exit(1);
		}

		//set the fields
		strcpy(new_node->word, word);
		new_node->leftChild = NULL;
		new_node->rightChild = NULL;
		
		//return new_node pointer
		return new_node;
		
		
	//tree not empty
	}else{
		//if data is less than for string compare
		if(strcmp((node->word), word) < 0){
			node->rightChild = insertNode(node->rightChild, word);
			
		}else{
			//must be greater than
			node->leftChild = insertNode(node->leftChild, word);	
		}
	}
}
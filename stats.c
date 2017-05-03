//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 1
//Due 2/14/16

#include "headers.h"
#include "treenode.h"

int treeHeight(treeNode *node){

	//if node is null, or the children are both null, then return 0 for counting
	//purposes
	if(node == NULL || ((node->leftChild == NULL) && (node->rightChild == NULL))){

		return 0;

	}else{
		//declare height for left and right to return the max later
		int leftHeight = treeHeight(node->leftChild);
		int rightHeight = treeHeight(node->rightChild);
		
		//returns max of left or right sub tree
		if(leftHeight > rightHeight){
			return leftHeight + 1;
		}else{
			return rightHeight + 1;
		}
	}	
	
}


int countLeaves(treeNode *node){
	
	//if node is null then return 0
	if(node == NULL){
		return 0;
	}
	
	//is left and right are null, then must be leaf
	if(node->leftChild == NULL && node->rightChild == NULL){
		return 1;
	}else{
		
		//if not null then return the sum of left and right nodes
		return countLeaves(node->leftChild) + countLeaves(node->rightChild);
	}
}


int countNodes(treeNode *node){
	
	//if null, then return 0, does not exist (DNE)
	if(node == NULL){
		return 0;
	}
	
	//return the count plus 1 for the root of the tree
	return 1 + countNodes(node->leftChild) + countNodes(node->rightChild);
}
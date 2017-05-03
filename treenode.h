//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 1
//Due 2/14/16

#include "headers.h"

typedef struct treeNode{
	struct treeNode *leftChild;
	struct treeNode *rightChild;
	char word[CHAR_MAX_LEN + 1];
}treeNode;
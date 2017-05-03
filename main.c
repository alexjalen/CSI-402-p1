//Alex Pospesel
//ID: 001146589
//NetID: ap212246
//Email: apospesel@albany.edu
//CSI 402
//Program 1
//Due 2/14/16

#include "headers.h"
#include "treenode.h"
#include "prototypes.h"

//command line arguments
int main (int argc, char *argv[]){


	//variables
	treeNode *rootPtr = NULL;
	FILE *inFile;
	FILE *outFile;
	char data[CHAR_MAX_LEN + 1];
	int file_length;


	//if not 3 arguments the exit(0)
	if(argc != 3){
		printf("Incorrect number of arguments.\n");
		exit(1);
	}


	//check file inputs for validity
	if((inFile = fopen(argv[1], "r")) == NULL){
		//if fails to open file for reading
		printf("Could not open file.\n");
		exit(1);
	}
	
	//test if file is empty
	fseek(inFile, 0, SEEK_END);
	file_length = ftell(inFile);
	if(file_length == 0){
		printf("File empty.\n");
		exit(0);
	}else{
		//file is not empty
		//set fseek to begginning
		fseek(inFile, 0, SEEK_SET);
	}


	//check output file for validity and writing
	if((outFile = fopen(argv[2], "w")) == NULL){
		//create the file for writing
		outFile = fopen(argv[2], "w");
	}

	
	
	/*if((fseek(inFile, 0, SEEK_END)) == (fseek(inFile, 0, SEEK_SET))){
		//file must be empty
		printf("File empty.\n");
		exit(0);
	}*/

	//read file line by line
	while(fscanf(inFile, "%s", data) != -1){		
		
		//insert data into tree
		rootPtr = insertNode(rootPtr, data);
		
	}

	//do data on tree
	//and print to file
	
	fprintf(outFile, "No. of strings in the input file \t= %d\n", countNodes(rootPtr));
	
	fprintf(outFile, "Height of the search tree \t\t\t= %d\n", treeHeight(rootPtr));
	
	fprintf(outFile, "Number of leaves in the tree \t\t= %d\n", countLeaves(rootPtr));
	
	fprintf(outFile, "Height of the left subtree of root \t= %d\n", treeHeight(rootPtr->leftChild));
	
	fprintf(outFile, "No. of strings in the left subtree \t= %d\n", countNodes(rootPtr->leftChild));
	
	fprintf(outFile, "Height of the right subtree of root = %d\n", treeHeight(rootPtr->rightChild));
	
	fprintf(outFile, "No. of strings in the right subtree = %d\n", countNodes(rootPtr->rightChild));
	

	//remember to close files that were opened
	fclose(inFile);
	fclose(outFile);

	//end program
	return 0;
}	//end main

// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_bst.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// ====================================================
// ================== Program Entry ===================
// ====================================================




void testAdd(){
	bst_t * testAdd = create_bst();

	bst_add(testAdd, 99);
	bst_add(testAdd, 12);
	bst_add(testAdd, 13);
	bst_add(testAdd, 14);

	bst_add(testAdd, 5);
	printf("Sum should be 130: %d\n",sum(testAdd));
	printf("printing bst\n");
	bst_print(testAdd, 0);
	bst_print(testAdd, 3);
	free_bst(testAdd);
	
}

void testTie(){
        bst_t * testTie = create_bst();

        bst_add(testTie, 3);
        bst_add(testTie, 3);
        bst_add(testTie, 3);
        bst_add(testTie, 9);

        printf("printing...\n");
        bst_print(testTie, 0);
        free_bst(testTie);

}


void testVacant(){
	bst_t * testVacant = create_bst();

	printf("Testing functions on an empty bst...\n");
	printf("bst_size should return  0:%u\n", bst_size(testVacant));
        printf("bst_empty should return  1:%d\n", bst_empty(testVacant));
       // printf("bst_find should return 0:%d\n", find(testVacant, 6));
       
           free_bst(testVacant);
	
}

void testNull(){
        bst_t * testVacant = NULL;

        printf("Testing functions on a null  bst...\n");
        printf("bst_add should return -1:%d\n", bst_add(testVacant, 5));
        printf("bst_size should return -1:%d\n", bst_size(testVacant));
        printf("bst_empty should return -1:%d\n", bst_empty(testVacant));
        printf("bst_find should return -1:%d\n", find(testVacant, 7));

           

}

void testSize(){
	bst_t * testSize = create_bst();
	printf("adding four numbers to bst...");
	bst_add(testSize, 1);
        bst_add(testSize, 3);
	bst_add(testSize, 99);
        bst_add(testSize, 7);
	printf("size should be 4 %d\n", bst_size(testSize));
           free_bst(testSize);
	
}



void testEmpty(){
//	printf("checking if empty on non existent bst should be 1 empty:%d", bst_empty(testEmpty));
	printf("Now creating an empty bst");
	bst_t * testEmpty = create_bst();
	printf("checking that bst is empty should return 1: %d\n", bst_empty(testEmpty));
	bst_add(testEmpty, 3);
	printf("added 3 as root. should return 0, not empty: %d\n", bst_empty(testEmpty));

           free_bst(testEmpty);

}



void testFind(){
	        bst_t * testFind = create_bst();

	bst_add(testFind, 99);
        bst_add(testFind, 7);
	bst_add(testFind, 63);

	printf("added 99, 7, 63.\n");

	printf("seeing if 7 is in bst %d\n",  find(testFind, 7));
	printf("seeing if 2 is in bst should return 0: %d\n",  find(testFind, 2));
	printf("seeing if 99 is in bst should return 1: %d\n",  find(testFind, 99));
        printf("seeing if 63 is in bst should return 1: %d\n",  find(testFind, 63));

           free_bst(testFind);
	


}

int main(){

  
	testAdd();
	testVacant();  
	testNull(); 
	testSize();
 	testEmpty();  
	testFind();
	testTie();

    return 0;
}

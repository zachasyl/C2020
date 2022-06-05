// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You need to add sufficient testing.
void unitTestPush(){

	stack_t* test1 = create_stack(5);
	printf("Attempting to push 20");
	stack_enqueue(test1, 20);	
	printf("top is %d\n", top->data);	
	stack_enqueue(test1, 16);
	printf("top is %d\n", top->data);
	stack_enqueue(test1, 91);
        printf("top is %d\n", top->data);



	 stack_dequeue(test1);
	 printf("top is %d\n", top->data);
	

	printf("stack size  %d\n",stack_size(test1));

	printf("stack full   %d\n",stack_full(test1));

       printf("stack empty  %d\n",stack_empty(test1));
	printf("adding 3  more");
	 stack_enqueue(test1, 91);
	 stack_enqueue(test1, 91);
	stack_enqueue(test1, 91);
	 printf("stack should be full:   %d\n",stack_full(test1));
	printf("adding another to full stack. this should fail %d\n", stack_enqueue(test1, 9));
	free_stack(test1);

}

void unitTest1(){

	stack_t* testCreate = create_stack(50);
	printf("Attempting to push %d\n",20);
	stack_enqueue(testCreate,20);	
	printf("Removing: %d\n",stack_dequeue(testCreate));	
	free_stack(testCreate);
	printf("!!! TESTING NULL!!!\n");
	stack_t* testNull = NULL;
	printf("should return -1 %d\n", stack_empty(testNull));
	free_stack(testNull);
	
	
}

void unitTest2(){

        stack_t* test2 = create_stack(100);
        printf("Attempting to push 20 15 and 91");
        stack_enqueue(test2, 20);
          
        printf("top is %d\n", top->data);
        stack_enqueue(test2, 15);
        printf("top is %d\n", top->data);
        stack_enqueue(test2, 91);
        printf("top is %d\n", top->data);

        stack_dequeue(test2);
        printf("removed top. top is %d\n", top->data);


 

        printf("stack size %d\n",stack_size(test2));

	printf("stack full  %d\n",stack_full(test2));

        printf("stack empty %d\n",stack_empty(test2));
	free_stack(test2);
}


void unitTest3(){
	// tests null return
	stack_t* test3 = NULL;
	printf("should return -1 \n %d\n", stack_empty(test3));
	free_stack(test3);


}
// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTestPush();
	unitTest1();
	unitTest2();
	 unitTest3();
	
	
	
	return 0;
}

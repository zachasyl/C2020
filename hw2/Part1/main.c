
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "myqueue.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// Basic create_queue() test.
void testCreate_Queue(){
	printf("!!!TESTING CREATE_QUEUE()!!!");
	printf("Createing queue size 3\n"); 	
	queue_t* testCreate = create_queue(3);

	printf("Attempting to add number 4 to queue");
	printf(" should return 1 if added:\n"); 
	printf("%d", queue_enqueue(testCreate,4));	
	printf("\nRemoving: %d\n",queue_dequeue(testCreate));
	
	free_queue(testCreate);
}

void testQueue_Empty(){
	printf("\n!!!TESTING EMPTY!!!()"); 
	// should return null
	printf("creating a queue with 0 capacity"); 
	queue_t* test1  = create_queue(0);
	printf(" should return null\n"); 
	printf("%d", queue_empty(test1));

	printf("\nCreating a queue with capacity 3\n") ;
	queue_t* test2  = create_queue(3);
	printf("adding two numbers, 50 and 60, to queue");
	queue_enqueue(test2, 50);                      
        queue_enqueue(test2, 60);

	queue_dequeue(test2);
        printf("\nRemoving item. Should return 0 not empty. Return: \n %d\n", queue_empty(test2));
	queue_dequeue(test2);
	printf("Removing item. should return 1, empty. Return:\n %d\n", queue_empty(test2));
	queue_dequeue(test2);
	printf("Removing item. Should return 1 still empty. Return: \n %d\n", queue_empty(test2));
	 free_queue(test1);
	free_queue(test2);
}

void testQueue_full(){
	printf("!!!TESTING QUEUE FULL!!!\n");	
// should return null
 	 queue_t* test3 = create_queue(0);
	printf("creating a queue capacity 0. full should return -1 Returns: %d\n",queue_empty(test3));

	queue_t* test4  = create_queue(3); 
	printf("creating a queue capacity 3\n");
	printf("adding 3 items\n");
	queue_enqueue(test4, 50);
	queue_enqueue(test4, 50);
	queue_enqueue(test4, 50);
	printf("testing if 3/3 is full %d\n", queue_full(test4));
	printf("removing one item\n");
	queue_dequeue(test4);
	printf("testing if 2/3 is full\n");
	printf("%d\n", queue_full(test4));
	free(test3->data);
	free(test3);
	free(test4->data);
	free(test4);
}
void testNull(){
	printf("!!! TESTING NULL!!!\n");
	queue_t* testNull = NULL;
	printf("Should return -1 %d\n", queue_empty(testNull));

}


void testQueue_Enqueue(){
	printf("!!!TESTING ENQUQUE!!!");
	printf("creating a queue capacity 2");
	queue_t*test5 = create_queue(2);
	printf("adding element\n");
	queue_enqueue(test5, 50);
	printf("adding element\n");
	queue_enqueue(test5, 60);
	printf("adding element. Should return 0\n");
	printf("%d\n", queue_enqueue(test5, 60));  
	printf("Create queue capacity 0\n");
	queue_t*test6 = create_queue(0);
	printf("adding element. should return -1\n");
	printf("%d\n", queue_enqueue(test6, 60));
	free_queue(test5);
	free_queue(test6);
}


void testQueue_Dequeue(){
	queue_t*test7 = create_queue(2);
	queue_enqueue(test7, 60);
 	queue_enqueue(test7, 30);
	//should return item
	queue_dequeue(test7);
	//should return item
	queue_dequeue(test7);
	//should return 0
	queue_dequeue(test7);

	queue_t*test8 = create_queue(0);
	//should return -1
	queue_dequeue(test8);
	free_queue(test7);
	free_queue(test8);
}
void testQueue_Size(){
	queue_t*test9 = create_queue(0);
	//should return -1
	queue_size(test9);

	queue_t*test10 = create_queue(3);
	queue_enqueue(test10, 1);
	queue_enqueue(test10, 2);
	// should return size is 2
	queue_size(test10);
	free_queue(test9);
	free_queue(test10);
}


void testcircularity(){
	// 33, 1, 4, 0 is correct.
	// the Back ended up as 0th element
	// and replaced 9 with 33 while the
	// front was on element 1 rather than 0
	printf("!!! TEST CIRCULARITY!!!");
	queue_t*testplease = create_queue(3);
	queue_enqueue(testplease, 9);
 printf("back is %d\n", testplease->back);
	queue_enqueue(testplease, 11);
 printf("back is %d\n", testplease->back);
	queue_enqueue(testplease, 4);
printf("back is %d\n", testplease->back);	
 	// queue_dequeue(testplease);
	// now head should be 1
	printf("front is %d\n", testplease->front);
	 queue_dequeue(testplease);
	queue_enqueue(testplease,33);	
	printf("back is %d\n", testplease->back);
	printf("front is %d\n", testplease->front); 
	printf("front value is %d\n", testplease->data[testplease->front]);
	// note that the FRONT ends at value 11. This is correct
	// I think but seems really weird. since its FIFO
	// 11 should indeed be the next number out which would occur
	// after another dequeue when head increases
	// running the two following commented out lines shows that 11 does indeed
	// get replaced next!
	//queue_dequeue(testplease);
	//queue_enqueue(testplease,99); 
	printf("%d\n",testplease->data[0]);
	
	printf("%d\n",testplease->data[1]);   
	printf("%d\n",testplease->data[2]);   
	printf("%d\n",testplease->data[3]);   
	free_queue(testplease);     	
}


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

//	 List of Unit Tests to test your data structure	
	testCreate_Queue();
	testQueue_Empty();
	testQueue_full();
	testQueue_Enqueue();
	testQueue_Dequeue();
	testQueue_Size();
	testcircularity();
	testNull();
	
	return 0;
}

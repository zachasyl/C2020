// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.



// ====================================================
// ================== Program Entry ===================
// ====================================================

// Creates a DLL and does a general check to see if items can be pushed and popped from list.
// Fills list and then empties it, checks if empty when full, partially full, and empty.
void unitTest1(){
    dll_t * myDLL = create_dll();

    dll_push_front(myDLL, 8) == 0; 
    dll_push_front(myDLL, 7) == 0;
    dll_push_front(myDLL, 13) == 0;
    dll_push_front(myDLL, 6) == 0;



	printf("Is the list empty? should be 0: %d\n", dll_empty(myDLL));
 
	// test whether push_front function works and whether myDLL head is correct. 
	printf("Pushed 8, 7, 13, 6.");
	printf("Headd should be 6. Head: %d\n ",myDLL->head->data);
	printf("Tail should be 8. Tail: %d\n ",myDLL->tail->data);

	printf("Empying list using pop front...\n");
	printf("removed: %d\n ", dll_pop_front(myDLL));
	printf("removed: %d\n ", dll_pop_front(myDLL));
	printf("Is the list empty? should be 0: %d\n", dll_empty(myDLL));
	printf("removed: %d\n ", dll_pop_front(myDLL));
	printf("removed: %d\n ", dll_pop_front(myDLL));

	printf("Is the list empty? should be 1: %d\n", dll_empty(myDLL));

	dll_empty(myDLL);

	free_dll(myDLL);
}


// testing all functions on null dll
void unitTest2(){

dll_t* nullTest = NULL;
printf("created null dll. Testing if all function return null: \n");


printf("%d\n",dll_empty(nullTest));
printf("%d\n",dll_pop_front(nullTest));
printf("%d\n",dll_pop_back(nullTest));
printf("%d\n",dll_push_front(nullTest, 5));
printf("%d\n",dll_push_back(nullTest, 6));
printf("%d\n",dll_get(nullTest,0));
printf("%d\n",dll_insert(nullTest, 6, 2));
printf("%d\n",dll_pop_front(nullTest));
}

// Tests functions on list with 0 items.
// Uses the empty DLL myDLL.
void unitTest3(){
dll_t * myDLL3 = create_dll();


printf("Popping front. Should return empty 0:  %d\n", dll_pop_front(myDLL3));
printf("Popping back. Should return empty 0:  %d\n", dll_pop_back(myDLL3));
printf("Getting. Should return empty 0:  %d\n", dll_get(myDLL3,0));
printf("Removing. Should return empty 0:  %d\n", dll_remove(myDLL3, 3));




// testing if you can push back when list is empty.
// testing if you can push front when list is empty.
// testing if you can pop front when dll has 1 item.
printf("Pushing back. Should return 1:  %d\n", dll_push_back(myDLL3,2));
dll_pop_front(myDLL3);
printf("Empty? should return 1 %d", dll_empty(myDLL3));
printf("Pushing front. Should return 1:  %d\n", dll_push_front(myDLL3,2));
dll_pop_back(myDLL3);
printf("Empty? should return 1 %d", dll_empty(myDLL3));


free_dll(myDLL3);

}


// test for push_back and testing get.

void unitTest4(){

dll_t * myDLL4 = create_dll();
printf("Pushing 8 to front");
dll_push_front(myDLL4, 8) == 0;
printf("Pushing 7 to front");
dll_push_front(myDLL4, 7) == 0;

printf("using dll_get  position 0. should be 7 %d\n", dll_get(myDLL4, 0));
printf("pushing 13 to front");
dll_push_front(myDLL4, 13) == 0;
printf("using dll_get  position 2. should be 8 %d\n", dll_get(myDLL4, 2));



printf("pushing 10 to back\n");
printf("this should be 0 not empty:  %d\n", dll_empty(myDLL4));
dll_push_back(myDLL4, 10) == 0;


printf("using dll_get on position 3 should be 10. %d\n", dll_get(myDLL4, 3));


printf("printing tail: %d\n",myDLL4->tail->data);
printf("pringing head%d", myDLL4->head->data);
printf("printing tail->previous->data%d\n",myDLL4->tail->previous->data);


printf("printing entire DLL using for loop\n");

node_t* curr = myDLL4->head;
int i = 0;
for(i; i<=  3; i++){

printf("%d\n", curr->data);
curr = curr->next;
}

free_dll(myDLL4);
}


// tests insert and remove
void unitTest5(){
    dll_t * myDLL5 = create_dll();
    printf("pushing 8, 7, 13, 6");
    dll_push_front(myDLL5, 8) == 0;
    dll_push_front(myDLL5, 7) == 0;
    dll_push_front(myDLL5, 13) == 0;
    dll_push_front(myDLL5, 6) == 0;
    printf("removing 0 index  number will return 0 success:");
    dll_remove(myDLL5, 0);
    printf("%d inserting 100 at position 1\n");
    dll_insert(myDLL5,1,100);



   node_t* curr = myDLL5->head;
   int i = 0;
   for(i; i<=  3; i++){
	printf("%d\n", curr->data);
	curr = curr->next;
   }	
free_dll(myDLL5);
}
    
int main(){
  
	unitTest1();
	unitTest2();
	unitTest3();
	unitTest4();
	unitTest5();
  	return 0;
}




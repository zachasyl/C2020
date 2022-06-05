// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* next;
  	struct node* previous;
}node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL{
	int count;		// count keeps track of how many items are in the DLL.
	node_t* head;		// head points to the first node in our DLL.
        node_t * tail;          //tail points to the last node in our DLL.
}dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
dll_t* create_dll(){
	// Modify the body of this function as needed.
	dll_t* myDLL = NULL;
	myDLL = (dll_t*) malloc(sizeof(dll_t));
	myDLL->count = 0;
	myDLL->head = NULL;
	myDLL->tail = NULL;
	return myDLL;
}

// DLL Empty
// Check if the DLL is empty
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
// Returns -1 if the dll is NULL.
int dll_empty(dll_t* l){
	if (!l){
		return -1;
	}
	if(l->count == 0){
		return 1;
	}
	else{
		return 0;
	}
}
// push a new item to the front of the DLL ( before the first node in the list).
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// Returns -1 if DLL is NULL.
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, int item){

	if (!l){
                return -1;
        }
	node_t* temp=(node_t*)malloc(sizeof(node_t));
	if(!temp)
    		return 0;
		temp->next = NULL;
		temp->previous = NULL;
		temp->data=item;
		
	if(l->count==0)
    		l->head=l->tail=temp;
	else{
    		temp->next=l->head;
    		l->head->previous=temp;
    		l->head=temp;
	}
	l->count++;
	return 1;
}

// push a new item to the end of the DLL (after the last node in the list).
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// Returns -1 if DLL is NULL.
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t* l, int item){

	if (!l){
                return -1;
        }
	node_t* temp = (node_t*) malloc(sizeof(node_t));

	if(temp == NULL)
    		return 0;
		temp->data=item;
		temp->next = NULL;
		temp->previous = NULL;
	if(l->count==0)
    		l->head=l->tail=temp;
	else{
    		temp->previous=l->tail;
    		l->tail->next=temp;
    		l->tail=temp;
	}
	l->count++;
	return 1;
 }


// Returns the first item in the DLL and also removes it from the list.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Returns a -1 if the DLL is NULL. 
// Assume no negative numbers in the list or the number zero.
int dll_pop_front(dll_t* l){

	if (!l){
                return -1;
        }
	else if(l->count == 0){
		return 0;
	}
	else{
    		int data=l->head->data;
    		l->head=l->head->next;
    		l->count--;
    		if(l->count==0)
      			l->tail = NULL;
    			return data;
	}
}

// Returns the last item in the DLL, and also removes it from the list.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Returns a -1 if the DLL is NULL. 
// Assume no negative numbers in the list or the number zero.
int dll_pop_back(dll_t* l){

	if (!l){
                return -1;
        }
	else if(dll_empty(l))
		return 0;

	else{
    		int data=l->tail->data;
    		l->tail=l->tail->previous;
    		l->count--;
    		if(l->count==0)
      			l->head=NULL;
    			return data;
	}
}

// Inserts a new node before the node at the specified position.
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
// Returns -1 if the list is NULL
int dll_insert(dll_t* l, int pos, int item){

	if (!l){
                return -1;
        }
	 if(pos == 0)
                return dll_push_front(l,item);
                node_t* newNode;	

	if(pos == l->count)
    		return dll_push_back(l,item);
	
	if(pos >l-> count || pos < 0 ||  (newNode = (node_t*)malloc(sizeof(node_t))) == NULL)

    		return 0;
		newNode-> data = item;
		newNode-> previous = NULL;
		newNode-> next = NULL;
		node_t* current=l-> head;
	while(--l->count != 0){
    		current = current-> next;
	}
	newNode->next = current-> next;
	current->next = newNode;
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
//  (does not remove the item)
// Retruns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Returns -1 if the list is NULL
// Assume no negative numbers in the list or the number zero.
int dll_get(dll_t* l, int pos){
	if (!l){
		return -1;
	}

	if (pos >= l->count || pos < 0){
		return 0;
	}

	node_t* curr = l->head;
	int i = 0;
	for(i; i <  pos; i++){
		curr = curr->next;}
		return curr->data;
}


// Removes the item at position pos starting at 0 ( 0 being the first item )
// Retruns 0 on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Returns -1 if the list is NULL
// Assume no negative numbers in the list or the number zero.
int dll_remove(dll_t* l, int pos){

	if (!l){
                return -1;
        }

	if(pos == l->count-1)
    		return dll_pop_back(l);
	if(pos == 0)
    		return dll_pop_front(l);
	if(pos < 0 || pos >= l->count )
    		return 0;
		node_t* current=l-> head;
	while(--l->count != 0){
    		current=current->next;
	}
	node_t* temp=current->next;
	current->next=current->next->next;
	return temp->data;
		}

// DLL Size
// Queries the current size of a DLL
// Returns -1 if the DLL is NULL.
int dll_size(dll_t* l){
	if(!l){
		return 0;}
	else
	return l->count;
}
// Free DLL
// Removes a DLL and all of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* t){
	if(!t)
	    return;
	else if (dll_empty(t)){
		free(t);
		return;
	}
    else
    
    while(t->head !=NULL){
      node_t* temps = t->head;
      t->head = temps->next;
      free(temps);
      
    }
free(t);

	
}
		


#endif

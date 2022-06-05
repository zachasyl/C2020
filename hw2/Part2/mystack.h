// =================== Support Code =================
// Stack
//
//
//
// - Implement each of the functions to create a working stack.
// - Do not change any of the function declarations
//   - (i.e. stack_t* create_stack() should not have additional arguments)
// - You should not have any 'printf' statements in your stack functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYSTACK_H
#define MYSTACK_H

// Stores the maximum 'depth' of our stack.
// Our implementation enforces a maximum depth of our stack.
// (i.e. capacity cannot exceed MAX_DEPTH for any stack)
# define MAX_DEPTH 32

// Create a node data structure to store data within
// our stack. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* next;
}node_t;
// global pointer
node_t* top;
// Create a stack data structure
// Our stack holds a single pointer to a node, which
// is a linked list of nodes.
typedef struct stack{
	int count;		// count keeps track of how many items
				// are in the stack.
	unsigned int capacity;	// Stores the maximum size of our stack
	node_t* head;		// head points to a node on the top of our stack.
}stack_t;

// Creates a stack
// Returns a pointer to a newly created stack.
// The stack should be initialized with data on the heap.
// Returns NULL if we couldnt allocate memory.
stack_t* create_stack(unsigned int capacity){

	
	// malloc myStack so it may be used outside function.
	stack_t* myStack = malloc(sizeof(stack_t));
	if (!myStack){
		return NULL;
	}
	else{
		//if myStack isnt null, initialize and return stack
		myStack->count = 0;
		myStack->capacity = capacity;
		myStack->head; 
		return myStack;
	}
}

// Stack Empty
// Check if the stack is empty
// Returns 1 if true (The stack is completely empty)
// Returns 0 if false (the stack has at least one element)
// Returns -1 if the stack is NULL.
int stack_empty(stack_t* s){
	if (!s){
                return -1;}
	else if (s->count == 0){
		return 1;}
	else if (s->count >= 1){
		return 0;}		
}

// Stack Full
// Check if the stack is full
// Returns 1 if true (The Stack is completely full, i.e. equal to capacity)
// Returns 0 if false (the Stack has more space available to add items)
// Returns -1 if the stack is NULL.
int stack_full(stack_t* s){
	if (!s){
                return -1;
        }
	else if (s->capacity == s->count){ 
	return 1;
	}
	else if (s->capacity >  s->count){
        return 0;
        }	

}
// Push a new item
// i.e. push a new item into our data structure
// Returns a 1 if the operation suceeds
// Returns a 0 if the operation fails 
// Returns -1 if the stack is NULL.
// (i.e. if the stack is full that is an error).
int stack_enqueue(stack_t* s, int item){
	if (!s){
                return -1;
         }
	else if (stack_full(s) == 1){
		return 0;
	}
	else{	
		// creates a temporary node.
		// node receives item.
		// temp next is set to global top of stack
		// top pointer points to node top of stack
		node_t* temp;
		temp = malloc(sizeof(node_t));
		//creates a new node with item.
		temp->data = item;
		//the new node's next wil be set to top
		temp->next = top;
		//now top will be set to temp -- top points to the newest entry on top of stack!
		top = temp;
		// stack head pointer is set to top. im making the stack head pointer
		// mimic the global top. I tried getting rid of the global pointer upon
		// rereading the instructions but i couldn't debug in time. 
		s->head = top;
		s->count += 1;
		return 1; 
	}
}
// Dequeue an item
// Returns the item at the front of the stack and removes an item from the stack.
// Removing from an empty queue returns a 0. Assume all entries are going to be > 0.
// Returns -1 if the stack is NULL. Assume there is not going to be negative numbers in the stack
int stack_dequeue(stack_t* s){
	if (!s){
                return -1;}
	else if (stack_empty(s) == 1){
		return 0;
	}
        else{
		node_t *temp;
    		int n;

    		temp = top;

    		n = temp->data;
		//top pointer points to node next to top
    		top = top->next;
		// delete termporary node
 		free(temp);
		// sets head pointer to top
		s->head = top;
		s->count -= 1;
    	
    		return n;
	}	
}

// Stack Size
// Queries the current size of a stack
// Returns -1 if the stack is NULL.
unsigned int stack_size(stack_t* s){
	if (!s){
		return -1;}
	else{
		
	return s->count;
	}
}
// Free stack
// Removes a stack and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_stack(stack_t* s){
	if (!s){
		return;
	}
	else if (stack_empty(s) == 1){
		free(s);
		return;
	} 
	
	else{
		// sets a temporary node to head ad.
		// sets head to next node.
		// deletes temporary node that used to be head
		// repeat untill all nodes are deleted.
		while (s->head != NULL){
			node_t* temps = s->head;
			s->head = temps->next;
			free(temps);
			
		}
	// frees stack
	free(s);
	// global set to null so head and global are null. prevents infinite while loop.
	top = NULL;
	}	
}	




#endif

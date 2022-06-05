#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// defines a new type struct node each of which will have
// wins and a year and each points to a next node
typedef struct node{
	int wins;
	int year;
	struct node* next;

}node_t;

// This function creates nodes and allocates space for them.
// It stores data in the nodes (wins and year).
// It also links each node to the next node.
// It returns the node head (2018)

node_t* createlist(){
	// Added to heap and will persist after function ends.
	node_t* year2018 = malloc(sizeof(node_t));
        node_t* year2017 = malloc(sizeof(node_t));
        node_t* year2016 = malloc(sizeof(node_t));
        node_t* year2015 = malloc(sizeof(node_t));
        node_t* year2014 = malloc(sizeof(node_t));

	year2018->year = 2018;
	year2017->year = 2017;
	year2016->year = 2016;
	year2015->year = 2015;
	year2014->year = 2014;

	year2018->wins =108;
        year2017->wins =93;
        year2016->wins =93;
        year2015->wins =78;
        year2014->wins =71;

	// linking the list
	year2018->next = year2017;
	year2017->next = year2016;
	year2016->next = year2015;
        year2015->next = year2014;
        year2014->next = NULL;
	
        return year2018;
}

// Frees space. Parameter is current node head, which is freed after print. 
//  Returns nothing.
void freedom(node_t* head){
free(head);
}

// Prints wins per year. Parameter is pointer head. Returns nothing.
void print_list(node_t* head){ 
        node_t* iterator = head;	
	// iterates through loop while iterator/head is not null (while it is not 2014).
	// Each iteration the wins/year of the current struc node head is printed
	// After the print, freedom(iterator) is called to free space since the
	// head pointer is no longer going to be used.
	// Then, we set iterator as next and repeat until iterator is pointer 2014 
	// which points to nothing.
	while(iterator != NULL){
		printf("wins in %d are %d\n", iterator->year, iterator ->wins);
		node_t *next = iterator->next;
		freedom(iterator);
		iterator = next;
	}	
}
int main(){
	// setting up the pointer redsocks
	node_t* redsocks = NULL;
	// call create list to create the list,
	// and the list will last once the function ends because of malloc.
        redsocks = createlist();
	//then call print to iterate and print.
	print_list(redsocks);
	return 0;
}


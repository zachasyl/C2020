// Task: Implement the 'sortIntegers' function below

// =================== Libraries ==================
#include <stdio.h> // Include file for standart input/output

// =============== Helper Functions ===============

// Swaps two numbers in an array
// Input: The 'address of' an index into an array for positions in an array.
// a is right index. b is value.
// right index is array[j+1]. value is array[j]

void swap(int* a, int* b){
// the second part of the swap happens after the second for loop.	
	*a = *b;
}

// Provided below is a sort function. We have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//          (1) 'array' is a pointer to an integer address. 
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'size' tells us how big the array of data is we are sorting.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void sortIntegers(int* array, unsigned int size){

	int i;
	int  key;
	int  j; 
    for (i = 1; i < size; i++) { 
        key = array[i]; 
        j = i - 1; 
 	 
        /* Move elements of arr[0..i-1], that are 
 *           greater than key, to one position ahead 
 *                     of their current position */

 
	for (j; j  >= 0 && array[j] >key; j--){
		swap(&array[j + 1], &array[j]);                                                                                                          
                                                           
    	}  
	// shifting to the right is over. the key is greater than array[j]
	// therefore we place the key to its right and no longer need to use
	// swap to push elements to the right.                                                               
       	array[j + 1] = key;                                                	    
	}	
}

// Input: A pointer to an array (i.e. the array itself points to the first index)
//        The size of the array (Because we do not know how big the array is automatically)
void printIntArray(int* array, unsigned int size){
  unsigned int i; // Note: 'unsigned int' is a datatype for storing positive integers.
  for(i = 0; i < size; i=i+1){
    printf("%d ",array[i]);
  }
  printf("\n");
}

int main(){
  
  // Some test data sets.
  int dataset1[] = {0,1,2,3,4,5,6,7,8,9,10};
  int dataset2[] = {10,9,8,7,6,5,4,3,2,1,0};
  int dataset3[] = {0,3,2,1,4,7,6,5,8,9,10};
  int dataset4[] = {2,1,1,1,1,1,1,1,1,1,1};
  int dataset5[] = {100,201,52,3223,24,55,623,75,8523,-9,150};
  int dataset6[] = {-1,1,2,-3,4,5,-6,7,8,-9,10};
  
  // Sort our integer array
  sortIntegers(dataset1, 11);
  sortIntegers(dataset2, 11);
  sortIntegers(dataset3, 11);
  sortIntegers(dataset4, 11);
  sortIntegers(dataset5, 11);
  sortIntegers(dataset6, 11);
  
  // Print out an array
  printIntArray(dataset1, 11);
  printIntArray(dataset2, 11);
  printIntArray(dataset3, 11);
  printIntArray(dataset4, 11);
  printIntArray(dataset5, 11);
  printIntArray(dataset6, 11);
  
  return 0;
}

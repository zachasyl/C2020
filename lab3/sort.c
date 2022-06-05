// Task: Implement the 'sortIntegers' function below

// =================== Libraries ==================
#include <stdio.h> // Include file for standart input/output

// =============== Helper Functions ===============

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int* array, int start, int stop){
    // TODO: Iterate through a subset of the array and find the minimum value.
    //       Return the index of that minimum value.
	
	int i;
	for(i = start  +1; i < stop; i++){
		if (array[i] < array[start]){
			start = i;
			array[start] = array[i];
		}		
	}	
    
    return start; 
}

// Swaps two numbers in an array
// Input: The 'address of' an index into an array for positions in an array.
void swap(int* a, int* b){

	int temp = *a;
	*a = *b;	
	*b = temp;
	
}

// Provided below is a sort function.
// Name: sort
// Input(s):
//          (1) 'array' is a pointer to an integer address. 
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'size' tells us how big the array of data is we are sorting.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void sortIntegers(int* array, unsigned int size){
	int i;
	int  min;
	
	for (i = 0; i  < size; i=i+1){
		// calls find minimum to return min. Swaps current i position with in.
		// then moves to next i position and repeats the search for next minimum,
		// comparing rest if list with current i.
		min  = findMinimum(array, i, size);	
		swap(&array[i],&array[min] );
	}		
	
}


// Input: A pointer to an array (i.e. trray[i]);he array itself points to the first index)
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

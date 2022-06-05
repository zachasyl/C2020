// Task: Implement the 'sortIntegers' function below

// =================== Libraries ==================
#include <stdio.h> // Include file for standart input/output

// =============== Helper Functions ===============

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r){ 


 int i;
 int j;
 
   
 int s1 = m - l +1;
 int s2 = r - m;
 int left[m - l + 1];
 int right[r - m];
		
        for (i = 0; i <  s1; i++){
               left[i] = arr[l + i];
}
	
        for (j = 0; j < s2; j++){
               right[j] = arr[m + 1 + j];
}	

    int k = l;//k=l is left or 'start'
    int le = 0;
    int ri = 0;
    while(le <s1 && ri <s2)//merge left array and right array in sorted order
   {
       if(left[le]<=right[ri])
       {
           arr[k]=left[le];
           le++;
       }
       else
       {
           arr[k]=right[ri];
           ri++;
       }
       k++;
   }
  
   while(le < s1)
   {
       arr[k]=left[le];
       le ++;
       k ++;
   }
  
   while(ri < s2)
   {
       arr[k]=right[ri];
       ri ++;
       k ++;
   }
}

void sorter(int arr[], int start, int end){
        if (start < end ){
                int mid =  start + (end- start) / 2;
                sorter(arr, start, mid);
                sorter(arr, mid + 1, end);
                merge(arr, start,  mid, end);
}
}


// Provided below is a sort function. We have also
// provided a template for how to document functions
// to help organize your code.
// Name: sortIntegers
// Input(s):
//          (1) 'array' is a pointer to an integer address. 
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'size' tells us how big the array of data is we are sorting.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void sortIntegers(int* array, unsigned int size){
	// I cannot recursively call this function if it only has two paremeters???? so I made another helper 		function
	unsigned int start = 0;

	sorter(array,start, size - 1);
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

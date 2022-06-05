// gcc factorial.c -o factorial
// ./factorial

#include <stdio.h>

// TODO: Implement iterative solution here
unsigned long factorial(unsigned long n){

	unsigned long answer = 1;
	int i;
  	for (i = 1;i <=n; i++){
		answer = answer * i;
	}

  return answer;
};

// TODO: Implement recursive solution here
unsigned long factorial_rec(unsigned long n){
	// the base case
	if(n < 1){
		return 1;}
	
	return n * factorial_rec(n-1);
}

int main(){

  printf("factorial(10) = %llu\n",factorial(10));
  printf("factorial_rec(10) = %llu\n",factorial_rec(10));


  return 0;
}

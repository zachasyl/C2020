#include <stdio.h>

/**
 *  This function takes a base and raises it to power n
 *  @param double base the number being raised to a power
 *  @param n the double value of the power
 *  @return double calculation, result of the base to n power
 */
double power(double base, double n){
  	double calculation = base;
	// note that while n = 1,while loop will not run
	// and  return calculation returns 2
	while(n > 1){
		// calculation multiplies itself by two
		// the amount of times n is greater than 1
		calculation *= base;
		--n;
	}
	return calculation;	 
}

int main(){
	// 2 is the double base to be raised to n power
	double base = 2;
	double  n = 1;
	// for powers 1 through 10, power function is called
	// and its return value is printed
	for (n = 1; n <= 10; n++){
		double answer = 0;
		answer = power(base, n);
		printf("answer is: %f.\n", answer);
	}
	return 0;
}


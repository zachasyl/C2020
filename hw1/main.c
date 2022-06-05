// Add your program here!
#include <stdio.h>
#include <stdlib.h>
// declaration of high_or_low function which takes integer guess and integer randomNumber
// and returns nothing.
void high_or_low(int guess, int randomNumber);
// declaration of random_number function which takes no parameters and returns an integer.
int random_number();
// declaration of game_over function, which takes array round_guess_amount as parameter
// returns nothing.
void game_over(int round_guess_amount[]);

int main(){
	// first thing main will do is use current time as seed for random number
	srand(time(0)); 
	//int gameNumber, the round of the game.
	int gameNumber;
	// int guess, the player's guess
	int guess;
	//int randomNumber, a pseudo randomly generated number
	int randomNumber;
	//guess_amount, amount of guesses per round to be stored in an array.
	int guess_amount;
	// an integer array which stores 5 integers,
	// the amount of guesses per each of the 5 rounds
	int round_guess_amount[5];
	// initializes integer i which is used to increment
	// the index of round_guess_amount
	int i = 0;

	// this for loop increments after a round of the game is complete
	for (gameNumber = 0; gameNumber < 5; gameNumber++){
		// initialize guess_amount starting at 1. If while loop is not triggered, 
		//there has been one guess.
		guess_amount = 1; 
		// calls random_number() to generate random number
		randomNumber = random_number();
		printf("PICK A NUMBER 1 THROUGH 10\n");
		// user input as guess
		scanf("%d", &guess);
		// for each round, the while loop will run until the guess does equal 
		// the random number.
		while (guess != randomNumber){
			high_or_low(guess, randomNumber);
                	scanf("%d", &guess);
			guess_amount += 1;
		}
		// once the guess does equal the number, the while loop ends and this code runs
	  	printf("correct guess!\n");
        	round_guess_amount[i] = guess_amount;
		i += 1;
	}
	// the for loop ends after all rounds are complete and then the game_over function is called
	game_over(round_guess_amount);
}
	

void game_over(int round_guess_amount[]){
	int z = 0;
	printf("Final Round Complete. Game over!\n");
        for (z = 0; z <= 4; z++){
                printf("Round %d: %d guesses\n",z, round_guess_amount[z]);

	}
}

//note function declarations are at top above main

// note that although else will include guess = randomNumber it is okay
// since this function can never trigger if they are equal. 
void high_or_low(int guess, int  randomNumber){
	if (guess > randomNumber){
		printf("guess again! lower!\n");
	}
	else{
		printf("guess again! higher!\n");
	}
}

// returns pseudo random number between 1 - 10
int random_number(){
	// without the + 1 the max amount would be 9, ie, 99 % 10 = 9..+ 1 = 10
        return rand() % 10 + 1;
 }



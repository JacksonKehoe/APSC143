/*
 * Lab 3 - Guess a Number
 *
 *   Jackson Kehoe, 20105920, 17jpk3
 *   Hussan Asim, 20115592, 17ah79
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXTURNS 3 
#define MAXNUM 10
#define MINNUM 1

int main(int argc, char **argv)
{
	int randNum, guess, isGameWon, turn;
	
	// Code generating random number that must be guessed
	srand(time(NULL));
	randNum = (rand() % (MAXNUM-MINNUM+1))+MINNUM;
	
	//Flag where initially assumed that game is lost
	isGameWon = 0;	
	
	
	// Loop that allows the user to have a maximum of 3 guesses
	for(turn=0; turn<MAXTURNS; turn++)  {
	//do while loop to make output ask again if number not in range
		do
		{

        //statement telling the user what to input
        printf("Enter a number between %d and %d \n",MINNUM , MAXNUM);
        // reads the guess and stores it under guess
		scanf("%d",&guess);
		
		}
		//while statement that checks to see if invalid number was input so it asks for a number again
		while(guess<MINNUM || guess>MAXNUM);
		
        // if statement checking to see if guess is correct
		if(guess==randNum)
		{
			isGameWon = 1;
			break;
		}
		//if statement to give feedback to user
		if(guess>randNum)
		{
			printf("Guess lower!\n");
		}
		//else statement to cover all other scenarios
		else 
		{
			printf("Guess higher!\n");
		}
		
	}
	//if statement checking to see if flag was set and game won
	if(isGameWon==1)
	{
		printf("You have won!\n");
	}
	//else statement for all other cases where game was lost and letting user know the correct answer
	else
	{
		printf("Sorry, the number was %d! Better luck next time!\n",randNum);
	}
	
	
	
    
    
    
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define USERCHARS 200
#define ROTORLEN 26
#define NROTORS 3

// These are the encryption rotors They map the input to the
// output of each rotor. To go backwards through the rotor you
// have to search for the element and find the index.

int rotorZero[ROTORLEN] = {18,7,10,0,17,9,12,11,8,3,16,22,15,2,14,13,6,23,4,19,20,1,5,25,21,24,};
int rotorOne[ROTORLEN] = {4,11,23,20,15,8,7,9,12,24,17,0,1,10,6,22,19,2,16,13,21,14,3,5,18,25,};
int rotorTwo[ROTORLEN] = {2,25,21,19,13,20,24,16,15,7,18,10,3,8,5,17,12,0,4,9,11,14,1,23,6,22,};
int reflector[ROTORLEN] = { 3, 16, 12, 0, 18, 11, 24, 22, 25, 17, 15, 5, 2, 23, 20, 10, 1, 9, 4, 21, 14, 19, 7, 13, 6, 8 };
 
/* main function:
 * Read a line of input and encrypt each letter to produce a new line of input.
 *    -- For each letter, check if it is a letter, if not ignore
 *    -- convert the the letter number A = 0, B = 1, C = 3, ...
 */
int main(int argc, char** argv)
{


    int i;
    int letter, letterNum, rotor0Out, rotor1Out, rotor2Out, reflectorOut;
	char userInput[USERCHARS];

    printf("WELCOME TO ENIGMA\n\n");
    printf("\nEnter Transmission: \t\n\n");

    // Take in Character String
	fgets(userInput,USERCHARS,stdin);
	while (strcmp(userInput,"done\n") != 0){
       for (i = 0; i < strlen(userInput); i++){
		   letter = userInput[i];
		   //if statement checking if input is letter
		   if(isalpha(letter))
		   {
			   //if statement to check if upper case
		    if(isupper(letter))
			   {
				   letterNum = letter - 'A';
			   }
			   //else for other case where letter is lowercase
			   else
				   {
						letterNum = letter - 'a';
				   }
				   //putting user input into the rotors
			   rotor0Out=rotorZero[letterNum];
			   rotor1Out=rotorOne[rotor0Out];
			   rotor2Out=rotorTwo[rotor1Out];
			   reflectorOut=reflector[rotor2Out];
			   //output of reflector and converting the number to a letter
			   printf("%c", reflectorOut + 'A');
		   
			   
		   }
	   }
	   printf("\n");
	   fgets(userInput,USERCHARS,stdin);

    }

    return 0;
}

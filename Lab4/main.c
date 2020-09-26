#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio4.h>
# define MAXCHARS 100


int main(int argc, char **argv)
{
	FILE* infile;
	//creating arrays
	char string[MAXCHARS], userInput[MAXCHARS];
	//creating variables for Msec
	long long startMsec,endMsec ;
	//creating total time variable
	float totalTime;
	//creating error count variable
	int errors=0;
	//creating word count variable
	float words=0;
	//creating words per minute variable
	float wordsPerMinute;
	//creating variable for time in minutes
	float timeInMinutes;
	//read file
	infile = fopen("../typingTest.txt","r");
	//if statement if file is not opened
	if(infile==NULL)
	{
		printf("Could not open the file");
		exit(1);
	}
	startMsec=getmSecs();
	//loop goes over each line
	while(fgets(string,MAXCHARS,infile))
	{
		printf("\n");
		//This loop goes each character in one word
		for(int i = 0; i < strlen(string); i++)
		{
			
			printf("%c",string[i]);
		}
		//gets user input
		fgets(userInput, MAXCHARS, stdin);
		words++;
		
		//compare userInput string and string
		
		while (strcmp(string,userInput) !=0)
		{
			//calculates amount of errors
			errors++;
			printf("Error please type :");
			//for showing correction for the user
			for(int i = 0; i < strlen(string); i++)
			{
			printf("%c",string[i]);
			}
			fgets(userInput, MAXCHARS, stdin);
			}
		}
		endMsec = getmSecs();
		fclose(infile);
		printf("\n");
		printf("Test Complete");
		//calculating amount of time
		totalTime = (float) (endMsec - startMsec)/1000;
		printf("\n");
		printf("Time : %0.1f seconds",totalTime);
		//printing amount of errors
		printf("\n");
		printf("Amount of errors : %i",errors);
		//calculating words per minute
		timeInMinutes=totalTime/60;
		wordsPerMinute=words/timeInMinutes;
		printf("\n");
		printf("Your speed is: %0.1f words per minute", wordsPerMinute);
		
		
		
	}
	
 

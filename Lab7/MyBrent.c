//Jackson Kehoe, 20105920, 17jpk3
//Hussan Asim, 20115592, 17ah79
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// including classes

#define MAXPRICES 7917
#define BUSDAYS_PER_MONTH 21
// defining constants

int main () 
{
	float prices[MAXPRICES];
	int numPrices, numMonths;
	int month, startDay, day;
	int minForMonth, maxForMonth;
	int spike, maxSpike;
	int maxMonth;
	int deltaMonths, deltaYears, spikeMonth, spikeYear;
    float absoluteMax = 0.0;
	int startMonth = 5; // june
	int startYear = 1987;
	// declaring variables 
   
	// read the file.
	FILE *infile = fopen("../brent.txt", "r");
   
	if (infile == NULL){
		printf("Could not open file.");
		exit(1);
	}
   
	// save the data in an array
	for (int x = 0; x < MAXPRICES; x++){
		fscanf(infile, "%f", &prices[x]);
	}
	
	fclose(infile);
	// closing file 
	
	// finding largest value in the array 
	for (int x = 0; x < MAXPRICES; x++){
		if (absoluteMax < prices[x]){
			absoluteMax = prices[x];
		} 
	}
	
	numMonths = MAXPRICES/BUSDAYS_PER_MONTH;
	maxSpike = 0.0;
	spike = 0.0;
	// initializing variables
	
	for (month = 0; month < numMonths; month++){
		// Set min and max prices for the month
		maxForMonth = 0;
		minForMonth = (int)absoluteMax;
		
		startDay = month * BUSDAYS_PER_MONTH;
		
		for (int day = startDay; day < (startDay + BUSDAYS_PER_MONTH); day++){
			// Use if-statements to search for min and max prices and spike in prices
			if (maxForMonth < prices[day]){
				maxForMonth = prices[day];
			} 
			// checking for and setting highest value of the month
			
			if (minForMonth > prices[day]){
				minForMonth = prices[day];
			}
			// checking for and setting lowest value of the month
		}
		
		spike = maxForMonth - minForMonth;
		// calculating spike
		
		if (maxSpike < spike){
			maxSpike = spike;
			maxMonth = month;
		}
		// checking for and setting highest spike
	}
	
	printf("The month with the max spike is %d\n", maxMonth);
    // printing month number of the highest spike
   
//  Find the year and month (the order) that max spike has happened
	deltaYears = maxMonth/12;
	deltaMonths = maxMonth;
	spikeYear = startYear + deltaYears;
	spikeMonth = startMonth + deltaMonths;
	// calculating spike year and month
	
	if (spikeMonth > 11){
		spikeMonth = spikeMonth - 12;
		spikeYear++;
	}
	// convert back to ascii
	
	spikeMonth = spikeMonth % 12;
	
	switch(spikeMonth){
	// Find the month's name 
		case 0:
			printf("December");
			break;
		case 1:
			printf("January");
			break;
		case 2:
			printf("Febuary");
			break;
		case 3:
			printf("March");
			break;
		case 4:
			printf("April");
			break;
		case 5:
			printf("May");
			break;
		case 6:
			printf("June");
			break;
		case 7:
			printf("July");
			break;
		case 8:
			printf("August");
			break;
		case 9:
			printf("September");
			break;
		case 10:
			printf("October");
			break;
		case 11:
			printf("November");
			break;
		default:
			break;
	}
	printf(", %d\n", spikeYear);
	// printing spike year
}
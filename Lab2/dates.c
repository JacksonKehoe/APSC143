//
//  dates.c
//  
//  compute the number of days between two dates
//
//   Jackson Kehoe, 17jpk3, 20105920
//   StudentName2, studentNetid2, studentnumber2

#include <stdio.h>
#define MONTHS_IN_YEAR 12
#define DAYS_IN_MONTH 30

int main(int argc, char **argv)
{
    
    //define variables
	int day_1;
	int day_2;
	int mth_1;
	int mth_2;
	int yr_1;
	int yr_2;
	int days;
	int months;
	int years;
	int date_1;
	int date_2;
	float time_In_Years;
	
	date_1 = 20180906;
	date_2 = 20181220;
    
	day_1 = date_1 % 100;
	mth_1 = (date_1 % 10000 - day_1) / 100;
	yr_1 = (date_1 % 100000000 - mth_1 + day_1) / 10000;
	
	day_2 = date_2 % 100;
	mth_2 = (date_2 % 10000 - day_2) / 100;
	yr_2 = (date_2 % 100000000 - mth_2 + day_2) / 10000;
	
	printf("Date 1: %d/%d/%d \n", yr_1, mth_1, day_1);
	printf("Date 2: %d/%d/%d \n", yr_2, mth_2, day_2);
	
    
    
    day_1 = 6;
    mth_1 = 9;
    yr_1 = 2018;
    
    day_2 = 20;
    mth_2 = 12;
    yr_2 = 2018;
	

    days = day_2 - day_1;
    //Add an expression to determine the number of months between the dates
	months = mth_2 - mth_1;
    //Add an expression to determine the number of years between the dates
	years = yr_2 - yr_1;
    
    if(day_1 > day_2)
		{
		//Add a statement to decrement the number of months by 1
        months = months - 1;
        days += DAYS_IN_MONTH; //Assuming 30 days in month
		}
    if(mth_1 > mth_2)
		{
        //Add a statement to decrement the number of years by one
		years = years - 1;
        months += MONTHS_IN_YEAR;
    }
    
    //Add print statement to print the number of days, months, and years between the date
	
    printf("%d years, %d months, %d days.\n", years, months, days);
	{
	
	
	}
	
	
	time_In_Years = (years*365 + months*DAYS_IN_MONTH + days) / 365;
	
	printf("Total Years : %0.2f", time_In_Years);
	}
		
 
 
    

#include <stdio.h>
/*The goal is to familiarize yourself with the Codelite debugging environment
 * Use double slashes to declare a comment. Comments have no effect on
 * the program, and exists to communicate what is going on to the programmer or reader
 * To find the value of each variable, use the Locals tab of the Debugger.
 * To access the debugger, set a Breakpoint at the beginning of the program
 * (click next to the numbers on the left until a pink dot appears), then select
 * Debugger->Start/Continue Debugger from the top of the window.
 * Use the down arrows on the far left to execute lines one at a time. Note that the
 * green arrow represents the command ABOUT to be executed,
 * So the values in the box are representative of everything UP to but not including
 * the line with the arrow
 * 
 * */



int main()
{
    // Declare Initial Values of Variables
    int intVar = 8;
    float floatVar = 2.25;

    // Observe the results of computing the same data type
    // When assigning a float value to an integer variable, the value gets truncated
    // A float + an int is a float
    int intRes;
    // Breakpoint
    intRes = intVar + intVar;    // <<< set breakpoint for this line.
    
    // STOP HERE - Look at values window
    intRes = floatVar + floatVar;
    
    // STOP HERE - Look at values window
    intRes = intVar + floatVar;

    // Define a float variable to store the results:
    float floatRes;
    
    // STOP HERE - Look at values window
    floatRes = floatVar + floatVar;
    
    // STOP HERE - Look at values window
    floatRes = intVar + floatVar;
    
    // STOP HERE - Look at values window
    floatRes = intVar + intVar;

    // Constants work the same way. They default to int unless a decimal is specified
    // STOP HERE - Look at values window
    floatRes = 7 / 2;
    
    // STOP HERE - QUESTION 8
    floatRes = 7.0 / 2.0;
    
    //Finally, powers.
    //The Hat Operator (^) does not compute powers!
    // STOP HERE - Look at values window
    intRes = 2 ^ 3;
    //In C you must use multiplication
    // STOP HERE - Look at values window
    intRes = 2 * 2 * 2;

    // Pointers!
    // Pointers store the address of a variable. They reference the parking space, not the car inside it.
    // Use * to specify a pointer. Use & to specify a memory address. These will be LARGE numbers, likely reprecented in Hexidecimal (numbers and letters).
    int* pointer = &intVar;

    // Using * sets the value of the variable at address pointer to 20
    // STOP HERE - Look at values window
    *pointer = 20;
    
    // STOP HERE - Look at values window
    intRes = *pointer;
    
    //Similarly for float values:
    // STOP HERE - Look at values window
    float* floatPointer = &floatVar;
    
    // STOP HERE - Look at values window
    *floatPointer = 9.75;
    
    // STOP HERE - Look at values window
    return 0;
}

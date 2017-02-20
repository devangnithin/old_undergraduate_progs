/*
Program Title: To find the sum and average of three real numbers.
Author: Nithin Devang
Date: 03 August 2011
Compiler Used: Dev C++ by Blood Shed
Version: Beta
*/
#include<stdio.h>
//#include<conio.h>  /*For Turbo C in windows */
int main() 
{
    float number1, number2, number3, sum, average;
    //clrscr(); /*For Turbo C */
    printf("Enter 3 Real Numbers :-)Either providing space or Enter\n"); //\n is new line character, 
                                          //removing this will take the
                                          // input in the same line its printed..Try it.
    printf("The Number should be in decimal format like 4.4 and not in fraction like 4/3\n");
    scanf("%f %f %f",&number1, &number2, &number3);
    
    
    sum = number1 + number2 + number3;
    average = sum / 3;
    printf("The Sum is %f and the Average is %f \n", sum, average );
    
    //getch(); // Turbo c. To hold the output screen for exiting
    return 0;
}
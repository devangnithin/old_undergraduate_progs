/*
Program Title: To find the largest of 3 numbers using if statement
Author: Nithin Devang
Date: 03 August 2011
File Name: largest_of_three.c
Compiler Used: Dev C++ by Blood Shed
Version: Beta
*/
#include<stdio.h>
//#include<conio.h>  /*For Turbo C in windows */
int main() /* If you are using void instead of int remove the return value at line */
{
    int number1, number2, number3,big=0;
    //clrscr(); /*For Turbo C */
    printf("Enter 3 Numbers"); //\n is new line character, 
                                          //removing this will take the
                                          // input in the same line its printed..Try it.
    scanf("%d %d %d",&number1, &number2, &number3);
    
    
    if(number1 >= number2 ) // If it satisfies it means number1 is
                          //greater then number 2 but it
                          //should be compared with number 3
    {
               if (number1 >= number3 )//If it satisfies this it means number1 is greater then
                                          //number 2 and number 3
               {
                           big= number1;
               }
               if ( number3 >= number1) //number 1 is greater then number 2 but its smaller number 3 means number 3 is biggest
               {
                    big=number3;
               }
    }
    if ( number2 >= number1) // it means number1 is not big, so its ignored and number2 is compared with 3;
    {
         if(number2 >= number3)
         {
                    big=number2;
         }       
         else
         {
             big = number3;
         }
    }

    printf("The Big B here is %d \n", big );
    
    getch(); // Turbo c. To hold the output screen for exiting
    return 0;
}
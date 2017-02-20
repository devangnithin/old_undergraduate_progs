/*
Program Title: To find if a number is even or odd using if-else
Author: Nithin Devang
Date: 04 August 2011
File Name: odd_even.c
Compiler Used: Dev C++ by Blood Shed
Version: Beta
*/
#include<stdio.h>
//#include<conio.h>  /*For Turbo C in windows */
int main() 
{
    int number1;
    //clrscr(); /*For Turbo C */
    printf("Enter a Number"); //\n is new line character, 
                                          //removing this will take the
                                          // input in the same line its printed..Try it.
    scanf("%d",&number1);
    
    
    if(number1 % 2 == 0) //% will return the remainder value after division.
    {                     // This will be 0 if number is even. Example 4/2 remainder is 0, value is 2.
        printf("Number is EVEN \n");
    }                  
    else
    {
               printf("number is ODD \n");
    }
    
    //getch(); // Turbo c. To hold the output screen for exiting
    return 0;
}
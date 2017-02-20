/*
Program Title: To find sum of digits
Author: Nithin Devang
Date: 04 August 2011
File Name: sum_of_digits.c
Compiler Used: Dev C++ by Blood Shed
Version: Beta
*/
#include<stdio.h>
//#include<conio.h>  /*For Turbo C in windows */
int main() /* If you are using void instead of int remove the return value at line */
{
    int number1, lastDigit, sum=0;//sum should be initialized to 0 to avoid garbage value
    //clrscr(); /*For Turbo C */
    printf("Enter a Number"); //\n is new line character, 
                                          //removing this will take the
                                          // input in the same line its printed..Try it.
    scanf("%d",&number1);
    while(number1!=0)
    {
                    lastDigit= number1 % 10; //Dividing by 10 the remainder will be the last digit
                                             // Example 568/10, upto 560 it will be divided and 8 will remain.
                    number1= number1 / 10; //Dividing the number 568 by 10 will give the value 56.8, but
                                           // Since its of type int it will ignore the decimal part and retain only 56.
                    sum = sum + lastDigit; // Old added sum + last digit of this loop.
    }//Till the number1 is 0 the while loop repeats.
    printf("The sum of digits is %d \n", sum);
    
    getch(); // Turbo c. To hold the output screen for exiting
    return 0;
}
/*
Program Title: To find if a number is prime
Author: Nithin Devang
Date: 04 August 2011
File Name: find_prime.c
Compiler Used: Dev C++ by Blood Shed
Version: Beta
*/
#include<stdio.h>
//#include<conio.h>  /*For Turbo C in windows */
int main() /* If you are using void instead of int remove the return value at line */
{
    int number1, i, prime_true=1;
    //clrscr(); /*For Turbo C */
    printf("Enter a Number- "); //\n is new line character, 
                                          //removing this will take the
                                          // input in the same line its printed..Try it.
    scanf("%d",&number1);
    
    for(i=2;i<=number1/2;i++)
    {
                             if (number1%i==0)
                             {
                                              prime_true=0;
                             }
    }
    if(prime_true==1)
    {
                     printf("This number is prime\n");
    }
    else
    {
        printf("Not prime\n");
    }
                             
    getch(); // Turbo c. To hold the output screen for exiting
    return 0;
}
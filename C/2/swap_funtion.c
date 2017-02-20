/*
Program Title: Swap using function.
Author: Nithin Devang
Date: 04 August 2011
File Name: swap_function.c
Compiler Used: Dev C++ by Blood Shed
Version: Beta
*/
#include<stdio.h>
//#include<conio.h>  /*For Turbo C in windows */
void swap(int *number1Address, int *number2Address)
{
     int temp; // local variable- scope is inside the function only
     temp = *number1Address; //read *x as content at address x.
     *number1Address = *number2Address;
     *number2Address = temp;
}
int main() /* If you are using void instead of int remove the return value at line */
{
    int number1, number2;
    printf("Enter number 1\n");
    scanf("%d",&number1);
    printf("Enter number 2 \n");
    scanf("%d",&number2);
    swap(&number1, &number2); //we are passing the address and not the values.
    printf("number1 = %d \n number2 = %d", number1, number2);
    getch(); // Turbo c. To hold the output screen for exiting
    return 0;
}
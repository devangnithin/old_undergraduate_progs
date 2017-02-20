/*
Program Title: To find if a number is prime
Author: Nithin Devang
Date: 04 August 2011
File Name: bubble_sort.c
Compiler Used: Dev C++ by Blood Shed
Version: Beta
*/
#include<stdio.h>
//#include<conio.h>  /*For Turbo C in windows */
int main() /* If you are using void instead of int remove the return value at line */
{
    int count, index, numberArray[30], choice, indexSecond, temp;
    //clrscr(); /*For Turbo C */
    printf("Enter number of elements- "); //\n is new line character, 
                                          //removing this will take the
                                          // input in the same line its printed..Try it.
    scanf("%d",&count);
    
    for(index=0;index<count;index++)
    {
                             //clrscr(); /*Turbo C*/
                             printf("Enter %dth number\n",index+1); //index starts from 0. 0th element=1st element
                             scanf("%d",&numberArray[index]);       
    }
    printf("\n\n"); //Just for entering two new lines
    printf("MENU\n");
    printf("1 -> Asceding order\n");
    printf("2 -> Desceding order\n");
    
    scanf("%d", &choice);            
    
    if(1 == choice)
    {
         printf("You have chosen to arrange numbers in Ascending order\n");
         for(index = count-2; index >= 0; index--)
         {
                   for(indexSecond = 0; indexSecond <= index; indexSecond++)
                   {
                                   if(numberArray[indexSecond] > numberArray[indexSecond+1])
                                   {
                                                               temp = numberArray[indexSecond];
                                                               numberArray[indexSecond] = numberArray[indexSecond + 1];
                                                               numberArray[indexSecond+1] = temp;
                                   }
                   }
         }
    }
    
    if(2 == choice)
    {
         printf("You have chosen to arrange numbers in Desending order\n");
         for(index = count-2; index >= 0; index--)
         {
                   for(indexSecond = 0; indexSecond <= index; indexSecond++)
                   {
                                   if(numberArray[indexSecond] < numberArray[indexSecond+1])
                                   {
                                                               temp = numberArray[indexSecond];
                                                               numberArray[indexSecond] = numberArray[indexSecond + 1];
                                                               numberArray[indexSecond+1] = temp;
                                   }
                   }
         }
    }
    for(index = 0 ; index < count ; index++)
    {
              printf("%d \t",numberArray[index]);
    }
                             
    getch(); // Turbo c. To hold the output screen for exiting
    return 0;
}
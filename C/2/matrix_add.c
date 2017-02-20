/*
Program Title: To Add and subtract matrix
Author: Nithin Devang
Date: 04 August 2011
File Name: matrix_add.c
Compiler Used: Dev C++ by Blood Shed
Version: Beta
*/
#include<stdio.h>
//#include<conio.h>  /*For Turbo C in windows */
int main() /* If you are using void instead of int remove the return value at line */
{
    int matrix1[3][3], matrix2[3][3], addedMatrix[3][3], i, j, choice;
/*This demo is for 3 X 3 matix. you may re write this program for matrix of any order. Rean the M X N value
from the user through scanf through a variable and substitute in the for loop*/
    printf("Enter the element of first matrix ");

    for(i=0;i<3;i++)
    {
                    for(j=0;j<3;j++)
                    {
                                    printf("\n a %d % d :-",i,j);
                                    scanf("%d",&matrix1[i][j]);
                    }
    }

    printf("Enter the element of second matrix ");

    for(i=0;i<3;i++)
    {
                    for(j=0;j<3;j++)
                    {
                                    printf("\n b %d % d :-",i,j);
                                    scanf("%d",&matrix2[i][j]);
                    }
    }
    
    printf("MENU    1-> ADD    2-> Subtract\n");
    scanf("%d",&choice);
    
    for(i=0;i<3;i++)
    {
                    for(j=0;j<3;j++)
                    {
                                    if(1 == choice)
                                    {
                                         addedMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
                                    }
                                    else
                                    {
                                         addedMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
                                    }
                                    printf("%d " ,addedMatrix[i][j]);
                    }
                    printf("\n");
    }
    
                             
    getch(); // Turbo c. To hold the output screen for exiting
    return 0;
}
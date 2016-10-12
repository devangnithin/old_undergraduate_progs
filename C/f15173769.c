#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>
int count=1;
void main()
{
	clrscr();
	int a,b,i,nop,nos,key,j=0,flag=0,r;
	fstream rec;

	char usn[11],tempusn[80],temp[80];

	printf("Enter number of programs\n");
	scanf("%d",&nop);
	printf("Enter no of students\n");
	scanf("%d",&nos);
	clrscr();
	for(i=0;i<nos;i++)
	{
	       //	for(i=0;i<4;i++)
		clrscr();
		a=rand();
		printf("Enter the USN number\n");
		scanf("%s",usn);
		rec.open("record.txt",ios::in);
		while(j<count)
		{
			rec.getline(tempusn,80,'|');
			rec.getline(temp,80,'\n');
			if(!strcmp(usn,tempusn))
			{
				for(r=5;r>0;r--)
				{
					clrscr();
					printf("\n\n\n\n\n\t\t\tyour USN number is locked contact the organisers\n");
					printf("\t\t\tPlease wait for %d second(s)",r);
					sleep(1);
				}
				flag=1;
				i--;
			}
			j++;
		}
		rec.close();
		if(flag==0)
		{
			rec.open("record.txt",ios::app);
			printf("Enter a key\n");
			scanf("%d",&key);
			a=a/key;
			clrscr();
			printf("your USN %s is locked and program number assigned is \n",usn);
			b=a%nop;
			rec<<usn<<"|"<<b<<"\n";
			printf("\n\n\t\t\t\t\t%d\n",b);
			count++;
			printf("Press enter to continue\n");
			getch();
			rec.close();
		}
		rec.close();
	}
	getch();

}

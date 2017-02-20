/*MODIFICATION TO PROGRAM PLEASE INCREMENT THE  VERSION BY 0.1 AND CHANGE "LAST MODIFIED BY"*/

/*

VERSION : 1.1
DATE/TIME:18 OCT 2010/4:00AM
PROGRAM NAME: LEAKY BUCKET SIMULATION
PROGRAM DESCRIPTION: LEAKY BUCKET ALGORITHM SIMULATION AND IMPLEMENTATION IN C TO OVERCOME TRAFFIC CONG. IN COMPUTER NETWORK
DATA STRUCTURE USED: CIRCULAR QUEUE
CONVENTION USED FOR NAMING VARIABLES AND FUNCTIONS: CAMEL CASE
LAST MODIFIED BY: NITHIN DEVANG (devangnithin@gmail.com)

*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/*if u r using LINUX replace stdlib with cstdlib*/
#define MAX 20

int Q[MAX];
int F=0,R=-1;
void insert(int N)
{
	R++;
	if(0==R&&0==F)
	{
		;
	}
	else if((R%MAX==F%MAX))
	{
		printf("NON CONFIRMING PACKETS\n");
		R--;
		return;
	}
	R=R%MAX;
	Q[R]=N;
	printf("Packet Confirmed. Content %c %d\n",16,Q[R]);
	return;
}
int deleteQ()
{
	if(R==F)
	{
		printf("Discharged Packet content %c  %d\n",16,Q[F]);
		R=-1;
		F=0;
		return 1;
	}
	if(0==F && -1==R)

	{
		printf("No Packets To Discharge\n");
		return -1;
	}
	printf("Discharged Packet Content %c %d\n",16,Q[F]);
	F++;
	F=F%MAX;
	return 1;
}

void display()
{
	int i;
	if(0==F && -1==R)
	{
		return;
	}
	printf("CONTENTS INSIDE THE BUCKET\n");
	for(i=F;i!=(R+1);i++)
	{
		i=i%MAX;
		printf("%d\n",Q[i]);
	}
	return;
}

int main()
{
	int Option,Turn=1;
	int Value;
	int i;
	int DeleteSuccess;
	int j=0,Yes,NoOfSim;
	int NoOfInsert;
  //	system("clear");
	clrscr();
	printf("Enter The No Of Simulation Rounds\n");
	scanf("%d",&NoOfSim);
    //	system("tput clear");
	clrscr();
	srand(time(NULL));
	NoOfInsert=rand();
	NoOfInsert=NoOfInsert%15;
	for(;;j++)
	{
		Option=Turn;
		srand(time(NULL));
		switch(Option)
		{

			case 1:
				printf("Input Burst Rate %c %d\n",16,NoOfInsert);
				for(i=0;i<50;i++)
					printf("%c",22);
				printf("\n");
				for(i=0;i<NoOfInsert;i++)
				{
				     sleep(1);
				     Value=rand()%11;
				     insert(Value);
				}
				Turn=2;
				display();
				break;
			case 2:
					sleep(1);
					for(i=0;i<5;i++)
					{
						DeleteSuccess=deleteQ();
						if(DeleteSuccess==-1)
						{
							break;
						}
					}
					display();
					Turn=1;
					for(i=0;i<50;i++)
					{
						printf("%c",178);
					}
					printf("\n");
					break;
		}
		if(j==NoOfSim)
		{
			j=0;
			clrscr();
			//system("tput clear");
			printf("%d Simulation Rounds Completed\nDo You Want To Go For Another Round?\n",NoOfSim);
			printf("1-Yes\n2-No\n");
			scanf("%d",&Yes);
			if(Yes==2)
				break;
			clrscr();
			//system("tput clear");
		}
	}
	for(i=5;i>0;i--)
	{

		sleep(1);
		clrscr();
		printf("\n\n\n\n\n\n\n\t\t\t\tTHIS PROGRAM WILL EXIT IN\n");
		printf("\t\t\t\t\t%d SECOND(S)",i);
		printf("\t\t\t\t\t\t\t\t\tPLEASE WAIT\n");
	}
	clrscr();
	//system("tput clear");
	printf("\n\n\n\n\n\n\n\n\t\t\t\tPROGRAM IS TERMINATED\n");
	getch();
	return 0;

}


/*DeVang Innovation Laboratory___Experimenting Thoughts*/
/*NO COPYRIGHT. LEGALLY FREE TO COPY, MODIFY AND REDISTRIBUTE*/
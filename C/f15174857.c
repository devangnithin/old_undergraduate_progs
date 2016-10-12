/* 1. write a c++ program to read series of names, one per line, from standard input and write these names spelled
in reverse order to the standard output using I/O redirection and pipes. Repeat the exercise using an input file specified
 by the user instead of standard input and using an output file specified by the user instead of standard input.*/

 /*
 PROGRAM BY: NITHIN DEVANG:
 DATE AND START TIME: 09 MAY 2010 01:18 AM

 */

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<fstream.h>

class name
{
	char name[11];
	public:
		void standardio();
		void fileio();
		void datafeed(char*);
};

void name::standardio()
{
	clrscr();
	cout<<"THIS FUNCTION WILL READ NAME FROM STANDARD INPUT DEVICE AND WRITE IT TO STANDARD OUTPUT DEVICE"<<endl;
	cout<<"\n\n\t\tENTER THE NAME AFTER THE BEEP OR PROMPT"<<endl;
	sleep(2);
	clrscr();
	cout<<"\n\n\nEnter the name\a\a\a"<<endl;
	cin>>name;
	clrscr();
	cout<<"\n\n\n\t\t\tNAME IN REVERSE ORDER PRESS ENTER TO RETURN"<<endl;
	int len=strlen(name);
	for(int i=len-1;i>=0;i--)
		cout<<name[i];
	getch();
}

void name::fileio()
{
	clrscr();
	cout<<"Enter the filename where data is stored\n\n\a\a\a";
	char filename1[20],filename2[20];
	cin>>filename1;
	clrscr();
	cout<<"Enter the filename where data has to be stored\n\n\a\a\a";
	cin>>filename2;
	clrscr();
	fstream filestream1,filestream2;
	filestream2.open(filename2,ios::out);
	cout<<"is there data in the input file? "<<filename1<<"\nY=Yes\nN=no"<<endl;
	char c[2];
	cin>>c;
	if(!strcmp(c,"N")||!strcmp(c,"n"))
	{
		datafeed(filename1);
	}

	filestream1.close();
	filestream1.open(filename1,ios::in);
	int len;
	while(!filestream1.eof())
	{
		filestream1.getline(name,12,'|');
		len=strlen(name);
		for(int i=len-1;i>=0;i--)
		{
			filestream2<<name[i];
		}
		filestream2<<"|";
	}
	filestream1.close();
	filestream2.close();

	clrscr();
	cout<<"names reversed and copied to the file "<<filename2<<" Successfully"<<endl;
	cout<<"\n\n\nPlease wait......";
	sleep(5);

}

void name::datafeed(char *file)
{
	cout<<"how many names do you want to enter \a\a\a"<<file;
	int n;
	cin>>n;
	fstream filestream1;
	filestream1.open(file,ios::out);
	for(int i=0;i<n;i++)
	{
		clrscr();
		cout<<"Enter name\a\a\a "<<i+1;
		cin>>name;
		filestream1<<name<<"|";
	}
	clrscr();
	cout<<"DATA ENTRY IS DONE PROGRAM WILL STEP BACK IN 5 SECONDS\n\n\a\a\a"<<"please wait";
	sleep(5);
	return;
}


int main(void)
{
	clrscr();
	name n;
	int choice;
	do{
		clrscr();
		cout<<"***************# MENU #***************"<<endl;
		cout<<"     1--->USING STANDARD INPUT AND OUTPUT"<<endl;
		cout<<"               2-->USING FILES"<<endl;
		cin>>choice;

		switch(choice)
		{
			case 1:
				n.standardio();
				break;
			case 2:
				n.fileio();
				break;
		}
	}while(choice<3);

	clrscr();
	cout<<"\n\n\n\n\n\t\t\t\tPROGRAM IS TERMINATED";
	getch();

	return 0;
}


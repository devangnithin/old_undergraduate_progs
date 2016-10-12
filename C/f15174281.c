#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
int count=0;

class record
{
	public:
	char ind[5],name[20],usn[12],branch[10];
};
class index
{
	public:
		char ind[5],usn[12];
};
class secindex
{
	public:
		char ind[5],name[20],usn[12];
};

record rec[10];
index ind[10];
secindex sec[10];

void sortindex()
{
	index temp;
	for(int i=0;i<count-1;i++)
	for(int j=i+1;j<count;j++)
	{
		if(strcmp(ind[i].usn,ind[j].usn)>0)
		{
			temp=ind[i];
			ind[i]=ind[j];
			ind[j]=temp;
		}
	}
}

void sortsecindex()
{
	secindex temp;
	for(int i=0;i<count-1;i++)
	for(int j=i+1;j<count;j++)
	{
		if(strcmp(sec[i].name,sec[j].name)>0)
		{
			temp=sec[i];
			sec[i]=sec[j];
			sec[j]=temp;
		}
		else
		if(strcmp(sec[i].name,sec[j].name)==0)
		{
			if((sec[i].usn,sec[j].usn)>0)
			{
				temp=sec[i];
				sec[i]=sec[j];
				sec[j]=temp;
			}
		}
	}
}



void addrecord()
{
	fstream recfile,secfile,indfile;
	recfile.open("record.txt",ios::app);
	secfile.open("recfile.txt",ios::out);
	indfile.open("index.txt",ios::out);
	cout<<"\nEnter no of students\n";
	int n;
	cin>>n;
	for(int i=count;i<count+n;i++)
	{
		cout<<"Enter details\nname\nusn\nbranch\n";
		cin>>rec[i].name>>rec[i].usn>>rec[i].branch;
		strcpy(sec[i].name,rec[i].name);
		strcpy(sec[i].usn,rec[i].usn);
		strcpy(ind[i].usn,rec[i].usn);
		recfile<<i<<"|"<<rec[i].name<<"|"<<rec[i].usn<<"|"<<rec[i].branch<<"\n";
		secfile<<i<<"|"<<sec[i].name<<"|"<<sec[i].usn<<"\n";
		indfile<<i<<"|"<<ind[i].usn<<"\n";
	}
	recfile.close();
	secfile.close();
	indfile.close();

	count=count+n;
	recfile.open("record.txt",ios::in);
	for(i=0;i<count;i++)
	{
		recfile.getline(rec[i].ind,5,'|');
		recfile.getline(rec[i].name,80,'|');
		recfile.getline(rec[i].usn,80,'|');
		recfile.getline(rec[i].branch,80,'\n');
		strcpy(sec[i].ind,rec[i].ind);
		strcpy(ind[i].ind,rec[i].ind);
	}
	sortindex();
	sortsecindex();
	getch();
}

void main()
{
	int choice;
	do
	{
		clrscr();
		cout<<"\n\n\n\t\t\t\t   MENU\n";
		cout<<"\t\t\t\t";
		for(int i=0;i<10;i++)
			printf("%c",178);
		printf("\n\t\t\t\t  1%cAdd\n\t\t\t\t  2%cSearch\n\t\t\t\t  3%cDelete\n",16,16,16);
		for(i=0;i<40;i++)
			printf("%c%c",5,15);
		cin>>choice;
		switch(choice)
		{
			case 1:
				addrecord();
				break;
			case 3:
				clrscr();
				cout<<"\n\n\n\n\t\t\tPROGRAM IS TERMINATED\n";
				getch();
				exit(0);

			default:
				cout<<"invalid choice\n";
				break;
		}
	}while(choice!=3);
	getch();
}


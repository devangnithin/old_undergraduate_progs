#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<dos.h>
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
			cout<<"YES\n";
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
	recfile.open("record.txt",ios::out);
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
	secfile.open("secfile.txt",ios::out);
	indfile.open("index.txt",ios::out);
	for(i=0;i<count;i++)
	{
		secfile<<sec[i].ind<<"|"<<sec[i].name<<"|"<<sec[i].usn<<"\n";
		indfile<<ind[i].ind<<"|"<<ind[i].usn<<"\n";
	}
	for(i=5;i>0;i--)
	{
		clrscr();
		cout<<"\n\n\n\n\t\t\tProgram will step back in "<<i<<" seconds(s}";
		sleep(1);
	}
}

void search()
{
	cout<<"Enter the name to be searched\n";
	char name[15];
	int k=0,flag=0;
	secindex finder[10];
	cin>>name;
	for(int i=0;i<count;i++)
	{
		if(strcmp(sec[i].name,name)==0)
		{
			finder[k]=sec[i];
			flag=1;
			k++;
		}
	}
	if(!flag)
	{
		cout<<"Record not found\n";
		return;;
	}
	cout<<"Record matching are\n";
	for(i=0;i<k;i++)
	{
	cout<<finder[i].name<<"  "<<finder[i].usn<<"\n";
	}

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
			case 2:
				search();
				break;
			case 4:
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


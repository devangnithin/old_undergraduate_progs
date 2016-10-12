#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
class node
{
	public:
	char name[10],usn[20];
	node *link;
};

node *first=NULL;

void writefile()
{
	node *p;
	char buf[100];
	fstream out;
	out.open("stud.txt",ios::out);
	p=first;
	while(p!=NULL)
	{
		strcpy(buf,p->name);
		strcat(buf,"|");
		strcat(buf,p->usn);
		strcat(buf,"\n");
		out<<buf;
		p=p->link;
	}
}

void insert()
{
	char name[20],usn[20];
	node *p,*q;
	p=new node;
	cout<<"Enter name\n";
	cin>>p->name;
	cout<<"Enter the usn\n";
	cin>>p->usn;
	p->link=NULL;
	if(first==NULL)
		first=p;

	else
	{
		for(q=first;q->link!=NULL;q=q->link);
			q->link=p;
	}
	writefile();
}


void delet()
{
}

int main()
{
	clrscr();
	int ch;
	do
	{
		cout<<"Enter your choice from the menu\n";
		cout<<"\t\t\t\tMENU\n";
		int dumb=178;
		cout<<"\t\t\t";
		for(int i=0;i<20;i++)
			printf("%c",dumb);

		dumb=16;
		printf("\n\t\t\t\t1%cInsert\n\t\t\t\t2%cDelete\n\t\t\t\t2%cExit\n",dumb,dumb,dumb);
		cin>>ch;
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				delet();
				break;
		}
	}while(ch<3);
	getch();
	return 0;
}



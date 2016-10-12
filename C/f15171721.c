#include<stdio.h>
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>
#include<fcntl.h>
#include<conio.h>


int count;
char curfile[]={"hello.dvng"};

class variable
{
	struct student
	{
		char rrn[3],usn[12],name[20],sem[5],dept[20];
	};
	public:
	void pack();
	void unpack();
	void search();
};

void variable::pack()
{
	count++;
	char buffer[100];
	student s;
	clrscr();

	cout<<"USN"<<endl;
	cin>>s.usn;
	cout<<"name"<<endl;
	cin>>s.name;
	cout<<"sem\n";
	cin>>s.sem;
	cout<<"dept\n";
	cin>>s.dept;

	fstream ofile;
	ofile.open("count.dvng",ios::out);
    //	seekp(0L,ios::beg);
	char str[3];
	itoa(count,str,10);
	strcpy(buffer,str);
	ofile<<buffer;
	ofile<<"\n";
	ofile.close();

       //	seekp(0,ios::end);
	itoa(count,str,10);
	strcpy(buffer,str);
	strcat(buffer,"|");
	strcat(buffer,s.usn);
	strcat(buffer,"|");
	strcat(buffer,s.name);
	strcat(buffer,"|");
	strcat(buffer,s.sem);
	strcat(buffer,"|");
	strcat(buffer,s.dept);
	strcat(buffer,"$");
	ofile.open(curfile,ios::app);
	ofile<<buffer;
	clrscr();
	cout<<"\n\n\n\n\n\n\n\t\t\tone record successfully added @ rrn position = "<<count;
	getch();
	ofile.close();
}

void variable::unpack()
{
       //	cout<<"Debug line1"<<endl;
       clrscr();
	char temp[5],len[5];
	student s;
	ifstream ifile;
	ifile.open(curfile,ios::in);
	int n=1;
	if(count==0)
		{
			clrscr();
			cout<<"\n\n\n\n\n\n\n\t\t\t\t\tno records\n";
			goto unp;
		}
	    //	cout<<"debug line 2"<<endl;
	while(n<=count)
	{
		//ifile.getline(len,5,' ');
		//cout<<"debug line 3"<<endl;

		ifile.getline(s.rrn,80,'|');
		ifile.getline(s.usn,80,'|');
		ifile.getline(s.name,80,'|');
		ifile.getline(s.sem,80,'|');
		ifile.getline(s.dept,80,'$');
		cout<<"\nRecord"<<n<<":\n"<<s.rrn<<endl;
	       //	cout<<"Debug line 4"<<endl;
		cout<<s.usn<<"\t"<<s.name<<"\t"<<s.sem<<"\t"<<s.dept;
	       //	cout<<"debug line 5"<<endl;
		n++;
	}
	unp:
	ifile.close();
}
void variable::search()
{
	clrscr();
	char temp[5],rrn[3],len[5];
	student s;
	int flag=0,n=1;
	fstream fff;
	fff.open(curfile,ios::in);
	cout<<"Enter rrn of d record\n";
	cin>>rrn;
	while(n<=count)
	{
		fff.getline(s.rrn,80,'|');
		fff.getline(s.usn,80,'|');
		fff.getline(s.name,80,'|');
		fff.getline(s.sem,80,'|');
		fff.getline(s.dept,80,'$');
		if(!strcmp(rrn,s.rrn))
		{
			cout<<"Record found\ncontents are\n";
			cout<<"\nRecord"<<n<<":\n"<<s.rrn<<endl;
			cout<<"usn"<<"\t"<<"name"<<"\t"<<"sem"<<"\t"<<"dept"<<endl;
			cout<<s.usn<<"\t"<<s.name<<"\t"<<s.sem<<"\t"<<s.dept;
			flag=1;
			return;
		}
		n++;
	}
	if(flag!=1)
		clrscr();
		cout<<"\n\n\n\n\n\n\n\t\t\t\t\tRecord not found\n";
		fff.close();
}



int main()
{
	variable v;
	fstream fileh;
	clrscr();
	fileh.open("count.dvng",ios::in);
	char str[3];
	fileh.getline(str,'\n');
	fileh.close();
	count=atoi(str);
	int ch;
	again: clrscr();
	cout<<"Enter your choice:\n1.pack\n2.unpack\n3.search\n4.reset\nany key to exit\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			v.pack();
			break;
		case 2:
			v.unpack();
			getch();
			break;
		case 3:
			v.search();
			getch();
			break;
		case 4:
			fileh.open("count.dvng",ios::out);
			fileh.close();
			fileh.open(curfile,ios::out);
			fileh.close();
			count=0;
			clrscr();
			cout<<"\n\n\n\n\n\n\n\n\t\tRecord completely erased from the file system";
			getch();
			break;

		default:
		       goto exitc;
	}
	goto again;
	exitc:
	clrscr();
	cout<<"\n\n\n\n\n\n\t\t\t\tProgram is terminated\n\n\t\t\t\tPress any key to exit";
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tProgram By: Dvng";
	getch();
	return 0;
}




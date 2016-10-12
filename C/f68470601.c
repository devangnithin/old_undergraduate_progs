/*
P5
PROGRAM BY: NITHIN DEVANG
START TIME: 03 MAY 2010 10:29:48 PM
FINISH TIME:04 MAY 2010 05:00 AM
EXACT COMPLETION OF 1 V:04 MAY 2010 08:08 AM
ALPHA VERSION
*/
#include<iostream>
//#include<conio.h>
//#include<process.h>
#include<fstream>
#include<stdlib.h>
#include<string>
//#include<dos.h>
//#include<stdio.h>
using namespace std;
class cou
{
    public:
    int count;
    cou()
    {
        count=0;
    }
};
class index
{
	public:
	char usni[20];
	char number[20];
};

class student
{
	char usn[20],number[20],name[20],age[20],sem[20];
	public:
	void addrecord();
	void searchindex();
	void deleterecord();
};
cou cou;

void student::addrecord()
{
	int i,j;
	index ind,indtemp,indarray[50];
	student stu;
	cout<<"Enter the usn to be added\n";
	cin>>stu.usn;
	fstream file1,file2;
	file1.open("student.dvng",ios::app);
	file2.open("index.dvng",ios::in);
	for(i=1;i<=cou.count;i++)
	{       file2.getline(indtemp.usni,80,'|');
		file2.getline(indtemp.number,80,'\n');
		if(!strcmp(stu.usn,indtemp.usni))
		{
			for(i=0;i<3;i++)
			{
//				clrscr();
				cout<<"\n\n\n\nDUPLICATE USN TRIED\a\a\a"<<endl;
//				sleep(1);
			}
			return;
		}
       }
       file2.close();
       cout<<"NAME\a\a\a"<<endl;
       cin>>stu.name;
       cout<<"AGE\a\a\a"<<endl;
       cin>>stu.age;
       cout<<"SEM\a\a\a"<<endl;
       cin>>stu.sem;

       file2.open("index.dvng",ios::in);

       for(i=1;i<=cou.count;i++)
       {
		file2.getline(indarray[i].usni,80,'|');

		file2.getline(indarray[i].number,80,'\n');

       }
       cou.count++;
       strcpy(indarray[cou.count].usni,stu.usn);
	char rr[2];
       itoa(cou.count,rr,10);
       strcpy(indarray[cou.count].number,rr);

       for(i=1;i<cou.count;i++)
       {
		for(j=i+1;j<=cou.count;j++)
		{
			if(strcmp(indarray[i].usni,indarray[j].usni)>0)
			{
				strcpy(indtemp.usni,indarray[i].usni);
				strcpy(indtemp.number,indarray[i].number);

				strcpy(indarray[i].usni,indarray[j].usni);
				strcpy(indarray[i].number,indarray[j].number);

				strcpy(indarray[j].usni,indtemp.usni);
				strcpy(indarray[j].number,indtemp.number);
			}
		}
       }
	file2.close();
	file2.open("index.dvng",ios::out);

       for(i=1;i<=cou.count;i++)
       {
		file2<<indarray[i].usni<<"|"<<indarray[i].number<<"\n";
	}



	//file2<<stu.usn<<"|"<<count<<"\n";
	file1<<cou.count<<"|"<<stu.usn<<"|"<<stu.name<<"|"<<stu.age<<"|"<<stu.sem<<"\n";

	file1.close();
	file2.close();
//	getch();
}
void student::searchindex()
{
	index ind,tempind;
	student stu,stutemp;
	cout<<"Enter the usn to be searched"<<endl;
	cin>>ind.usni;
	int i;
	fstream file1,file2;
	file1.open("student.dvng",ios::in);
	file2.open("index.dvng",ios::in);
	while(!file2.eof())
	{
		file2.getline(tempind.usni,80,'|');
		file2.getline(tempind.number,80,'\n');
		if(!strcmp(ind.usni,tempind.usni))
		{
			for(;atoi(stutemp.number)!=atoi(tempind.number);)
			{
				file1.getline(stutemp.number,80,'|');
				file1.getline(stutemp.usn,80,'|');
				file1.getline(stutemp.name,80,'|');
				file1.getline(stutemp.age,80,'|');
				file1.getline(stutemp.sem,80,'\n');
			}
			cout<<"NAME\tAGE\tSEM\n";
			cout<<stutemp.name<<"\t"<<stutemp.age<<"\t"<<stutemp.age<<endl;
//			getch();
		    //	return;
		}
	}
//	getch();
	file1.close();
	file2.close();
}

void student::deleterecord()
{
	cout<<"Enter the usn to be deleted"<<endl;
	char usn[20];
	cin>>usn;
	student s;
	char tempi;
	index i,i2;
	fstream file1,file2;
	int w=1,flag=-1;
/*	file1.open("student.dvng",ios::in|ios::app);
	file2.open("index.dvng",ios::in|ios::app);
	while(!file2.eof())
	{
		long a=file2.tellg();
		cout<<"TELL G "<<a;
		cout<<"PUT "<<file2.tellp();
		file2.getline(i.usni,80,'|');
		file2.getline(i.number,80,'\n');
		if(!strcmp(usn,i.usni));
		{
			file2. seekp(a);

			file2.seekg(a);
			file2.getline(i2.usni,1,'$');
			while(strcmp(i2.usni,"|"))
			{
				file2.getline(i2.usni,1,'$');
				file2<<"*";
			}
			while(strcmp(i2.number,"\n"))
			{
				file2.getline(i2.number,1,'$');
				file2<<"*";
			}
		}
	}*/
	file1.open("student.dvng",ios::in);
	file2.open("index.dvng",ios::in);
	fstream tempindex,tempstudent;
	tempindex.open("temp1.dvng",ios::out);
	tempstudent.open("temp2.dvng",ios::out);
	int p=1;
	while(p<cou.count)
	{
		file2.getline(i.usni,80,'|');
		file2.getline(i.number,80,'\n');
		file1.getline(s.number,80,'|');
		file1.getline(s.usn,80,'|');
		file1.getline(s.name,80,'|');
		file1.getline(s.age,80,'|');
		file1.getline(s.sem,80,'\n');
		if(strcmp(i.usni,usn))
		{
			tempindex<<i.usni<<"|"<<w<<"\n";
			tempstudent<<w<<"|"<<s.usn<<"|"<<s.name<<"|"<<s.age<<"|"<<s.sem<<"\n";
			w++;
		}
		else
		{
			flag=0;
			cout<<"RECORD DELETED\n";
		}
		p++;
	}
	cou.count=w;
	file1.close();
	file2.close();
	if(flag==0)
	{
		cou.count--;
	}
	else
	{
		cout<<"record not found\n";
	}
	tempindex.close();
	tempstudent.close();
	file1.open("student.dvng",ios::out);
	file2.open("index.dvng",ios::out);
	tempindex.open("temp1.dvng",ios::in);
	tempstudent.open("temp2.dvng",ios::in);
	char hello[400];
	p=1;
	while(!tempindex.eof())
	{
		tempindex>>hello;
		file2<<hello<<"\n";
		p++;
	}
	p=1;
	while(!tempstudent.eof())
	{
		tempstudent>>hello;
		file1<<hello<<"\n";
		p++;
	}
		file1.close();
		file2.close();
		tempindex.close();
		tempstudent.close();
	//getch();
}
int main()
{

	fstream countfile;
	countfile.open("count.dvng",ios::in);
	char countarray[5];
	countfile.getline(countarray,5,'\n');
	countfile.close();
	cou.count=atoi(countarray);
	//clrscr();
	student s;
	int choice;
	do
	{
//		clrscr();
		cout<<"1---->ADD RECORD\n 2---->SEARCH INDEX\n3---->DISPLAY INDEX\n4---->DELETE RECORD\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				s.addrecord();
				break;
			case 2:
				s.searchindex();
				break;
			case 3:
				fstream file;
				file.open("index.dvng",ios::in);
				char recorder[100];
				cout<<"USN|INDEX"<<endl;
				while(!file.eof())
				{
					file.getline(recorder,100,'\n');
					cout<<recorder<<endl;
				}
				file.close();
//				getch();
				break;
			//case 4:
				//s.deleterecord();
				//break;
			}
	}while(choice<5);
	countfile.open("count.dvng",ios::out);
	countfile<<cou.count<<"\n";
	countfile.close();
	//getch();
	return 0;
}

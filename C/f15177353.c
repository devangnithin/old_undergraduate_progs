/*
P5
PROGRAM BY: NITHIN DEVANG
START TIME: 03 MAY 2010 10:29:48 PM
ALPHA VERSION
*/
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
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
	void pack(int);
};

int count=0;
char arrow=17,strip1=176,strip2=178,buffer[64];
index indarray[50];

void updateindex()
{
		fstream file2;
		file2.open("index.dvng",ios::out);
		file2<<count<<"\n";
		for(int i=1;i<=count;i++)
		{
			file2<<indarray[i].usni<<"|"<<indarray[i].number<<"\n";
		}

}

void readindex()
{
	fstream file2;
	file2.open("index.dvn",ios::in);
	char countarray[5];
	file2.getline(countarray,5,'\n');
	count=atoi(countarray);
	for(int i=1;i<=count;i++)
	{
		file2.getline(indarray[i].usni,80,'|');
		file2.getline(indarray[i].number,80,'\n');
	}

}
int binarysearch(char* usn)
{
	int low=1,high=count,mid,rrn,x;
	while(low<=high)
	{
		mid=(high+low)/2;
		x=strcmp(usn,indarray[mid].usni);
		if(x==0)
		{
			rrn=atoi(indarray[mid].number);
			return rrn;
		}
		else
		if(x<0)
		{
			high=mid-1;
		}
		else
			low=mid+1;
	}
	return -1;

}
void student::pack(int pc)
{
	char tempcount[2];
       itoa(pc,tempcount,10);
       strcpy(buffer,tempcount);
       strcat(buffer,"|");
       strcat(buffer,usn);
       strcat(buffer,"|");
       strcat(buffer,name);
       strcat(buffer,"|");
       strcat(buffer,age);
       strcat(buffer,"|");
       strcat(buffer,sem);
       int strlength=strlen(buffer);
       for(int i=0;i<59-strlength;i++)
       strcat(buffer,"~");
       strcat(buffer,"\n");
}


void student::addrecord()
{
	int i,j,dupflag;
	index ind;
	student stu;
	cout<<"Enter the usn to be added\n";
	cin>>usn;
	fstream file1,file2;
	file1.open("student.dvn",ios::app);
	dupflag=binarysearch(usn);
	if(dupflag!=-1)
	{
		for(i=0;i<3;i++)
		{
			clrscr();
			cout<<"\n\n\n\nDUPLICATE USN TRIED\a\a\a"<<endl;
			cout<<"please wait for "<<i<<"second(s)";
			sleep(1);
		}
			return;
       }

       cout<<"NAME\a\a\a"<<endl;
       cin>>name;
       cout<<"AGE\a\a\a"<<endl;
       cin>>age;
       cout<<"SEM\a\a\a"<<endl;
       cin>>sem;
       count++;
       strcpy(indarray[count].usni,usn);
       char rr[2];
       itoa(count,rr,10);
       strcpy(indarray[count].number,rr);

       for(i=1;i<count;i++)
       {
		for(j=i+1;j<=count;j++)
		{
			if(strcmp(indarray[i].usni,indarray[j].usni)>0)
			{
				ind=indarray[i];
				indarray[i]=indarray[j];
				indarray[j]=ind;

			}
		}
       }
       this->pack(count);
       file2.open("student.dvn",ios::app);
       file1<<buffer;
	file1.close();
	getch();
}
void student::searchindex()
{
	index ind;
	int rrn;
	if(count==0)
	{
		cout<<"NO RECORDS TO SEARCH";
		sleep(2);
		return;
	}
	cout<<"Enter the usn to be searched"<<endl;
	cin>>ind.usni;
	int i;
	rrn=binarysearch(ind.usni);
	if(rrn==-1)
	{

		clrscr();
		cout<<"Record not found\nPress enter to return";
		getch();
		return;
	}
	rrn--;
	cout<<"record found\n";
	fstream file1;
	file1.open("student.dvn",ios::in);
	file1.seekg(61*rrn,ios::beg);
	file1.getline(usn,20,'|');
	file1.getline(number,20,'|');
	file1.getline(name,20,'|');
	file1.getline(age,20,'|');
	file1.getline(sem,20,'~');
	cout<<"usn"<<arrow<<usn<<endl;
	cout<<"name"<<arrow<<name<<endl;
	cout<<"age"<<arrow<<age<<endl;
	cout<<"sem"<<arrow<<sem<<endl;
	file1.close();
	getch();
}

void student::deleterecord()
//NOT WORKING PROPERLY LOGICALLY... PLEASE CORRECT
{
	cout<<"Enter the usn to be deleted"<<endl;
	char usn[20];
	int i=0;
	cin>>usn;
	student stu[20];
	fstream file1;
	int pos;
	file1.open("student.dvn",ios::in);
	pos=binarysearch(usn);
	if(pos==-1)
	{
		cout<<"Record not found....Please Press Enter";
		getch();
		return;
	}
	file1.close();
	file1.open("student.dvn",ios::app);
	file1.seekg(pos*61,ios::beg);
	for(i=1;i<=count;i++)
	{
		file1.getline(stu[i].usn,20,'|');
		file1.getline(stu[i].number,20,'|');
		file1.getline(stu[i].name,20,'|');
		file1.getline(stu[i].age,20,'|');
		file1.getline(stu[i].sem,20,'~');
		file1.getline(buffer,60,'\n');

	}
	file1.seekg(pos*61,ios::beg);
	int temppos=pos;
	for(i=2;i<=count;i++)
	{
		stu[i].pack(temppos);
		temppos++;
		file1<<buffer;
	}
	char temper[2];
	int delflag=0;
	itoa(pos,temper,10);

	//FOR INDEX

	for(i=1;i<=count;i++)
	{
		if(!strcmp(indarray[i].number,temper))
		{
			delflag=1;
		}
		if(delflag)
		{
			strcpy(indarray[i].usni,indarray[i+1].usni);
		}
	}
}

void main()
{
	fstream record;
	readindex();
	clrscr();
	student s;
	int choice;
	do
	{
		clrscr();
		for(int i=0;i<10;i++)
		{
			cout<<endl;
		}
		cout<<"\t\t\t   MENU\n";
		cout<<"\t\t\t";
		for(i=0;i<10;i++)
			cout<<strip2;
		cout<<"\n\t\t\t1 "<<arrow<<" ADD RECORD\n\t\t\t2 "<<arrow<<" SEARCH INDEX\n\t\t\t3 "<<arrow<<" DISPLAY INDEX\n\t\t\t4 "<<arrow<<" DELETE RECORD\n";
		cout<<"\t\t";
		for(i=0;i<33;i++)
		cout<<strip1;
		cout<<endl;
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
				getch();
				break;
			case 4:

				s.deleterecord();
				break;
			}
	}while(choice<5);
	updateindex();
	getch();
}

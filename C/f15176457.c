#include <iostream.h>
#include<process.h>
#include <fstream.h>
#include <conio.h>
#include <string.h>

struct buffer
{
	char buf1[20],buf2[20];
};
void clear(char * buffer)
{
	int i;
	for(i=0;i<20;i++)
		buffer[i]='\n';
}
void fileMerge(char *f1,char *f2,char *f3)
{
	struct buffer s;
	int x=1,y=1,i;
	ifstream file1(f1);
	ifstream file2(f2);
	ofstream file3(f3);
	clear(s.buf1);
	clear(s.buf2);
	file1.getline(s.buf1,20,'|');
	if(!file1.good())
	{
		x=0;
	}

	file2.getline(s.buf2,20,'|');
	if(!file2.good())
	{
		y=0;
	}
	while(x!=0 && y!=0)
	{
		if(strcmp(s.buf1,s.buf2)==0)
		{
			file3<<s.buf1;
			file3<<"|";
			clear(s.buf1);
			file3<<s.buf2;
			file3<<"|";
			clear(s.buf2);
			file1.getline(s.buf1,20,'|');
			if(!file1.good())
			{
				x=0;
			}
			file2.getline(s.buf2,20,'|');
			if(!file2.good())
			{
				y=0;
			}
		}


		else if(strcmp(s.buf1,s.buf2)<0)
		{
			file3<<s.buf1;
			file3<<"|";
			clear(s.buf1);
			file1.getline(s.buf1,20,'|');
			if(!file1.good())
			{
				x=0;
			}

		}

		else if(strcmp(s.buf1,s.buf2)>0)
		{
			file3<<s.buf2;
			file3<<"|";
			clear(s.buf2);
			file2.getline(s.buf2,20,'|');
			if(!file2.good())
			{
				y=0;
			}
		}

	}
	while(x==0 && y!=0)
	{
		file3<<s.buf2;
		file3<<"|";
		clear(s.buf2);
		file2.getline(s.buf2,20,'|');
		if(!file2.good())
			{
				y=0;
			}
	}
	while(y==0 && x!=0)
	{
		file3<<s.buf1;
		file3<<"|";
		clear(s.buf1);
		file1.getline(s.buf1,20,'|');
			if(!file1.good())
			{
				x=0;
			}
	}

	file1.close();
	file2.close();
	file3.close();
}

void getList(char *f1)
{
	ofstream file(f1);
	cout<<"\nEnter the number of names: ";
	int n,i=0,z;
	char buf[20];
	cin>>n;
	while(i<n)
	{
		clear(buf);
		cout<<"\nEnter name"<<i+1<<"\n"<<flush;
		cin>>buf;
		file<<buf;
		file<<"|";
		i++;
	}
	file.close();
}

void main()
{
	clrscr();
	char list[10][10];
	char list1[4][10];
	char list2[2][10];
	char output[10];
	int i,j;
	for(i=0;i<8; i++)
	{
		cout<<"\nEnter the "<<i+1<<" file name:"<<flush;
		cin>>list[i];
		cout<<endl;
		getList(list[i]);

	}
	i=0;j=1;
	for(int l=0; l<4; l++)
	{
			cout<<"\nEnter the first level outputfile name "<<l+1<<endl<<flush;
			cin>>list1[l];
			fileMerge(list[i],list[j],list1[l]);
			i=i+2;
			j=j+2;
	}
	i=0;j=1;
	for(l=0;l<2;l++)
	{
			cout<<"\nEnter the second level outputfile name "<<l+1<<endl<<flush;
			cin>>list2[l];
			fileMerge(list1[i],list1[j],list2[l]);
			i=i+2;j=j+2;
	}
	cout<<"\nEnter the name of the main output file: ";
	cin>>output;
	fileMerge(list2[0],list2[1],output);

	getch();
}

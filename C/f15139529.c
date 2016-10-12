#include<stdlib.h>
#include<time.h>
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
//using namespace std;

int main()
{clrscr();
 char str[4];
ofstream file("ny.txt") ;
    srand((unsigned)time(0));
    int random_integer;
    for(int index=0; index<8; index++){
	random_integer = (rand()%1024)+1;
	itoa(random_integer,str,2);
	for(int j=0;j<8;j++)
	file<<str[j]<<"\t";
	file<<endl;

    } getch();
}

void tryin()
{
	FILE fp=fopen(file1,"r");
	FILE fp2,fp3;
	while(fp!=eof)
	{
		for(int i=1;i<=25;i++)
		{
			fseek(fp2,2,ios::cur);
			char ch,dh;
			fread(&ch,sizeof(char),1,fp);
			if(ch==i+65)
			{
				fseek(fp,3,ios::cur);
				fread(&dh,sizeof(char),1,fp);
				for(j=i+1;j<=26;j++)
				{
					fseek(fp3,2,ios::cur);
					for(k=1;k<=8;k++)
					{
						int c,d;
						fread(&c,sizeof(int),1,fp2);
						fread(&d,sizeof(int),1,fp3);
						if(c && d)
						count++;
						fseek(fp2,54,ios::cur);
						fseek(fp3,54,ios::cur);
					}
					if(counter<Threshold)
					{
						sfile<<i+64<<j+64<<counter;
					}
					else
					{
						bfile<<i+64<<j+64<<counter;
					}
				}
			}
		}
	}
}

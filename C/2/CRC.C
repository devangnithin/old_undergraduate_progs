#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
char x[10],temp[10];
int m,n,i,k,len;
void xor(char a[10],char t[10],int m)
{
	int i,j;

	if(t[0]=='0')
	{
		for(i=0;i<m;i++)
		t[i]=t[i];
	}
	else
	{

		for(i=0;i<m;i++)
		t[i]=((a[i]==t[i])?'0':'1');
	}

	strcpy(x,t);


	printf("%s",x);
}


void divide(char a[10],char b[10])
{
	char c[10];
	int j;
	for(i=0;i<=9;i++)
	c[i]=0;


       j=0;

	m=strlen(a);
	n=strlen(b);
	len=n-m;


	for(i=0;i<m;i++)
	c[i]=b[i];
	j=m;

	printf("\nthe remainder is:");

	xor(a,c,m);
	for(k=0;k<len;k++)
	{
		for(i=0;i<len;i++)
		{
			x[i]=x[i+1];
		}

		x[len]=b[j++];

		printf("\nthe remainder is:");
		xor(a,x,m);
	}
}
void gen(char b[10])
{
	int j;
	j=0;
	for(i=0;i<len;i++)
	{
		temp[j++]='0';
	}
	for(i=0;i<m;i++)
	{
		temp[j++]=x[i];
	}
printf("\nthe codeword is:");
xor(temp,b,n);
}

int main()
{
	char a[10],c[10],b[10];
	int pos,flag;
	clrscr();
	printf("Enter divisor and dividend\n");
	scanf("%s%s",a,b);


	divide(a,b);
	gen(b);


	printf("\nenter the position where error shud b inserted\n");
	scanf("%d",&pos);
	for(i=0;i<strlen(x);i++)
	{
	if(i==pos)
	{
	x[i]=(x[i]=='0'?'1':'0');
	break;
	}
	}
	printf("\nafter inserting error:%s",x);
	strcpy(c,x);
	divide(a,c);
	i=0;
	while(i<strlen(x))
	{
	if(x[i++]=='1')
	flag=1;
	}
	if(flag==1)
	printf("\nerror");
	else
	printf("\n no error");
	getch();
}



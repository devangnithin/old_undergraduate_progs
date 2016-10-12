#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();
	char a[3];
	cin>>a;
	cout<<"a#>"<<a<<"a[0]>"<<a[0]<<"a[1]>"<<a[1]<<"a[3]>"<<a[3]<<"\n";
	char b;
	b=a[0];
	cout<<"B# "<<b;
	cout<<"--------------------";
	cout<<"dis"<<*a;
	cout<<"   ";
//	cout<<*a[0];
	cout<<"    ";
    //	cout<<*a[1];
	cout<<"    ";
     //	cout<<*a[2];
	cout<<"     ";
     //	cout<<*a[3];
	getch();

}

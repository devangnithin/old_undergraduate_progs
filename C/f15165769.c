/*

VERSION: ALPHA

SUBVERSION: 0.1;

LAST UPDATE BY: NITHIN DEVANG;

ORDER OF UPDATE WITH DATE :
	1.NITHIN DEVANG <16 JULY 2010>
	2.

LAST UPDATE DATE AND TIME:


*/
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include"addproduct.cpp"
#include"purchase.cpp"

/*void initialize()
{

} */

void main()
{
	clrscr();

	purchase p;
	cout<<"\n\n\n\n\t\t\tDo you want to enter more products?";
	char arr=17;
	cout<<endl<<"\t\t\t\t"<<1<<arr<<" Yes"<<endl<<"\t\t\t\t"<<2<<arr<<" No"<<endl;

	cout<<"\t\t\t";
	arr=178;
	for(int i=0;i<35;i++)
	{
		cout<<arr;
	}
	cout<<endl;

	int ch;
	cin>>ch;
	if(ch==1)
	{
		p.addproduct();
	}
	getch();
}
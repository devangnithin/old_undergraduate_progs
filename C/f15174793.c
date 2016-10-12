/* file(s} used
	1.product.pho

	*/
#include"purchase.cpp"
#include<fstream.h>
#include<dos.h>
#include<conio.h>
#include<string.h>

char buffer[40];
void purchase::addproduct()
{
	fstream product;
	product.open("product.pho",ios::in);

	/*if(!product)
	{
		for(int i=5;i>0;i--)
		{
			clrscr();
			cout<<"Error!\n contact the system admin\n";
			cout<<"System will step back in "<<i<<" seconds(s)";
			sleep(1);
		}
		clrscr();
		return;
	} */


	char al[1];
	product.getline(al,1,'\n');

	cout<<"Debug line 1 \nal="<<al<<endl;
	ap=al[0];
	cout<<"Debug line 2 \nap="<<ap<<endl;

	if(ap=='\0')
	{
		ap='a';
		cout<<"DEBUG LINE 3 "<<ap;
	}

	if((ap=='z')&&(ap=='Z'))
	{
		clrscr();
		cout<<"Maximum limit reached\ncontact system designers";
			for(int i=5;i>0;i--)
		{
			clrscr();
			cout<<"Error!\n contact the system admin\n";
			cout<<"System will step back in "<<i<<" seconds(s)";
			sleep(1);
		}
		clrscr();
		return;
	}

	product.close();

	product.open("product.pho",ios::app);

	if(!ap=='a')
	{
		ap=++ap;
	}
	cout<<"Enter product name"<<endl;
	char proname[10];
	cin>>proname;

 //	char arr=179;

	product.seekp(0,ios::beg);
	product<<ap<<endl;

	product.seekp(0,ios::end);

	product<<proname<<"|"<<ap<<endl;
	product.close();
	for(int i=3;i>0;i--)
	{
		clrscr();
		cout<<"Product successfilly added"<<endl;
		cout<<"will step back in "<<i<<" seconds(s)";
		sleep(1);
	}
	clrscr();
	return;

}

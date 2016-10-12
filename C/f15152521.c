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

	if(!product);
	/*{
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

	char bp[3];
	product. getline(bp,2,'\n');

	cout<<"Debug line 1 \nbp="<<bp[0]<<endl;
	ap=bp[0];
	cout<<"Debug line 2 \nap="<<ap<<endl;

	/*if(ap=='\0')
	{
		ap='a';
		cout<<"DEBUG LINE 3 "<<ap;
	}
	  */
	if((ap=='z')||(ap=='Z'))
	{
		clrscr();
		for(int i=5;i>0;i--)
		{
			clrscr();
			cout<<"Maximum limit reached\ncontact system designers";
			cout<<"System will step back in "<<i<<" seconds(s)";
			sleep(1);
		}
		clrscr();
		return;
	}
	--ap;

	product.close();

	product.open("product.pho",ios::app);


		ap=++ap;
		cout<<"Debug line 4  >  "<<ap;
		getch();

	cout<<"Enter product name"<<endl;
	char proname[10];
	cin>>proname;

 //	char arr=179;

	product.seekp(0,ios::beg);
	cout<<"DEBUG LINE 4  >  "<<product.tellp();
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

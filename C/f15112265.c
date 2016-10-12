#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
class name
{
	public:
		char name[11];
};

ostream& operator <<(ostream& show,name nami)
{
	int l;
	l=strlen(nami.name);
	for(int i=l;i>0;i--);
	show<<nami.name[i];
	return show;
}



int main()
{
	name nam;

	clrscr();

	cout<<"Enter the name\n";
	cin>>nam.name;
	cout<<"Enter the choice\n1 > Using Standard IO\n2 > Using Files";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<nam;
			break;
		case 2:
			fstream file;
			file.open("student.dvn",ios::out);
			file<<nam;
			break;
	}
	clrscr();
	cout<<"THANK YOU";

	getch();
	return 0;
}

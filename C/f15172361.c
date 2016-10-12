#include<iostream.h>
#include<dos.h>
int main()
{
       //	int i,j;
	for(int i=0;i<10;i++)
	{
	cout<<"Beep \a\a"<<i+1<<endl;
	sleep(1);
	}

	return 0;
}
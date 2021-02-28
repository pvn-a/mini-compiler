#include<iostream.h>

int check(int,int);

int check(int a, int b)
{
	int x = 10;
	int y = 30;
	int z = 10+x+y;
	cout<<"Value of z is"<<z;
}

int main()
{
	int a=12;
	a=15;
	{
		a=18;
	}
	//check(a);
	return 0;
}

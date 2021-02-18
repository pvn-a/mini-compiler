#include<iostream.h>

int main()
{
	int a = 5;
	cout<<"The value of a is "<<a;
	cin>>a;
	float b;
	char c;
	cin>>b>>c;
	int x; 
	int y = 7; int z = 8;
	x = y+z; int final;
	if(x > y)
	{
		if(x > z)
		{
			cout<<"x is the greatest";
			final = x;
		}
	}
	else
	{
		if(y > z)
		{
			cout<<"y is the greatest";
			final = y;
		}
	}
	return 0;	
}

	#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class xyz
{
	public:
		int a;
		int b;
		float c;
		
		simple()
		{
			cout<<"constructor called";
		}
		
		simple(int x, int y=0, float z=0.0)
		{
			a=x;
			b=y;
			c=z;
			cout<<"\n constructor called, initialisation done";
		}
};

int main()
{
	simple *z=new simple;
	simple x;
	simple t(100);
	z->values();
	t.values();
	delete z;
	
	cout<<"last";
	
	return 0;
}

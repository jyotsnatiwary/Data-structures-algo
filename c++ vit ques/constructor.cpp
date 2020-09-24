#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class xyz
{
	public:
		int x;
		xyz()
		{
			cout<<"\n Constructor called";
		}
		~xyz()
		{
			cout<<"\n Destructor called";
		}
};

int main()
{
	xyz obj1;
	obj1.x=100;
	cout<<"\n the value of x="<<obj1.x;
	
	xyz *obj2= new xyz;
	//xyz *obj2;
	obj2->x=200;
	cout<<"\n the value of x="<<obj2->x;
	
	delete obj2;
	
	xyz *obj3;
	obj3=&obj1;
	cout<<"\n the value of x="<<obj3->x;
	
	
}

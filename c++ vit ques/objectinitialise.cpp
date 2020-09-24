#include<iostream>
#include<stdio.h>
using namespace std;

class student
{
	public:
		char name[10];
		int regno;
};		 

int main()
{
	student s1={"xyz",1000};
	student s2;
	
	cout<<"\n name:"<<s1.name;
	cout<<"\n regno:"<<s1.regno;
	
	return 0;
}

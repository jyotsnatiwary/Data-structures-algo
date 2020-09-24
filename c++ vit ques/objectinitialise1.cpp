#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class student
{
	public:
		char name[10];
		int regno;
		
		//void init()
		student()
		{
			regno=100;
			strcpy(name,"abc");
			cout<<"object initialised";
		}
		student(int r,char n[10])
		{
			regno=r;
			strcpy(name,n);
			cout<<"object initialised";
		}
		student(student *s)
		{
			regno=s->regno;
			strcpy(name,s->name);
			cout<<"object initialised";
		}
};		 

int main()
{
	student s1;
	//s1.init();
	student s2(100,"xyz");
	student s3(&s2);
	student s4=s3;
	
	cout<<"\n name:"<<s1.name;
	cout<<"\n regno:"<<s1.regno;
	
	cout<<"\n name:"<<s2.name;
	cout<<"\n regno:"<<s2.regno;
	
	return 0;
}

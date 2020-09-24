//Object Initialization
#include<iostream>
#include<string.h>
using namespace std;
class student
{
	public:
		char name[10];
		int regno;
		void inits(int reg,char n[10])
		{
			strcpy(name,n);
			regno=reg;
			cout<<"\n Initialization done!";
		}
		void display()
		{
			cout<<"\n Name of the student:"<<name;
			cout<<"\n Register Number:"<<regno;
		}
};
int main()
{
	student s1,s2;
	strcpy(s1.name,"Arun");
	s1.regno=10012;
	s2.inits(s1.regno,s1.name);
	s2.display();
	return 0;
}

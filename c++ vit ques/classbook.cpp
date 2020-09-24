#include<stdio.h>
#include<iostream>
using namespace std;

class book
{
	public:
	int bno;
	char bt[10];
	void stock()
	{
		cout<<"\n book available";
	}
	void issue()
	{
		cout<<"\n book isnt available an in issue";
	}
};

int main()
{
	book b1;
	cout<<"\n enter book num";
	cin>>b1.bno;
	cout<<"/enter title";
	cin>>b1.bt;
	cout<<"\n book info"<<b1.bno<<b1.bt;
	b1.issue();
	b1.stock();
	return 0;
}

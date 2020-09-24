#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int a, b,ch;
	cout<<"enter value";
	cin>>a>>b;
	cout<<"enter choice";
	cin>>ch;
	if(ch==1)
	{
	    cout<<"sum="<<a+b;
	    cout<<endl;
	}
	if(ch==2)
	{
	    cout<<"diff="<<a-b;
	    cout<<endl;
	}
	if(ch==3)
	{
	    cout<<"prod="<<a*b;
	    cout<<endl;
	}
	if(ch==4)
	{
	    cout<<"div="<<a/b;
	    cout<<endl;
	}
	
	return 0;
}

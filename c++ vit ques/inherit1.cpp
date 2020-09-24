#include<iostream>
using namespace std;
// Multi-level Inheritance, i.e. A child class have a child class

class a 
{
int ay;

public:
int ax;
a()
{
cout<<"\n I am a 'a' Constructor";
ax=100;ay=0;
az=300;
}
protected:
int az;
};
class b:public a // Level 1
{
public:
int bx;
b()
{
cout<<"\n I am a 'b' Constructor";	
bx=200;
ax=0;
az=az+100;
by=0;
}
void display()
{
//	cout<<"\n ax="<<ax;
cout<<"\n az="<<az;
cout<<"\n bx="<<bx;
cout<<"\n by="<<by;
}
private:
int by;
};
class c:public b// Level 2
{
private:
int cy;
public:
int cx;
protected:
int cz;

};

int main()
{
c obj;
obj.display();

}

#include<iostream>
using namespace std;
class a
{
public:
inline void print()
{
cout<<"\n Inline function called!";
}
inline void message()
{
cout<<"\n Hello! Message function";
}

};
int main()
{
a obj;
obj.print();
obj.message();
for(int i=0;i<100000;i++)
{

//cout<<"\n Inline function called!";
//cout<<"\n Hello! Message function";
obj.print();
obj.message();
}
{
int x=100;
cout<<"x="<<x;
}

return 0;
}

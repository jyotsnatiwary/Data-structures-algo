#include<iostream>
using namespace std;
class num
{
    public:
    int abc()
    {
        int a,b,c;
        cout<<"enter 2 num";
        cin>>a;
        cin>>b;
        c=a+b;
        cout<<c;
        return 0;
    }
};
int main()
{
    num o;
    //o=num;
    o.abc();
}


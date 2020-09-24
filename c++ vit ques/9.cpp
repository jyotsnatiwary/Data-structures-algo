#include<iostream>
using namespace std;
class cal
{
    int a,b;
    public:

    cout<<"entr 2 num";
    cin>>a;
    cin>>b;


    int add()
    {
        int c;

        c=a+b;
        cout<<c;
        return 0;
    }
    public:
    int sub()
    {
        int d;
        d=a-b;
        cout<<d;
        return 0;
    }
    public:
    int mul()
    {
        int e;
        e=a*b;
        cout<<e;
        return 0;
    }
};
int main()
{
    int a,b;

    cal o;
    o.add();
    //o.sub();
    //o.mul(a,b);
}

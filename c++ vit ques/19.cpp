#include<iostream>
using namespace std;
class area
{
    public:
    int sqare()
    {
        int a=10,a1;
        cout<<a*a;
    }
    int rec()
    {
        int b=5;
        int c=2;
        int a2;
        a2=b*c;
        cout<<a2;
    }
};
int main()
{
    area obj;
    obj.sqare();
    obj.rec();
}

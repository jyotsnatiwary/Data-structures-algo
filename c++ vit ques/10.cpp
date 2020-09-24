#include<iostream>
using namespace std;
class Cal
{
public:
    int setInput(int num1,int num2)
    {
        a=num1;
        b=num2;
    }
    protected:
    int a,b;
};
class Fun: public:class Cal{
    public:
        int sum()
    {
        cout<<a+b;
        return 0;
    }
    int diff()
    {
        cout<<a-b;
        return 0;
    }
};
int main()
{
    Fun o;
    o.sum();
    o.diff();
}

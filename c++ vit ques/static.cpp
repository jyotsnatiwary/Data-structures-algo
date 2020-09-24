#include<stdio.h>
#include<iostream>
// Class declaration
class icecream
{
public:
int scoop;
void count(int);
};

void icecream::count(int t)//outside method definition ::scope resolution operator
{
static int z=0;//Static Member
z++;
scoop=z;

printf("\n The value of scoop is %d",z);

}
int main()
{
int i=0;
icecream ic={0};

for(i=0;i<10;i++)
ic.count(ic.scoop++);
return 0;

}

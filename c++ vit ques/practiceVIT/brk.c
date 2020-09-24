#include<stdio.h>
void main()
{
    int i,j;
    for(i=0;i<=5;i++)
    {
        if(i==3)
            goto p;
        printf("%d \n",i);
    }
    p:
        ptintf("end");
}

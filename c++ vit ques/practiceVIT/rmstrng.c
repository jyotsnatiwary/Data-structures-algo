#include<stdio.h>
void main()
{
    int n,u,s=0,t,h;
    printf("enter num");
    scanf("%d",&n);
    if(n>=100&&n<=999)
    {
        u=n%10;
        t=(u/10)%10;
        h=(u/100)%10;
        s=u*u*u+t*t*t+h*h*h;
        if(s==n)
        {
            printf("its armstrong");
        }
        else
        {
            printf("its not armstrong");
        }
    }

}

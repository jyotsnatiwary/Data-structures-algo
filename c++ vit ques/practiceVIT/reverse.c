#include<stdio.h>
void main()
{
    int n,u,t,h;
    printf("enter num");
    scanf("%d",&n);
    if(n>=100&&n<=999)
    {
        u=n%10;
        t=(n/10)%10;
        h=(n/100)%10;
        printf("%d %d %d",u,t,h);
    }
}

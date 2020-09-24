#include<stdio.h>
void main()
{
    int n,i,c;
    printf("enter num: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            c++;
        }
    }
    if(c==2)
    {
        printf("its prime");
    }
    else
    {
        printf("its not prime");
    }
    return 0;
}

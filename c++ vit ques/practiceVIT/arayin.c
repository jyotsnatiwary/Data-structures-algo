#include<stdio.h>
void main()
{
    int ar[10],s=0,i;
    printf("enter num");
    for(i=0;i<=9;i++)
    {
        scanf("%d",&ar[i]);
        //printf("%d",ar[i]);

    }
    for(i=0;i<=9;i++)
    {
        s=s+ar[i];
    }
    printf("%d",s);
}

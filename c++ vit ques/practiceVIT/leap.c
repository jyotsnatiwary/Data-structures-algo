#include<stdio.h>
void main()
{
    int a;
    printf("enter year");
    scanf("%d",&a);
    if(a%400==0&&a%100==0&&a%4==0)
    {
        printf("its leap year");
    }
    else
    {
        printf("its not leap year");
    }
}

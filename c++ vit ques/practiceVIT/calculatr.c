#include<stdio.h>
void main()
{
    int a,b,z,x,c,d;
    printf("enter no.");
    scanf("%d %d",&a,&b);
    printf("enter choice");
    scanf("%d",&z);
    switch(z)
    {
        case 1:printf("sum= %d",a+b);
        break;
        case 2:printf("diff= %d",a-b);
        break;
        default:printf("enter num");
        scanf("%d %d",&c,&d);

    }

}

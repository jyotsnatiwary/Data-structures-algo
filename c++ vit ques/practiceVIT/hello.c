#include<stdio.h>
void main()
{
    float a,b,c,d,e;
    printf("Enter 2 no.: ");
    scanf("%f %f",&a,&b);
    c=a/b;
    printf("div=%.2f\n",c);
    d=a+b;
    printf("sum=%f\n",d);
    e=a-b;
    printf("diff=%f\n",e);
    printf("prodct=%f",a*b);
}

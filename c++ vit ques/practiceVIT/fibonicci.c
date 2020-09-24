#include<stdio.h>
void main()
{
  int n,i,k,a=0,b=1;
  printf("enter num");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    k=a+b;
    a=b;
    b=k;
    printf("%d  ",k);
  }
}

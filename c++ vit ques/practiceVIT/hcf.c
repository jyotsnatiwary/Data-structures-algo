#include <stdio.h>
void main()
{
  int a,b,min,max;
  printf("enter num");
  scanf("%d %d",&a,&b);
  min=(a<b)?a:b;
  max=(a>b)?a:b;
  int r;
  do
  {
    r=max%min;
    max=min;
    min=r;
  }while(r!=0);
  printf("%d",max);
}

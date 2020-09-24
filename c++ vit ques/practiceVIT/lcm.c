#include<stdio.h>
void main()
{
  int max,min,a,b;
  printf("enter num");
  scanf("%d %d",&a,&b);
  max=(a>b)?a:b;
  min=(a<b)?a:b;
  int l=0;
  do
  {
    l=l+max;
  }while(l%min!=0);
  printf("%d",l);
}

#include<stdio.h>
void main()
{
  int a,b,c;
  printf("enter sides");
  scanf("%d %d %d",&a,&b,&c);
  if(a==b&&b==c)
  {
    printf("equilatrl");
  }
  else if(a==b||b==c||c==a)
  {
    printf("isosceles");
  }
  else
  {
    printf("scalene");
  }
}

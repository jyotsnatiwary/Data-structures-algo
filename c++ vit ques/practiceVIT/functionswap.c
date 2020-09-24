#include<stdio.h>
void swap(int a, int b);
void main()
{
  int a=3,b=4;
  swap(a,b);
  printf("a=%d",a);
  printf("b=%d",b);
}
void swap(int a,int b)
{
  int c;
  c=a;
  b=a;
  a=c;
}

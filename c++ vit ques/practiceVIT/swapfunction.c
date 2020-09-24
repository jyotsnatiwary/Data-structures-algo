#include<stdio.h>
void swap(int *x, int *y);
void main()
{
  int a=3,b=4;
  swap(a,b);
  printf("a=%d",&a);
  printf("b=%d",&b);
}
void swap(int *x,int *y)
{
  int c;
  c=*x;
  *x=*y;
  *y=c;
}

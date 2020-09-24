#include<stdio.h>
void add(c);
void main()
{
    int x;
  x=add(5,5);
  printf("%d",x);
  sub();
  div();
  prod();
}
void add()
{
  int a=1,b=2,c;
  c=a+b;
  //printf("sum= %d",c);
}
void sub()
{
  int d=6,e=3,f;
  f=d-e;
  printf("sub= %d",f);
}
void div()
{
  float g=10,h=5,i;
  i=g/h;
  printf("div= %f",i);
}
void prod()
{
  int j=3,k=7,l;
  l=j*k;
  printf("prod= %d",l);
}

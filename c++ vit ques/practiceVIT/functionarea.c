#include <stdio.h>
void main()
{
  int a,b;
  float a1,a2,a3;
  printf("entr num");
 scanf("%d%d",&a,&b);
  a1=triangle(a,b);
  printf("area of triangle= %f",a1);
 a2=rectangle(a,b);
 printf("area of rectangle= %f",a2);
 a3=square(a,b);
 printf("area of square= %f",a3);
}
triangle(int l,int b)
{

float a1;
  a1=0.5*l*b;
  return a1;

}
rectangle(int l,int b)
{
  float a2;
  a2=l*b;
  return a2;
}
square(int l,int b)
{
 float a3;
 a3=l*l;
 return a3;
}

#include<stdio.h>
void main()
{
  int i,j,a[5];
  printf("enter num");
  for(i=0;i<=4;i++)
  {
    a[i]=i+1;
  }
  for(j=4;j>=0;j++)
  {
    printf("%d",a[j]);
  }
}

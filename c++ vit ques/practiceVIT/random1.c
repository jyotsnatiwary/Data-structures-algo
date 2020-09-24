#include<stdio.h>
void main()
{
  int i,n;
  printf("entr num");
  scanf("%d",&n);
  for(i=1;i<10;i++)
  {
    n=n*i+8;
    printf(n);
  }
}

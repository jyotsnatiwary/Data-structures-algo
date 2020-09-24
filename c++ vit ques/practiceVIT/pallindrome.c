#include<stdio.h>
void main()
{
  int n;
  printf("enter num");
  scanf("%d",&n);
  int r=0,d;
  int m=n;
  while(n>0)
  {
    d=n%10;
    r=r*10+d;
    n=n/10;
  }
  if(r==m)
    {
        printf("its palindrome");
    }
    else
    {
        printf("its not palindrome");
    }
}

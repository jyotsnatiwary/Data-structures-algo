#include<stdio.h>
void main()
{
  //sum of frst n natural num
  int i,s=0,n;
  printf("enter num");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    s=s+i;
  }
   printf("sum= %d",s);

}

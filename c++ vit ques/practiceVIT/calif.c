#include <stdio.h>
void main()
{
  int a,b,z,c,d,x;
  printf("enter num");
  scanf("%d %d",&a,&b);
  printf("enter choice");
  scanf("%d",&z);
  if(z==1)
  {
    printf("sum= %d",a+b);
  }
  if(z==2)
  {
    printf("diff=",a-b);
  }
  else
  {
      printf("enter num");
      scanf("%d %d",&a,&b);
      printf("entr choice");
      scanf("%d",x);
      if(z==1)
      {
         printf("sum= %d",a+b);
      }
      if(z==2)
      {
         printf("diff=",a-b);
      }
  }
}

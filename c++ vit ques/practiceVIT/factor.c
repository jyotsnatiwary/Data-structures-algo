#include<stdio.h>
void main()
{
  //to chk whethr frst num is factor of secnd
  int a,b;
  printf("enter 2 num");
  scanf("%d %d",&a,&b);
  if(a%b==0)
  {
    printf("its factor");
  }
  else
  {
    printf("its not");
  }
}

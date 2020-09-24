#include<stdio.h>
void main()
{
  int i,a[5],s;
  float avg;
  printf("entr num");
  for(i=0;i<=4;i++)
  {
    scanf("%d",&a[i]);
  }
  for(i=0;i<=4;i++)
  {
    s=s+a[i];
  }
  avg=s/5.0;
  printf("avg= %f",avg);
}

#include<stdio.h>
#include<string.h>
void main()
{
  char a[10]="jyotsna";
  char rev[10]="";
  int i;
  int length=0;
  length=strlen(a);
  for(i=0;i<length;i++)
  {
    rev[length-1-i]=a[i];
  }
  printf(rev);
  return 0;
}

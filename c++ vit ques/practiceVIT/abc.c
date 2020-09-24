#include<stdio.h>
#include<string.h>
void main()
{
   char a[10],b[10],c;

   printf("enter name");
   scanf("%s%s",&a,&b);
   strcat(a,b);
   printf("full name: %s",a);
}

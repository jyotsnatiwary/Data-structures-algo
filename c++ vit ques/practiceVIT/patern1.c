#include<stdio.h>
void main()
{
   //pattern
   int n,i,j;
   printf("entr num");
   scanf("%d",&n);
   for(i=1;i<=n-i;i--)
   {
     for(j=1;j<=i;j++)
     {
       printf("*");
     }
     printf(" \n");
   }

}

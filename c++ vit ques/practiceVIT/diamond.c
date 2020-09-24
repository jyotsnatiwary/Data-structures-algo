#include<stdio.h>
void main()
{
   int i,j,s,k,n;
   printf("enter num");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
     for(s=1;s<=n-i;s++)
     {
       printf(" ");
     }
     for(j=i;j>=1;j--)
     {
       printf("*");
     }
     for(k=2;k<=i;k++)
     {
         printf("*");
     }
     printf("\n");
   }
   for(i=n-1;i>=1;i--)
   {
     for(s=1;s<=n-i;s++)
     {
       printf(" ");
     }
     for(j=i;j>=1;j--)
     {
       printf("*");
     }
     for(k=2;k<=i;k++)
     {
       printf("*");
     }
     printf(" \n");
   }
}

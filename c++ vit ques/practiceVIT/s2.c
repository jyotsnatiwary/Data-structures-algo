#include<stdio.h>
void main()
{
    char a[7]={'S','T','R','I','N','G'};
    int i, j,k;
    for(i=0;i<6;i++)
    {
        for(j=6;j>=i;j--)
        {
            printf(" ");
        }
        for (k=0; k<=i; k++)
        {
          printf("%c",a[k]);
        }
        printf("\n");
    }
}

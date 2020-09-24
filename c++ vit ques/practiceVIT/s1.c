#include<stdio.h>
void main()
{
    char a[7]={'S','T','R','I','N','G'};
    int i, j;
    for(i=0;i<7;i++)
    {
        for(j=0;j<i;j++)
        {
            printf("%c",a[j]);
        }
        printf("\n");
    }
}

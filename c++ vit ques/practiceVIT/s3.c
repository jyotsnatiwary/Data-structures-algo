#include<stdio.h>
void main()
{
    char a[7]={'S','T','R','I','N','G'};
    int i, j,k;
    for(i=6;i>=0;i--)
    {
        printf("%s",a+i);
        printf("\n");
    }
}

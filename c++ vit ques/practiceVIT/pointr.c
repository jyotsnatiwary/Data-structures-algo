#include<stdio.h>
void main()
{
    char a[3];
    int i,j,*p;
    printf("enter char");
    for (i=0;i<=2;i++)
    {
           scanf("%c",&a[i]);
           fflush(stdin);
    }
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            printf("/t%f",*p);
            p++;
        }
    }
}

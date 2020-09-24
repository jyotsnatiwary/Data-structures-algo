#include<stdio.h>
#include<string.h>
void main()
{
    int i,j,k,l;
    char a[5];
    printf("enter char");
    for(i=0;i<=4;i++)
    {
        scanf("%c",&a[i]);
        fflush(stdin);
    }
    for(j=0;j<=4;j++)
    {
        for(k=0;k<=strlen(a);k++)
        {
            if(a[i]>='A'&&a[i]<='Z')
            {
                a[i]=a[i]+32;
            }
            else if(a[i]>='a'&&a[i]<='z')
            {
                a[i]=a[i]-32;
            }
        }
    }
    for(l=0;l<=4;l++)
    {
        printf("%c",a[l]);
    }
}

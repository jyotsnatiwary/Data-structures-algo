#include<stdio.h>
void main()
{
    int a[10],i,j,k,l,m;
    printf("enter  num");
    for(i=0;i<=9;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0;j<=9;j++)
    {
        for(k=0;k<=(9-j);k++)
        {
            if(a[k]>=a[k+1])
                {
                    l=a[k];
                    a[k]=a[k+1];
                    a[k+1]=l;
                }
        }

    }
    for(m=0;m<10;m++)
        {
            printf("sorted array: %d \n",a[m]);
        }
}

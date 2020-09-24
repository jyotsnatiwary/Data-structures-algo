#include<stdio.h>
void main()
{
    int i,j,k,l=0,m;
    char a[5];
    printf("enter char");
    for(i=0;i<=4;i++)
    {
        scanf("%c",&a[i]);
        fflush(stdin);
    }
    for(j=0;j<=4;j++)
    {l=0;
        for(k=0;k<=4;k++)
        {
            if(a[j]==a[k])
            {
                l++;
            }
        }
       printf("%c of common char in array= %d \n",a[j],l);
    }


}

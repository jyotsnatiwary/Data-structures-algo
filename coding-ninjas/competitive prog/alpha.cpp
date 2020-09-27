#include<stdio.h>
#include<string.h>
int main()
{
    char a[5010];
    int i,j;
    scanf("%s",a);
    while(a[0]!='0')
    {
 
        int n= strlen(a);
        long long int b[n];
        for(i=0;i<n;i++)
            b[i]= 0;
        b[0]= 1;
        for(i=1;i<n;i++)
        {
 
            j= (a[i-1] - '0') * 10 + (a[i] - '0');
            if(a[i]- '0')
                b[i]= b[i-1];
             if(j>9 && j<27)
             {
                 if(i==1)
                    b[i]= b[i] + 1;
                 else
                    b[i]= b[i] + b[i-2];
             }
 
        }
        printf("%lld\n",b[n-1]);
        scanf("%s",a);
    }
    if(a[0]=='0')
        return 0;
}

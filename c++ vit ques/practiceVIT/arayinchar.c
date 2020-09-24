#include<stdio.h>
void main()
{
    char a[10],i;
    int s=0;
    printf("enter char");
    for(i=0;i<=9;i++)
    {
        scanf("%c",&a[i]);
        fflush(stdin);
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
        {
            s++;
        }
    }
    printf("num of vowel= %d",s);
}

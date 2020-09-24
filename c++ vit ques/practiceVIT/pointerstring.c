#include <stdio.h>
int main()
{
    char str[100];
    char *ptr;
    int  cntV,cntC;

    printf("Enter a string: ");
    gets(str);

    ptr=str;

    cntV=cntC=0;
    while(*ptr!='\0')
    {
        if(*ptr=='A' ||*ptr=='E' ||*ptr=='I' ||*ptr=='O' ||*ptr=='U' ||*ptr=='a' ||*ptr=='e' ||*ptr=='i' ||*ptr=='o' ||*ptr=='u')
            cntV++;
        else
            cntC++;
        ptr++;
    }

    printf("Total number of VOWELS: %d, CONSONANT: %d\n",cntV,cntC);
     return 0;
}

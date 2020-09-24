#include <stdio.h>
void main()
{
    char str[100];
    char *ptr;
    printf("Enter a string: ");
    gets(str);
    ptr=str;
    printf("Entered string is: ");
    while(*ptr!='\0')
        printf("%c",*ptr++);

}

#include<stdio.h>
void main()
{
    char a;
    printf("entr character");
    scanf("%c",&a);
    switch(a)
    {
      case 'i':
      case 'a':
      case 'e':
      case 'o':
      case 'u': printf("vowel");
      default: printf("consonant");
    }
}

#include<stdio.h>
#include<string.h>
void main()
{
  int ch,num;
  char name[10];
  printf("Welcome to COFFEE EXPRESS \n");
  printf("Enter your name: ");
  //scanf("%c",&name);
  gets(name);
  //puts(name);
  printf("Enter your contact number: ");
  scanf("%d",&num);
  menu();
  printf("Ener your choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
      case 1: printf("bill:$20");
      break;
      case 2: printf("Bill:$30");
      break;
      case 3: printf("Bill:$25");
      break;
      case 4: printf("Bill:$27");
      break;
      case 5: printf("Bill:$40");
      break;
      case 6: menu();
              printf("Ener your choice");
            scanf("%d",&ch);
            switch(ch)
            {
               case 1: printf("bill:$20");
               break;
               case 2: printf("Bill:$30");
               break;
               case 3: printf("Bill:$25");
               break;
               case 4: printf("Bill:$27");
               break;
               case 5: printf("Bill:$40");
               break;
               default: printf("Invalid input");
            }
            break;
            default:("Invalid input");
  }
  printf("\nThankYou");

}
void menu()
{
  printf("MENU");
  printf("1.Alphonso Milk Shake:$20\n");
  printf("2.Arise with pomegranate:$30\n");
  printf("3.California tea:$25\n");
  printf("4.Aztec single origin coffee:$27\n");
  printf("5.Caffee Frappe:$40\n");
  printf("6.Edit menu\n");
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


double price[7] = {15.80 , 10.50 , 19.00 , 14.00 , 12.00 , 22.00 , 16.00 };
double mealTaxPrices[7];
int person;

void printMeals();
void orderMeals();
double order();

int main()
{
    char response = 'y';


     printMeals();
     while(response == 'y'|| response == 'Y')
    {
            printf("please enter number of person  :");
            scanf("%d",&person);
            orderMeals();

            printf("\nwould you like to continue(y/n):");
            scanf("\n%c",&response);
    }

 printf("\n      ******************** THANK YOU FOR COMING  *************************\n");
 printf("\20**********************   PLEASE VISIT US NEXT TIME  **************************\20 \n");
   system("pause");
   return 0;
}

void printMeals()
{

      printf("\20*******************  WELCOME TO COFFEE EXPRESS **************************\20\n");
      printf(" \t\t\t Below is the menue:\20\n");
      printf(" \t\t\t MEALS\t\t\tPRICE:\n");
      printf(" \t\t\t \22*******************************\22\n");
      printf(" \t\t 1- Caffee Frappe\tRM15.80\n");
      printf(" \t\t 2- Coffee Latte\t\tRM10.50\n");
      printf(" \t\t 3- California Tea\tRM19.00\n");
      printf(" \t\t 4- Chicken Soup\tRM14.00\n");
      printf(" \t\t 5- Chicken Maryland Tea\tRM12.00\n");
      printf(" \t\t 6- Red Chill\t\tRM22.00\n");
      printf(" \t\t 7- Pineapple Fresh\tRM16.00\n");


      printf("\n");
}
void orderMeals()
{
	double totalPrice;
	double allPayment,discount;
         printf("                      \t\t**** ORDER MENUE****\n");


        totalPrice =  order();
		allPayment = totalPrice;

     printf("\n \t\t     \22**************************************\22    \n");
     printf(" \t\t   ******************  final BILL   ************      \n");
     printf(" \t\t\tadult/child\tcount\t\ttotal price\n");
     printf(" \t\t\tadults\t\t%d\t\t%5.2f\n",person,totalPrice);
     printf(" \t\t\tTotal bill\t\t\t%5.2f\n",allPayment );



     if(allPayment < 10)
		 discount=((allPayment * 0.5)/100);
     else if(allPayment>= 10 && allPayment<20)
          discount=((allPayment * 1)/100);
     else if(allPayment>= 20 && allPayment<30)
          discount=((allPayment * 1.5)/100);
     else if(allPayment>= 30 && allPayment<40)
          discount=((allPayment * 2.0)/100);
	 else
		  discount= ((allPayment * 5.0)/100);

          printf(" \t\t\tTotal bill after discount\t%5.2f\n",allPayment-discount);

}
double order()
{
     int menuOption,i,amount;
      char response = 'y';
      double totalPerPerson = 0.0,totalAllPerson = 0.0;
      double tax = 5.0;
      if(person <=0)
		   printf("\n ");
	  else
      printf("*\tadults:\n");
      for(i=0;i<person;i++)
     {
               printf("adult %d please enter your orders\n",i+1);
               while(response == 'y' || response == 'Y')
               {
                              printf("please enter your option:");
                              scanf("%d",&menuOption);
							  if(menuOption<1 || menuOption>7)
							  {
								  printf("sorry we don`t have this order \nagain! ");
								  continue;
							  }
                              printf("please enter your amount of order:");
                              scanf("%d",&amount);


                           totalPerPerson = totalPerPerson + (amount * price[menuOption - 1] );

                              printf("\nWould you like to enter more orders(y/n):");
                              scanf("\n%c",&response);



               }
               printf("\n");
               totalAllPerson += totalAllPerson +  totalPerPerson;
               totalPerPerson = 0.0;
               response = 'y';
     }

     return totalAllPerson + ((totalAllPerson * tax) / 100);
}



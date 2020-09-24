#include <stdio.h>
int main()
{
    int r=0,c=0,num;

    r=rand()%1000;

    while(1)
    {
        c+=1;

        printf("Guess a number from (0 to 1000): ");
        scanf("%d",&num);


        if(r==num){
            printf("Congratulations, you have guessed a correct number.");
            break;
        }
        else if(r<num){
            printf("Generated number is less than entered number, try your luck again...");
        }
        else if(r>num){
            printf("Generated number is greater than entered number, try your luck again...");
        }

        if(c==7){
            printf(" Maximum limit of atttempt finished, BAD LUCK !!!");
            break;
        }
}    }

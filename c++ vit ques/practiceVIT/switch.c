#include<stdio.h>
void main()
{
    int x,w,y;
    p:
    printf("enter choice");
    //printf("enter amont");
    scanf("%d",&x);
    //scanf("%d",&z);
    do
        {
            switch(x)
            {
                case 1:printf("entr mony to deposit");
                scanf("%d",&w);
                printf("deposit:%d",w);
                break;
                case 2:
                printf("enter money to withdraw");
                scanf("%d",&y);
                printf("amt:%d",x-y);
                break;
                case 3:printf("balance:%d",x);
                break;
                default:goto p;
            }
        }while(x!=0);
}


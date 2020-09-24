 #include<stdio.h>

   int main(){

                int numbr,k,remark;

                printf(" The prime numbers between 1 and 1000 : \n");

                for(numbr=2;numbr<=1000;++numbr)

               {

               remark=0;

               for(k=2;k<=numbr/2;k++){

               if((numbr % k) == 0){

               remark++;

               break;

               }

               }

               if(remark==0)

               printf("\n    %d ",numbr);

              }

    return 0;
    }

#include<stdio.h>
void main()
{

  int a[10][10],s;
     int m,i,j=0,num,p;
     printf("Enter the square matrix size ");
     scanf("%d",&s);
     printf("\nyour matrix is of %d*%d\n",s,s);
     printf("\nEnter the value for the matrix\n\n");

     for(int i=0; i<s; i++)
     {
          for(int j=0; j<s; j++)
          scanf("%d",&a[i][j]);
     }

     printf("\n\n");
     p = s;

     for(int i=p-1; i > 0; i--, j++)
     {
          for(num=j; num < i; num++)
          printf("%d ", a[j][num]);
          for(num=j; num < i; num++)
          printf("%d ", a[num][i]);
          for(num=i; num > j; num--)
          printf("%d ", a[i][num]);
          for(num=i; num > j; num--)
          printf("%d ", a[num][j]);
     }

     m = (p-1)/2;
     if (p % 2 == 1) printf("%d", a[m][m]);
     printf("\n\n");
     getch();
     return 0;
}



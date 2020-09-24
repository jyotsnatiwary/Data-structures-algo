#include<stdio.h>
void main()
{
  int p,q,r;

  //printf("Subject\tMarks\tGrade\n");
  printf("enter marks");
  scanf("%d",&p);
  scanf("%d",&q);
  scanf("%d",&r);
  int s;
  float av;
  s=p+q+r;
  av=s/3;
//  if(p>=90)
//  {
//      getchar
//  }
  printf("\tVIT University\t\t\t\n");
  printf("\t1st Semister Result\t\t\t\n");
  printf("-----------------------------------\n");
  printf("-----------------------------------\n");
  printf("|  sub     :  Max  |  Marks   |\n");
  printf("|  phy     :  100  |  %d      |\n",p);
  printf("|  che     :  100  |  %d      |\n",q);
  printf("|  math    :  100  |  %d      |\n",r);
  printf("|  Total   :  300  |  %d     |\n",s);
  printf("per  %f\t\t \n",av);
  printf("-----------------------------------\n");

}

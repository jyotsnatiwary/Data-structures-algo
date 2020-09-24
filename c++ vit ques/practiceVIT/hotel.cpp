#include<stdio.h>
#include<string.h>
struct hotel
{
	char name[20];
	char add[30];
	char grade[2];
	long int charge;
	long int no;
};
 main()
{
	struct hotel h[3];
	for(int i=0;i<3;i++)
	{
		printf("enter the name of hotel  ");
		scanf("%s",h[i].name);
		printf("enter the address  ");
		scanf("%s",h[i].add);
        printf("enter the charge  ");
		scanf("%ld",&h[i].charge);
		printf("enter the number  ");
		scanf("%ld",&h[i].no);
		printf("enter the grade  ");
		scanf("%s",h[i].grade);
	}
/*	printf("\nsec. part\n");
	int b;
	printf("\nenter the amount u can pay   ");
	scanf("%d",&b);
	for(int i=0; i<5; i++)
	{
		if(h[i].charge<b)
		{printf("%s\n",h[i].name);}
	}*/
	printf("\nfirst part of question\n");
	int a;
	char d[2],c[2],t[20];
	for(int i=0;i<3;i++)
	{for(int j=i+1;j<3;j++)
	{
		if(strcmp(h[i].name,h[j].name)>1)
		{
			strcpy(t,h[i].name);
			strcpy(h[i].name,h[j].name);
			strcpy(h[j].name,t);
		}
	}
    printf("\nenter the grade\n");
	scanf("%s",c);
	}
	for(int i=0; i<3; i++)
	{
		strcpy(h[i].grade,d);
	if(c==d)
	{printf("%s\n",h[i].name);
		}	
	}
}

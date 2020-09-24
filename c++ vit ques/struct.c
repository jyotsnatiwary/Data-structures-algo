#include<stdio.h>
//using namespace std;

struct book
{
	char author[10];
	int num;
	char titile[10];
	
};

void main()
{
	struct book b1;
	struct book b2;
	printf("enter author, serial num, title");
	scanf("%s %d %s", b1.author);
	printf(b1.author);
}

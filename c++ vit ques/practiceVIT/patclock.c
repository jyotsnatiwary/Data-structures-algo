#include<stdio.h>
int main()
{
	int n,c1=0,r1=0,k=1,i,j;
	printf("\n Enter the size ::");
	scanf("%d",&n);
	int a[n][n],c2=n-1,r2=n-1;
	do
	{
		for(i=c1;i<=c2;i++)
		{
			a[r1][i]=k;
			k++;
		}
		for(j=r1+1;j<=r2;j++)
		{
			a[j][c2]=k;
			k++;
		}
		for(i=c2-1;i>=c1;i--)
		{
			a[r2][i]=k;
			k++;
		}
		for(j=r2-1;j>=r1+1;j--)
		{
			a[j][c1]=k;
			k++;
		}
		c1++;c2--;r1++;r2--;
	}while(k<=n*n);
	printf("\n The matrix is ::\n");
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
		printf("\n");
        }
        return 0;
 }

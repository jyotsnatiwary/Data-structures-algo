#include<iostream>
using namespace std; 

int compareTriplets(int a[], int b[])
{
	int c=0;
	int d=0;
	for(int i=0; i<3; i++)
	{
		if(a[i]>b[i])
		{
			c++;
		}
		if(a[i]<b[i])
		{
			d++;
		}
	}
	cout<<c<<" "<<d<<endl;
	return 0;
}
int main()
{
	int ar[3], br[3];
	int i;
	for(i=0;i<3;i++)
	{
		cin>>ar[i];
		
	}
	for(i=0;i<3;i++)
	{
		cin>>br[i];
	}
	if((ar[0]&&ar[1]&&ar[2])<=100&&(ar[0]&&ar[1]&&ar[2])>=1)
	{
		if((br[0]&&br[1]&&br[2])<=100&&(br[0]&&br[1]&&br[2])>=1)
		{
			compareTriplets(ar, br);
		}
	
	}	
    return 0;
}

#include<iostream>
using namespace std;

long long int VeryBigSum(unsigned long long int a[], int n)
{
	unsigned long long int s=a[0];
    for(int j=1; j<n; j++)
    {
    	int pow=1;
        for(unsigned long long int k=a[j];k!=0;k=k/10)
        {
        	int p=k%10;
        	s=s+(p*pow);
        	pow*=10;
		}
    }
    return s;
}

int main()
{
	int l, i;
	cin>>l;
	unsigned long long int ar[10];
	if(l>=1&&l<=10)
	{
		for(i=0; i<l; i++)
		{
			cin>>ar[i];
		}
	}	 
	cout << VeryBigSum(ar, l);
	
	return 0;
}

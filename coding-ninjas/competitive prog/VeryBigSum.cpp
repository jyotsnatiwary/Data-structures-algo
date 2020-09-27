#include<iostream>
using namespace std;

long long int VeryBigSum(unsigned long long int a[], int n)
{
	unsigned long long int s=0;
    for(int j=0; j<n; j++)
    {
        s=s+a[j];
    }
    return s;
}

int main()
{
	int l, i;
	cin>>l;
	unsigned long long int ar[l];
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

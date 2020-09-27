#include<iostream>
using namespace std;

int SimpleArraySum(long long int a[], int n)
{
	long long int s=0;
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
	long long int ar[l];
	for(i=0; i<l; i++)
	{
		cin>>ar[i];
	}
	if(l>=1&&l<=10)
	{
		cout << SimpleArraySum(ar, l);
	}
	
	return 0;
}

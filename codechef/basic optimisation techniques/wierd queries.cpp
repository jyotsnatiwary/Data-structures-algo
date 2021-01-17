#include <bits/stdc++.h>
using namespace std;

long long int helpingNour(long long int Y)
{
    long long int res=0;
    for(int i=1;i<701 && i<Y;i++)
    {
        res = res + (int)sqrt(Y-i);
    }
    return res;
}

int main() {
	long long int t,Y;
	cin>>t;
	while(t--)
	{
	    cin>>Y;
	    cout<<helpingNour(Y)<<'\n';
	}
	return 0;
}


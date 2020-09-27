#include<bits/stdc++.h>
using namespace std;
int main() {

	int n, t, i, j, a[n];
    cin>>n;
    cin>>t;
    int count= pow(2,n);
    if (t<=10000&& t>=1)
    {
        if(n<=100&& n>=1)
        {
            for(i=0;i<n;i++)
            {
                cin>>a[i];
            }
        }
        
    }
    for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i & (1 << j)) > 0)
				cout << a[j] << " ";
		}
	}
}

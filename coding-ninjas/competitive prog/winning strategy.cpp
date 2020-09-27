#include <bits/stdc++.h>

using namespace std;
//Returns -1 if not possible
int go(int* arr, int n){
    if(n==1){
        if(arr[0]!=1){
            return -1;
        }else{
            return 0;
        }
    }
    if(n==0){
        return 0;
    }
	
    int count = 0;
	int i = 0;
    
    for (int j = 0; j < n; ++j)
    {
    	if(arr[j]>j+3 || arr[j]<j-1){
            return -1;
        }
    }
	
    for (i ; i < n-2; ++i)
	{
        if(arr[i]>i+3 || arr[i]<i-1){
            return -1;
        }
		if (arr[i]==i+1)
		{
			continue;

		}else if (arr[i+1]==i+1)
		{
			//cout << "here" << '\n';
			swap(arr[i], arr[i+1]);
			count++;
			//cout << count << '\n';
			continue;
		}else if (arr[i+2]==i+1)
		{
			swap(arr[i+2], arr[i+1]);
			count++;
			swap(arr[i+1], arr[i]);
			count++;
			continue;
		}else{
			return -1;
		}
	}
	
    
    //Doing operation on remaining last two elements
	if (arr[i] == i+1 && arr[i+1]==i+2)
	{
		return count;
        
	}else if(arr[i]==i+2 && arr[i+1]==i+1){
		swap(arr[i], arr[i+1]);
		return count+1;
	}else{
		return -1;
	}




}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;

	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	int ans = go(arr, n);
	if (ans==-1)
	{
		cout << "NO" << '\n';
	}else{
		cout << "YES" << '\n' << ans <<endl;
	}


	return 0 ; 



}

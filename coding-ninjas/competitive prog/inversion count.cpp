#include <bits/stdc++.h> 
using namespace std; 
  
long long solve(int arr[], int n) 
{ 
    int inv_count = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (arr[i] > arr[j]) 
                inv_count++; 
  
    return inv_count; 
} 
int main()  
{  
   int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];        
    }
    int n = sizeof(arr)/sizeof(arr[0]);  
      
    cout << solve(arr, n);  
      
    return 0;  
} 

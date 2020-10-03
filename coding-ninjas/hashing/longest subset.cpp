/*Given an array, find and return the length of longest subarray containing equal number of 0s and 1s.
Input Format :
Line 1 : Integer N, size of array
Line 2 : Array elements (separated by space)
Output Format :
Length of longest subarray
Contraints :
1<= N <=10^6
Sample Input 1 :
6 
1 0 0 1 1 1
Sample Output 1 :
4    
Sample Input 2 :
10 
1 1 1 0 0 0 1 1 0 0
Sample Output 2 :
10*/

#include<bits/stdc++.h> 
using namespace std; 
  
//So basically first change all the 0s to -1
//And then all you need to do is find the longest subarray with sum equal to 0
//You know how to calculate longest subarray with sum equal to 0


#include<unordered_map>
int max(int arr[], int n) {
	/* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int sum = 0;  
    int maxSize = -1, startindex;  
  
    // Pick a starting point as i  
    
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            arr[i] = -1;
        }
    }
    
    unordered_map<int, int> omap;
    
    for(int i=0; i<n; i++){
        sum += arr[i];
        
        if(omap.count(sum) > 0){
            if(i-omap[sum] > maxSize){
                maxSize = i - omap[sum];
            }
        }
        else{
            omap[sum]= i;
        }
           
    }
    return maxSize; 

}

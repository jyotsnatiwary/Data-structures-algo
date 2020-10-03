/*You are given with an array of integers and an integer K. Write a program to find and print all pairs which have difference K.
Take difference as absolute.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Line 3 : K
Output format :
Print pairs in different lines (pair elements separated by space). In a pair, smaller element should be printed first.
(Order of different pairs is not important)
Constraints :
0 <= n <= 10^4
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2 5
1 4
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
4 4
4 4
4 4
4 4
4 4
4 4*/

#include<bits/stdc++.h>
using namespace std;


void printPairs(int *input, int n, int k) {
	// Write your code here
	unordered_set<int> set;
	for(int i=0;i<n;i++){
		if(set.find(input[i]-k) != set.end()) cout<<input[i]<<" "<<input[i]-k<<endl;
		if(set.find(input[i]+k) != set.end()) cout<<input[i]+k<<" "<<input[i]<<endl;
		set.insert(input[i]);
	}

}
//main code
void printPairs(int *input, int n, int k) {
	// Write your code here
    
    unordered_map<int,int>m;
    
    //Unusual case of zero
    if(k==0){
        for(int i=0;i<n;i++){
            
            if(m.count(input[i]))
                m[input[i]]+=1;
            else
                m[input[i]]=0;
            
            if(m[input[i]]){
                int t=m[input[i]];
                for(int j=1;j<=t;j++)
                    cout<<(input[i])<<" "<<(input[i])<<endl;
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
        
            if(m.count(input[i]))
                m[input[i]]+=1;
            else
                m[input[i]]=1;
        
            if(m.count(input[i]+k)){
                int t=m[input[i]+k];
                for(int j=1;j<=t;j++)
                    cout<<(input[i])<<" "<<(input[i]+k)<<endl;
            }
            if(m.count(input[i]-k)){
             
                int t=m[input[i]-k];
                for(int j=1;j<=t;j++)
                    cout<<(input[i]-k)<<" "<<(input[i])<<endl;
             }
        }
             
        
    }

}


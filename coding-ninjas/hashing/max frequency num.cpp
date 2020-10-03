/*You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Most frequent element
Constraints :
0 <= N <= 10^8
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1*/

#include<bits/stdc++.h>
using namespace std;

int highestFrequency(int *input, int n){
	unordered_map<int,int> freq;
	for(int i=0;i<n;i++){
		int key=input[i];
		if(freq.count(key)==0) freq[key]=1;
		else freq[key]++;
	}
	int max=freq[input[0]];
	int ans=input[0];
	int j=1;
	while(j<n){
		if(freq[input[j]]>max)
		{
			max=freq[input[j]];
			ans=input[j];
		}
		j++;
	}
	return ans;
}	




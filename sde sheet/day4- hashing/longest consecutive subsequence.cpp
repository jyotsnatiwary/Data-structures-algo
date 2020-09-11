//longest consecutive subsequence

/*Create an empty hash.
Insert all array elements to hash.
Do following for every element arr[i]
Check if this element is the starting point of a subsequence. To check this, simply look for arr[i] – 1 in the hash, if not found, then this is the first element a subsequence.
If this element is the first element, then count the number of elements in the consecutive starting with this element. Iterate from arr[i] + 1 till the last element that can be found.
If the count is more than the previous longest subsequence found, then update this.*/

// C++ program to find longest 
// contiguous subsequence 
#include <bits/stdc++.h> 
using namespace std; 

// Returns length of the longest 
// contiguous subsequence 
int findLongestConseqSubseq(int arr[], int n) 
{ 
	unordered_set<int> S; 
	int ans = 0; 

	// Hash all the array elements 
	for (int i = 0; i < n; i++) 
		S.insert(arr[i]); 

	// check each possible sequence from 
	// the start then update optimal length 
	for (int i = 0; i < n; i++) { 
		// if current element is the starting 
		// element of a sequence 
		if (S.find(arr[i] - 1) == S.end()) { 
			// Then check for next elements 
			// in the sequence 
			int j = arr[i]; 
			while (S.find(j) != S.end()) 
				j++; 

			// update optimal length if 
			// this length is more 
			ans = max(ans, j - arr[i]); 
		} 
	} 
	return ans; 
} 

// Driver program 
int main() 
{ 
	int arr[] = { 1, 9, 3, 10, 4, 20, 2 }; 
	int n = sizeof arr / sizeof arr[0]; 
	cout << "Length of the Longest contiguous subsequence is "
		<< findLongestConseqSubseq(arr, n); 
	return 0; 
} 


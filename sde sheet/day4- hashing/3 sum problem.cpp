//3 sum problem

/*Approach: This approach uses extra space but is more simpler than the two pointers approach. Run two loops outer loop from start to end and inner loop from i+1 to end. Create a hashmap or set to store the elements in between i+1 to j-1. So if the given sum is x, check if there is a number in the set which is equal to x – arr[i] – arr[j]. If yes print the triplet.
Algorithm:
Traverse the array from start to end. (loop counter i)
Create a HashMap or set to store unique pairs.
Run another loop from i+1 to end of the array. (loop counter j)
If there is an element in the set which is equal to x- arr[i] – arr[j], then print the triplet (arr[i], arr[j], x-arr[i]-arr[j]) and break
Insert the jth element in the set.*/

// C++ program to find a triplet using Hashing 
#include <bits/stdc++.h> 
using namespace std; 

// returns true if there is triplet with sum equal 
// to 'sum' present in A[]. Also, prints the triplet 
bool find3Numbers(int A[], int arr_size, int sum) 
{ 
	// Fix the first element as A[i] 
	for (int i = 0; i < arr_size - 2; i++) { 
		// Find pair in subarray A[i+1..n-1] 
		// with sum equal to sum - A[i] 
		unordered_set<int> s; 
		int curr_sum = sum - A[i]; 
		for (int j = i + 1; j < arr_size; j++) { 
			if (s.find(curr_sum - A[j]) != s.end()) { 
				printf("Triplet is %d, %d, %d", A[i], 
					A[j], curr_sum - A[j]); 
				return true; 
			} 
			s.insert(A[j]); 
		} 
	} 
	// If we reach here, then no triplet was found 
	return false; 
} 
int main() 
{ 
	int A[] = { 1, 4, 45, 6, 10, 8 }; 
	int sum = 22; 
	int arr_size = sizeof(A) / sizeof(A[0]); 

	find3Numbers(A, arr_size, sum); 

	return 0; 
} 


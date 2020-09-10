// CPP program to print digit's position 
// to be removed to make number 
// divisible by 6 
#include <bits/stdc++.h> 
using namespace std; 

// function to print the number divisible 
// by 6 after exactly removing a digit 
void greatest(string s) 
{ 
	int n = s.length(); 
	int a[n]; 

	// stores the sum of all elements 
	int sum = 0; 

	// traverses the string and converts 
	// string to number array and sums up 
	for (int i = 0; i < n; i++) { 
		a[i] = s[i] - '0'; 
		sum += a[i]; 
	} 

	if (a[n - 1] % 2) // ODD CHECK 
	{ 
		// if second last is odd or 
		// sum of n-1 elements are not 
		// divisible by 3. 
		if (a[n - 2] % 2 != 0 or (sum - a[n - 1]) % 3 != 0) { 
			cout << "-1" << endl; 
		} 

		// second last is even and 
		// print n-1 elements 
		// removing last digit 
		else { 
	
			// last digit removed 
			cout << n << endl; 
		} 
	} 
	else { 
		int re = sum % 3; 
		int del = -1; 

		// counter to check if any 
		// element after removing, 
		// its sum%3==0 
		int flag = 0; 

		// traverse till second last element 
		for (int i = 0; i < n - 1; i++) { 

			// to check if any element 
			// after removing, 
			// its sum%3==0 
			if ((a[i]) % 3 == re) { 
	
				// the leftmost element 
				if (a[i + 1] > a[i]) { 
					del = i; 
					flag = 1; 

					// break at the leftmost 
					// element 
					break; 
				} 
				else { 
					// stores the right most 
					// element 
					del = i; 
				} 
			} 
		} 

		// if no element has been found 
		// as a[i+1]>a[i] 
		if (flag == 0) { 
	
			// if second last is even, then 
			// remove last if (sum-last)%3==0 
			if (a[n - 2] % 2 == 0 and re == a[n - 1] % 3) 
				del = n - 1; 
		} 

		// if no element which on removing 
		// gives sum%3==0 
		if (del == -1) 
			cout << -1 << endl; 
		else { 
			cout << del + 1 << endl; 
		} 
	} 
} 

// driver program to test the above function 
int main() 
{ 
	string s = "2436"; 
	greatest(s); 
	return 0; 
} 


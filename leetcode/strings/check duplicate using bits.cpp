// A space efficient C++ program to check if 
// all characters of string are unique. 
#include<bits/stdc++.h> 
using namespace std; 

// Returns true if all characters of str are 
// unique. 
// Assumptions : (1) str contains only characters 
//				 from 'a' to 'z' 
//			 (2) integers are stored using 32 
//				 bits 
bool areChractersUnique(string str) 
{ 
	// An integer to store presence/absence 
	// of 26 characters using its 32 bits. 
	int checker = 0; 

	for (int i = 0; i < str.length(); ++i) 
	{ 
		int val = (str[i]-'a'); 

		// If bit corresponding to current 
		// character is already set 
		if ((checker & (1 << val)) > 0) 
			return false; 

		// set bit in checker 
		checker |= (1 << val); 
	} 

	return true; 
} 

// Driver code 
int main() 
{ 
	string s = "aaabbccdaa"; 
	if (areChractersUnique(s)) 
		cout << "Yes"; 
	else
		cout << "No"; 
	return 0; 
} 


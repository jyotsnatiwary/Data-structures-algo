// C++ program to print all 
// permutations with duplicates allowed 
#include <bits/stdc++.h> 
using namespace std; 


// Function to print permutations of string 
// This function takes three parameters: 
// 1. String 
// 2. Starting index of the string 
// 3. Ending index of the string. 
void permute(string a, int l, int r) 
{ 
	// Base case 
	if (l == r) 
		cout<<a<<endl; 
	else
	{ 
		// Permutations made 
		for (int i = l; i <= r; i++) 
		{ 

			// Swapping done 
			swap(a[l], a[i]); 

			// Recursion called 
			permute(a, l+1, r); 

			//backtrack 
			swap(a[l], a[i]); 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	string str = "ABC"; 
	int n = str.size(); 
	permute(str, 0, n-1); 
	return 0; 
} 

// using next permutation
// C++ program to print all permutations with 
// duplicates allowed using next_permutation 
#include <bits/stdc++.h> 
using namespace std; 

// Function to print permutations of string str 
// using next_permutation 
void permute(string str) 
{ 
	// Sort the string in lexicographically 
	// ascennding order 
	sort(str.begin(), str.end()); 

	// Keep printing next permutation while there 
	// is next permutation 
	do { 
	cout << str << endl; 
	} while (next_permutation(str.begin(), str.end())); 
} 

// Driver code 
int main() 
{ 
	string str = "CBA"; 
	permute(str); 
	return 0; 
} 

//using stl
// C++ program to print all permutations with 
// duplicates allowed using rotate() in STL 
#include <bits/stdc++.h> 
using namespace std; 

// Function to print permutations of string str, 
// out is used to store permutations one by one 
void permute(string str, string out) 
{ 
	// When size of str becomes 0, out has a 
	// permutation (length of out is n) 
	if (str.size() == 0) 
	{ 
		cout << out << endl; 
		return; 
	} 

	// One be one move all characters at 
	// the beginning of out (or result) 
	for (int i = 0; i < str.size(); i++) 
	{ 
		// Remove first character from str and 
		// add it to out 
		permute(str.substr(1), out + str[0]); 

		// Rotate string in a way second character 
		// moves to the beginning. 
		rotate(str.begin(), str.begin() + 1, str.end()); 
	} 
} 

// Driver code 
int main() 
{ 
	string str = "ABC"; 
	permute(str, ""); 
	return 0; 
} 


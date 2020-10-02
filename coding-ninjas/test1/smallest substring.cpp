/*Find smallest substring
Send Feedback
Given two strings string1 and string2 (named large and small), find the smallest substring in string1 containing all characters of string2 in O(n). You need to return the output substring.
Note : The characters of string2 need not to be present in same order in string1. That is, we need a substring which contains all characters of string2 irrespective of the order.
Return null if no substring with all characters is present.
Input format :
Line 1 : String 1
Line 2 : String 2
Output Format :
Smallest substring
Constraints :
1 <= Length of string1 & string2 <= 10^4
Sample Input 1 :
Looks for minimum string
mums
Sample Output 1 :
mum s*/

#include<bits/stdc++.h>
using namespace std;

/*Find smallest substring
Send Feedback
Given two strings string1 and string2 (named large and small), find the smallest substring in string1 containing all characters of string2 in O(n). You need to return the output substring.
Note : The characters of string2 need not to be present in same order in string1. That is, we need a substring which contains all characters of string2 irrespective of the order.
Return null if no substring with all characters is present.
Input format :
Line 1 : String 1
Line 2 : String 2
Output Format :
Smallest substring
Constraints :
1 <= Length of string1 & string2 <= 10^4
Sample Input 1 :
Looks for minimum string
mums
Sample Output 1 :
mum s*/

// C++ program to find smallest window containing 
// all characters of a pattern. 
#include<bits/stdc++.h> 
using namespace std; 

const int no_of_chars = 256; 

// Function to find smallest window containing 
// all characters of 'pat' 
string findSubString(string str, string pat) 
{ 
	int len1 = str.length(); 
	int len2 = pat.length(); 

	// check if string's length is less than pattern's 
	// length. If yes then no such window can exist 
	if (len1 < len2) 
	{ 
		cout << "No such window exists"; 
		return ""; 
	} 

	int hash_pat[no_of_chars] = {0}; 
	int hash_str[no_of_chars] = {0}; 

	// store occurrence ofs characters of pattern 
	for (int i = 0; i < len2; i++) 
		hash_pat[pat[i]]++; 

	int start = 0, start_index = -1, min_len = INT_MAX; 

	// start traversing the string 
	int count = 0; // count of characters 
	for (int j = 0; j < len1 ; j++) 
	{ 
		// count occurrence of characters of string 
		hash_str[str[j]]++; 

		// If string's char matches with pattern's char 
		// then increment count 
		if (hash_pat[str[j]] != 0 && 
			hash_str[str[j]] <= hash_pat[str[j]] ) 
			count++; 

		// if all the characters are matched 
		if (count == len2) 
		{ 
			// Try to minimize the window i.e., check if 
			// any character is occurring more no. of times 
			// than its occurrence in pattern, if yes 
			// then remove it from starting and also remove 
			// the useless characters. 
			while ( hash_str[str[start]] > hash_pat[str[start]] 
				|| hash_pat[str[start]] == 0) 
			{ 

				if (hash_str[str[start]] > hash_pat[str[start]]) 
					hash_str[str[start]]--; 
				start++; 
			} 

			// update window size 
			int len_window = j - start + 1; 
			if (min_len > len_window) 
			{ 
				min_len = len_window; 
				start_index = start; 
			} 
		} 
	} 

	// If no window found 
	if (start_index == -1) 
	{ 
	cout << "No such window exists"; 
	return ""; 
	} 

	// Return substring starting from start_index 
	// and length min_len 
	return str.substr(start_index, min_len); 
} 

// Driver code 
int main() 
{ 
	string str = "this is a test string"; 
	string pat = "tist"; 

	cout << "Smallest window is : \n"
		<< findSubString(str, pat); 
	return 0; 
} 


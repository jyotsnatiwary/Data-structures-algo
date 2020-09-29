/*Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
Input Format :
String S
Output Format :
count of palindrome substrings
Constraints :
1 <= Length of S <= 1000
Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba").*/

#include<bits/stdc++.h>
using namespace std;
/*
int countPalindromeSubstrings(char s[]) {
	// Write your code here
	
}

int countPalindromes(string s) 
{ 
	unordered_map<string, int> m; 
	for (int i = 0; i < s.length(); i++) { 

		// check for odd length palindromes 
		for (int j = 0; j <= i; j++) { 

			if (!s[i + j]) 
				break; 

			if (s[i - j] == s[i + j]) { 

				// check for palindromes of length 
				// greater than 1 
				if ((i + j + 1) - (i - j) > 1) 
					m[s.substr(i - j, 
						(i + j + 1) - (i - j))]++; 

			} else
				break; 
		} 

		// check for even length palindromes 
		for (int j = 0; j <= i; j++) { 
			if (!s[i + j + 1]) 
				break; 
			if (s[i - j] == s[i + j + 1]) { 

				// check for palindromes of length 
				// greater than 1 
				if ((i + j + 2) - (i - j) > 1) 
					m[s.substr(i - j, 
						(i + j + 2) - (i - j))]++; 

			} else
				break; 
		} 
	} 
	return m.size(); 
} */

int length(char input[]) {
    int len = 0;
    for(int i = 0; input[i] != '\0'; i++) {
        len++;
    }
    return len;
}

int countPalindromeSubstrings(char s[]) {
	int count = 0;
	int len = length(s);
	for(int i = 0; i < len; i++) {
		int left = i-1;
		int right = i+1;
		count++;
		while(left >= 0 && right < len) {
			if(s[left] == s[right]) {
				count++;
				left--;
				right++;
			}
			else {
				break;
			}
		}

		if(i < len-1 && s[i] == s[i+1]) {
			left = i-1;
			right = i+2;
			count++;
			while(left >= 0 && right < len) {
				if(s[left] == s[right]) {
					count++;
					left--;
					right++;
				}
				else {
					break;
				}

			}
		}
	}
	return count;
}


/*Given two strings S1 and S2, find and return the minimum number of deletions to be made (total count of deletions in both strings) in order to make the strings anagram.
Anagram of a string is a string which is its permutation.
For example "bbaa" and "abab" are anagrams of each other but "bbaa" and "aaab" are not.
Input Format :
Line 1 : String1
Line 2 : String2
Output Format :
Number of deletions required
Contraints :
1<= Length of string <=10^4
Sample Input 1 :
cde 
abc
Sample Output 1 :
4
Sample Input 2 :
aab
aba
Sample Output 2 :
0*/

#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26; 
int makeAnagram(char str1[], char str2[]){
	
	int count1[CHARS] = {0}, count2[CHARS] = {0}; 

	// count frequency of each character in first string 
	for (int i=0; str1[i]!='\0'; i++) count1[str1[i]-'a']++; 

	// count frequency of each character in second string 
	for (int i=0; str2[i]!='\0'; i++) count2[str2[i]-'a']++; 

	int result = 0; 
	for (int i=0; i<26; i++) 
		result += abs(count1[i] - count2[i]); 
	return result; 
} 



/*Code : Check Permutation
Send Feedback
Given two strings, S and T, check if they are permutations of each other. Return true or false.
Permutation means - length of both the strings should same and should contain same set of characters. Order of characters doesn't matter.
Note : Input strings contain only lowercase english alphabets.


Input format :
Line 1 : String 1
Line 2 : String 2
Output format :
'true' or 'false'
Constraints :
0 <= |S| <= 10^7
0 <= |T| <= 10^7
where |S| represents the length of string, S.
Sample Input 1 :
abcde
baedc
Sample Output 1 :
true
Sample Input 2 :
abc
cbd
Sample Output 2 :
false*/

#include<bits/stdc++.h>
using namespace std;

bool isPermutation(char input1[], char input2[]) {
    // Write your code here
    int m=strlen(input1);
    int n=strlen(input2);
    if(m!=n) return false;
    int freq[256];
    for(int i=0;i<256;i++) freq[i]=0;
    for(int i=0;i<m;i++)
    {
    	freq[input1[i]]++;
    	freq[input2[i]]--;
	}
	for(int i=0;i<256;i++){
		if(freq[i]!=0) return false;
	}
	return true;
}



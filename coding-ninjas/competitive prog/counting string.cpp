To make a valid string t, you can just replace the letter 
A in S by any other letter, e.g. by replacing 'A' by 'B', 
we get t = ZBZ. Note that ZBZ is lexicographically larger than ZAZ. 
Reverse of t (i.e. ZBZ) is also lexicographically larger than reverse 
of s (i.e. ZAZ).

We will using dynamic programing (dp). Let F[i][ok1][ok2] 
is the number of the strings T that we can generated if we
 already got the first i-1 characters of it and ok1 and 
 ok2 represent the following information:
ok1 = 0 mean the first i - 1 characters of T still match 
the corresponding t - 1 characters of S. ok1 = 1 mean T is larger then S.
ok2 = 0 mean in the reversed order the first t - 1
 characters in T is already lexicographically larger 
 then the corresponding characters in S. ok2 = 0 if 
 otherwise.
Let N is the length of S The result of course will be
 F[0][0][0]. We can initialize the dp with
  F[N + 1][1][1] = 1. We will calculate F in the
   decreasing order of i. With each i, ok1, ok2, we try 
   to put all possible character in position i so that T 
   is never lexicographically smaller than S in the 
   original order:
   	
   	
//let s is 0-indexed
for (int i = N - 1; i > 0; i--)
    for (int ok1 = 0; ok1 <= 1; ok1++)
      for (int ok2 = 0; ok2 <= 1; ok2++) {
      //make sure that T is always lexicographically larger than S in original order
        for (char c = ok1 == 0 ? s[i] : 'A'; c <= 'Z'; c++) {
          int nextOk2 = ok2;
          if (c != s[pos]) {
            //if we put a character c > s[pos] in position pos of T then T became lexicographically larger than S in reversed order
            nextOk2 = c > s[pos];
          }

          f[pos][ok1][ok2] = (f[pos][ok1][ok2] + f[pos + 1][ok1 || c > s[pos]][nextOk2]) % MOD;
        }
      }
      
      
      
#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007

int solve(string X)
{
        long long ans = 0, temp = 0;
        for(int i = X.length()-1; i >= 0; i--)
        {
            temp = (26 * temp)%mod;
            if(i != X.length()-1)
            temp = (temp + ('Z' - X.at(i+1)))%mod;
            ans = (ans + ('Z'-X.at(i)) * temp)%mod;
            ans = (ans + 'Z'-X.at(i))%mod;
        }
        return ans;
}
int countStrings(char* s) {
    string x;
    for(int i=0;s[i]!='\0';i++)
    {
        x=x+s[i];
    }
  int ans=solve(x);
    return ans;
}
/*
#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;


int countStrings(char* s) {
    
    
    ll n = strlen(s);
	ll dp[n];
	dp[n-1] = 0;
	for (ll i = n-2; i >= 0; i--) {
		dp[i] = (((dp[i+1]*26) % mod) + ('Z' - s[i+1])%mod)%mod;
	}
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		sum += ((dp[i] + 1) * ('Z' - s[i])) % mod;
		sum %= mod;
	}
	return sum;
}
*/
/*
xample
Input 1:
ZAZ

Output 1:
25

Input 2:
XYZ

Output 2:
5
Explanation
Test #1: To make a valid string t, you can just replace the letter A in S by any other letter, e.g. by replacing 'A' by 'B', we get t = ZBZ. Note that ZBZ is lexicographically larger than ZAZ. Reverse of t (i.e. ZBZ) is also lexicographically larger than reverse of s (i.e. ZAZ).
Test #2: there are 5 valid strings: YYZ, ZYZ, XZZ, YZZ, ZZZ

=============================================editorial================================
DIFFICULTY:
Medium
PREREQUISITES:
Dynamic Programming
Problem
Given the string S count the number of the strings of same length T such that T is lexicographically bigger then S and when we reverse the order of characters in both of the two strings T is still lexicographically bigger than S.
Solution
We will using dynamic programing (dp). Let F[i][ok1][ok2] is the number of the strings T that we can generated if we already got the first i-1 characters of it and ok1 and ok2 represent the following information:
ok1 = 0 mean the first i - 1 characters of T still match the corresponding t - 1 characters of S. ok1 = 1 mean T is larger then S.
ok2 = 0 mean in the reversed order the first t - 1 characters in T is already lexicographically larger then the corresponding characters in S. ok2 = 0 if otherwise.
Let N is the length of S The result of course will be F[0][0][0]. We can initialize the dp with F[N + 1][1][1] = 1. We will calculate F in the decreasing order of i. With each i, ok1, ok2, we try to put all possible character in position i so that T is never lexicographically smaller than S in the original order:
//let s is 0-indexed
for (int i = N - 1; i > 0; i--)
    for (int ok1 = 0; ok1 <= 1; ok1++)
      for (int ok2 = 0; ok2 <= 1; ok2++) {
      //make sure that T is always lexicographically larger than S in original order
        for (char c = ok1 == 0 ? s[i] : 'A'; c <= 'Z'; c++) {
          int nextOk2 = ok2;
          if (c != s[pos]) {
            //if we put a character c > s[pos] in position pos of T then T became lexicographically larger than S in reversed order
            nextOk2 = c > s[pos];
          }

          f[pos][ok1][ok2] = (f[pos][ok1][ok2] + f[pos + 1][ok1 || c > s[pos]][nextOk2]) % MOD;
        }
      }

*/





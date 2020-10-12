/*Consider a very long K-digit number N with digits d0, d1, ..., dK-1 (in decimal notation; d0 is the most significant and dK-1 the least significant digit). This number is so large that we can't give it to you on the input explicitly; instead, you are only given its starting digits and a way to construct the remainder of the number.

Specifically, you are given d0 and d1; for each i = 2, di is the sum of all preceding (more significant) digits, modulo 10 — more formally, the following formula must hold: 

Determine if N is a multiple of 3.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers K, d0 and d1.
Output
For each test case, print a single line containing the string "YES" (without quotes) if the number N is a multiple of 3 or "NO" (without quotes) otherwise.

Constraints
1 = T = 1000
2 = K = 1012
1 = d0 = 9
0 = d1 = 9
Example
Input:
3
5 3 4
13 8 1
760399384224 5 1

Output:
NO
YES
YES
Explanation
Example case 1: The whole number N is 34748, which is not divisible by 3, so the answer is NO.

Example case 2: The whole number N is 8198624862486, which is divisible by 3, so the answer is YES.*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,d0,d1;
    long long int k;
    cin>>t;
    while(t--)
    {
        cin>>k>>d0>>d1;
        long long ini=(d0+d1)%10;
        long long dig=d0+d1+ini;
        long long b1,b2,b3,b4,q,rem,rim;
        b1=(2*ini)%10;
        b2=(4*ini)%10;
        b3=(8*ini)%10;
        b4=(6*ini)%10;
        rim=k-3;
        q=rim/4;
        rem=rim%4;
        dig+=q*(b1+b2+b3+b4);
        if(rem==3)dig+=b1+b2+b3;
        else if(rem==2)dig+=b1+b2;
        else if(rem==1)dig+=b1;
        if(dig%3==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }

}


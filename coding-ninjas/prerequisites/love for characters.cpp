Love for Characters
Send Feedback
Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.
Input:
First line contains an integer denoting length of the string.
Next line contains the string.
Constraints:
1<=n<=10^5
‘a’<= each character of string <= ‘z’
Output:
Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.
Sample Input:
6
aabsas
Sample output:
3 2 0

#include<bits/stdc++.h>
using namespace std;
int duplicate(int l, string ar)
{
    int s1=0, s2=0, s3=0, i=0;
    for(i=0;i<l;i++)
    {
        if(ar[i]=='a'){s1++;}
        if(ar[i]=='s'){s2++;}
        if(ar[i]=='p'){s3++;}
    }
    cout<<s1<<" "<<s2<<" "<<s3;
    return 0;
}
int main()
{
    int l;
    cin>>l;
    string s;
    cin>>s;
    duplicate(l,s);
	return 0;
}

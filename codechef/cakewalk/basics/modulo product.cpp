/*Modulo product
Send Feedback
Ninja got an easy assignment from his professor but he is unable to solve this. So he needs your help to complete the assignment.
In the assignment, he is given two integers A and B and he needs to output the product of all numbers from 1 to A modulo B, where 1 and A are inclusive.
For example, if A=5 and B=7, the answer will be ( 1 * 2 * 3 * 4 * 5 ) % 7 = 1 so the final answer is 1.
Input format:
The first line of input will contain an integer T, that denote the number of test cases.
Every test case will consist of one single line and that line will contain two integers: A and B.
Constraints:
1<=T<=50
1<=A<=10^9
1<=B<=10^5
Time Limit: 1 second
Output format:
For every test case, print the output in a newline.
Sample Input 1
4
8 10
5 140
18 19
20 21
Sample Output 1:
0
120
18
0*/

/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    // write your code
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int i,p=1;
        for(i=1;i<=a;i++){
            p=p*i;
        }
        cout<<p%b;
    }
    return 0;
}*/


#include<bits/stdc++.h>
using namespace std;

int fac(int a){
	if(a==0||a==1){
		return 1;
	}
	else{
		return a*fac(a-1);
	}
}
int main(){
    // write your code
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int i,p;
//        for(i=1;i<=a;i++) p=p*i;
		p=fac(a);
        cout<<p%b;
    }
    return 0;
}

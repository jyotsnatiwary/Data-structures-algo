/*Little Shino loves maths. Today her teacher gave her two integers. Shino is now wondering how many integers can divide both the numbers. She is busy with her assignments. Help her to solve the problem.

Input:
First line of the input file contains two integers, a and b.

Output:
Print the number of common factors of a and b*/

#include <bits/stdc++.h>
using namespace std;

/*int main() {
	int n1, n2, c=0;
	cin >> n1>>n2;
	//int max=(n1>n2)?n1:n2;										
	for(int i=1;i<=n1 && i<=n2;i++){
		if(n1%i==0 && n2%i==0) c++;
	}	
	cout<<c<<endl;
}*/
int gcd(int a, int b) {
   if (a == 0)
      return b;
   return gcd(b%a, a);
}
int countCommonDivisors(int a,int b) {
   int gcd_val = gcd(a, b); //get gcd of a and b
   int count = 0;
   for (int i=1; i<=sqrt(gcd_val); i++) {
      if (gcd_val%i==0) { // when'i' is factor of n
         if (gcd_val/i == i) //if two numbers are same
            count += 1;
         else
            count += 2;
      }
   }
   return count;
}
int main() {
	int n1, n2, c=0;
	cin >> n1>>n2;
	cout<<countCommonDivisors(n1,n2);
}
---


//best solution
#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b)
{
if (a == 0) return b;
return gcd(b % a, a);
}
int main() {
long long int a,b,c=0;
cin>>a>>b;
long long int n=gcd(a,b);
long long int result = 0;
long long int i;
for ( i=1; i<=sqrt(n); i++)
{
if (n%i==0)
{

if (n/i == i)
result += 1;
else
result += 2;
}
}
cout<<result;
}



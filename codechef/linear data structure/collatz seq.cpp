/*The rules for generating Collatz sequence are: If n is even: n = n / 2 If n is odd: n = 3n + 1 
if the starting number is 5 the sequence is: 5 -> 16 -> 8 -> 4 -> 2 -> 1 
It has been proved for almost all integers, that the repeated application of the above rule will result in a sequence that ends in 1. 
Write a java program to generate the Collatz sequence  if the input is an integer 'n' which denotes the first term of the sequence.

Test Case 1 : 
Sample Input : 5
Sample Output :  5 16 8 4 2 1


Test Case 2 : 
Sample Input : 3
Sample Output : 3 10 5 16 8 4 2 1


Test Case 3 : 
Sample Input : 18
Sample Output : 18 9 28 14 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	while (n != 1) 
    { 
        cout << n << " "; 
        if (n & 1) 
            n = 3*n + 1; 
        else
            n = n/2; 
    } 
    // Print 1 at the end 
    cout << n; 
}





import java.io.*; 

class col
{ 
	static void printCollatz(int n) 
	{ 
		while (n != 1) 
		{ 
			System.out.print(n + " "); 
			if ((n & 1) == 1) 
				n = 3 * n + 1; 

			else
				n = n / 2; 
		} 
	
		// Print 1 at the end 
		System.out.print(n); 
	} 
	public static void main (String[] args) 
	{ 
		printCollatz(6); 
	} 
} 


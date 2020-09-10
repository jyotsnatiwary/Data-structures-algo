/*There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top. 
The first input will an integer value 'n' indicating the total number of stairs 
to be covered. Output will be an integer number indicating the total number of ways to reach the top.

Test Case  1 :  Input: n = 1 Output: 1 Explanation : There is only one way to climb 1 stair 
Test Case  2 :  Input: n = 2 Output: 2 
Explanation : There are 2 ways: (1, 1) and (2) 
Test Case  3 :  Input: n = 4 Output: 5 Explanation : There are 5 ways : (1, 1, 1, 1), (1, 1, 2), (2, 1, 1), (1, 2, 1), (2, 2)

*/

#include<bits/stdc++.h>
using namespace std;

int fib(int n) 
{ 
    if (n <= 1) return n; 
    return fib(n - 1) + fib(n - 2); 
} /*
int countWays(int s) 
{ 
    return fib(s + 1); 
} */
int main() 
{ 
    int s;
	cin>>s; 
    cout <<fib(s+1); 
    return 0; 
} 

/*
class stairs { 
    static int fib(int n) 
    { 
        if (n <= 1) 
            return n; 
        return fib(n - 1) + fib(n - 2); 
    } 
    static int countWays(int s) 
    { 
        return fib(s + 1); 
    } 
    public static void main(String args[]) 
    { 
        int s = 4; 
        System.out.println(countWays(s)); 
    } 
}*/

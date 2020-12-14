/*Sort a Stack
Send Feedback
Given a stack, sort the elements inside that stack in ascending order using only push and pop operation. You can use one additional stack only.
For eg.

Input Stack :  5 (top)
               4
               3
               2
               1
Output Stack : 1 (top)
               2
               3
               4
               5
Input format
First line of input consists of an integer representing the size of the stack, N
Second line of input consistes of N space-separated integers representing the elements of the stack
Output format
The only line of output consists of the elements of the stack in sorted order (space-separated)
Constraints
0 <= N <= 1000
Time limit: 1 sec
Sample Input
5
1 2 3 4 5
Sample Output
1 2 3 4 5*/


#include <bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &input){
	stack<int> tmp;
    while(!input.empty()){
        int temp=input.top();
        input.pop();        
        while(!tmp.empty() && tmp.top()>temp){
            input.push(tmp.top());
            tmp.pop();            
        }
        tmp.push(temp);
    }    
    while(!tmp.empty()){
        input.push(tmp.top());
        tmp.pop();
    }
    return;
}

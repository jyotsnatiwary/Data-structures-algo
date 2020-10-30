/*Print Subsets of Array
Send Feedback
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 15
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 */

#include<vector>
void print(int input[],int n,vector<int>v)
{
    if(n==0)
    { 
        vector<int>::iterator ptr=v.begin();
       while(ptr!=v.end())
      {
     cout<<*ptr<<" ";
     ptr++;
      }
     cout<<"\n";
        return;
     
    }
print(input+1,n-1,v);
v.push_back(input[0]);
print(input+1,n-1,v);
return;
    
    
}
void printSubsetsOfArray(int input[], int n) {
	
    if(n==0)
    { 
        return;
    }    
    vector<int>v;
    print(input,n,v);   
}

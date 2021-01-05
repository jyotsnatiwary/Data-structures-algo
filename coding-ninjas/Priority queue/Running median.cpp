/*Running median
Send Feedback
You are given a stream of N integers. For every i-th integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.
Input Format :
The first line of input contains an integer N, denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.
Output Format :
Print the running median for every integer added to the running list in one line (space-separated).
Input Constraints
0 <= N <= 10^5
1 <= Ai <= 10^5

Time Limit: 1 sec
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3*/


#include <bits/stdc++.h>
using namespace std;
void printRunningMedian(int* arr, int n){
    priority_queue<int> max_half;
    priority_queue<int,vector<int>,greater<int> > min_half;       
    for(int i=0;i<n;i++){        
        if(max_half.empty()){
            max_half.push(arr[i]);
            cout<<arr[i]<<" ";
            continue;
        }        
        if(arr[i]<max_half.top()){
            max_half.push(arr[i]);            
            if(max_half.size()- min_half.size()>1){
                min_half.push(max_half.top());
                max_half.pop();
            }
            if((i+1)%2==0){
                int x=(max_half.top()+min_half.top())/2;
                cout<<x<<" ";
            }
            else{
                if(max_half.size()>min_half.size())
                    cout<<max_half.top()<<" ";
                else
                    cout<<min_half.top()<<" ";
            }
        }
        else{
            min_half.push(arr[i]);
            
            if(min_half.size()-max_half.size()>1){
                max_half.push(min_half.top());
                min_half.pop();
            }
            if((i+1)%2==0){
                int x=(max_half.top()+min_half.top())/2;
                cout<<x<<" ";
            }
            else{
                if(max_half.size()>min_half.size())
                    cout<<max_half.top()<<" ";
                else
                    cout<<min_half.top()<<" ";;
            }
        }
    }   
}




/*Merge K sorted arrays
Send Feedback
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format:
The first line of input contains an integer, that denotes value of k.
The following lines of input represent k sorted arrays. Each sorted array uses two lines of input. The first line contains an integer, that denotes the size of the array. The following line contains elements of the array.
Output Format:
The first and only line of output contains space separated elements of the merged and sorted array, as described in the task.
Constraints:
0 <= k <= 1000
0 <= n1, n2 <= 10000
Time Limit: 1 second
Sample Input 1:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1:
0 1 2 5 6 9 45 78 90 100 234*/

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<input.size();i++){
        for(int j=0;j<input[i]->size();j++){
            pq.push(input[i]->at(j));
        }
    }    
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

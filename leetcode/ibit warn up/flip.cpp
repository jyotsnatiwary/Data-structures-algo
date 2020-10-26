/*You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 = L = R = N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:

Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
For example,

S = 010

Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
Another example,

If S = 111

No operation can give us more than three 1s in final string. So, we return empty array [].*/

vector<int> Solution::flip(string A) {
    int n=A.length();

    //build new array of 1s and -1s
    vector<int> ar(n);
    for(int i=0; i<n; i++)
        if(A[i]=='1')ar[i]=-1;
        else ar[i]=1;

    //pair storing the answer
    pair<int, int> ans=make_pair(INT_MAX, INT_MAX);

    //basic kadane's algorithm implementation
    //we also storing the begin point for best till now
    int best_till_now=0,best_ending_here=0,l=0;
    for(int i=0; i<n; i++){
        if(best_ending_here+ar[i]<0){
            l=i+1;
            best_ending_here=0;
        }
        else best_ending_here+=ar[i];
        if(best_ending_here>best_till_now){
            best_till_now=best_ending_here;
            ans.first=l;
            ans.second=i;
        }
    }

    //if no valid subarray found
    if(ans.first==INT_MAX)return vector<int>();

    //return answer
    vector<int> ret;
    ret.push_back(ans.first+1);
    ret.push_back(ans.second+1);
    return ret;
}


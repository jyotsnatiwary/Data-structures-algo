/*Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.*/

int Solution::solve(vector<string> &A) {
    if(A.size() < 3) return 0;
    int n = A.size();
    vector<float> res = (vector<float>){stof(A[0]), stof(A[1])};
    for(int i = 2; i < n; ++i){
        res.push_back(stof(A[i]));
        float sm = res[0] + res[1] + res[2];
        if(sm > 1.0 && sm < 2.0) return 1;
        sort(res.begin(), res.end());
        if(sm <= 1.0) res.erase(res.begin());
        else res.pop_back();
    }
    return 0;
}

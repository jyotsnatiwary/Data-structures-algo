/*Tetrahedron
Send Feedback
Given a tetrahedron with verticies A, B, C and D. An ant is standing at vertex D. The ant won't sit idle. It will keep on moving from one vertex to another along some edge of the tetrahedron. Your task is to count the number of ways in which the ant can go from the initial vertex D to itself in exactly n steps. In other words, you are asked to find out the number of different cyclic paths with the length of n from vertex D to itself. As the number can be quite large, you should print it modulo 1000000007 (10^9?+?7).
alt text

Input Format :
Line 1 : Integer n (1?=?n?=?10^5) — the required length of the cyclic path
Output Format :
Return the only integer - the required number of ways modulo 1000000007 (10^9?+?7)
Sample Input :
2
Sample Output :
3*/
long long mod = 1e9+7;

long long count(vector<vector<long long>> &dp, int v, int n, int pos){
    if(pos== n ){
        if(v==0)
        return 1;
        return 0;
    }
    if(dp[pos][v] != -1)
        return dp[pos][v];
    long long ans = 0;
    for(int a=0; a<4; a++)
        if(a!=v)
            ans += count(dp,a,n,pos+1);
    return dp[pos][v] = ans%mod;
}

long long solve(int n)
{
	// Write your code here.
    vector<vector<long long>> dp(n+2, vector<long long> (4,-1));
    return count(dp,0,n,0);
}

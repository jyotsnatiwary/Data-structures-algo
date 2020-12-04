/*Code : MCM
Send Feedback
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format:
The first line of input contains an integer, that denotes the value of n. The following line contains n+1 integers, that denote the value of elements of array p[].
Output Format:
The first and only line of output prints the minimum number of multiplication needed.
Constraints :
1 <= n <= 100
Time limit: 1 second
Sample Input 1:
3
10 15 20 25
Sample Output 1:
8000
Sample Output Explanation:
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 15000.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000. */

#include<vector>
#include<climits>
int matrixChainMultiplication(int* arr,int n)
{
    n+=1;
    vector<vector<int> > dp(n, vector<int>(n));
    //Cost is zero when multiplying one matrix
    for(int i=1;i<n;i++)
        dp[i][i]=0;
    //L is matrix chain length
    for(int L=2;L<n;L++)
    {
        for(int i=1;i<n-L+1;i++)
        {
            int j=i+L-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                int q=dp[i][k]+dp[k+1][j]+(arr[i-1]*arr[k]*arr[j]);
                if(q<dp[i][j])
                    dp[i][j]=q;
            }
        }
    }
    return dp[1][n-1];
}

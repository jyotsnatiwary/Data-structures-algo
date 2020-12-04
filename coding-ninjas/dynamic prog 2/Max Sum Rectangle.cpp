/*Max Sum Rectangle
Send Feedback
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29*/

#include<bits/stdc++.h>  
using namespace std;  
  
int kadane(int* temp,int r)  
{  
   
    int maxSum=INT_MIN,sum=0;
    for(int i=0;i<r;i++)
    {
        sum=sum+temp[i];
        if(sum>maxSum)
        {
            maxSum=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
            
    }
    return maxSum;
}  
  
int findMaxSum(int**rectangle,int r,int c)  
{  
    int*temp=new int[r];
    int maxsum=INT_MIN;
   
    for(int left=0;left<c;left++)
    {
        // memset(temp,0,sizeof(temp));
        for (int i = 0; i < r; i++)
		{
			temp[i] = 0;
		}
        for(int right=left;right<c;right++)
        {
            for(int k=0;k<r;k++)
            {
                temp[k]=temp[k]+rectangle[k][right];
            }
            int sum=kadane(temp,r);
            if(sum>maxsum)
            {
                maxsum=sum;
            }
        }
    }
    return maxsum;
}  
int main()
{
    int ROW,COL;
    cin>>ROW>>COL;
   	int **s = new int*[ROW];
    for(int i = 0;i < ROW; i++){
        s[i] = new int[COL];
        for(int j = 0;j < COL; j++){
            cin>>s[i][j];
        }
    }
    cout<<findMaxSum(s,ROW,COL)<<endl;
    return 0;
}

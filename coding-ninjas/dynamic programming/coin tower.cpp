/*Coin Tower
Send Feedback
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
 Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.
Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
Sample Input 1 :
4 2 3
Sample Output 1 :
Whis
Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus*/

#include<iostream>
#include<string>
#include <vector>
using namespace std;

int BeerusWin(vector<int> &dp,int n,int x,int y){
    if(n==1 || n==x || n==y)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    
    int ans;
    //You'll have take care when n>x or <x, likewise for y
    if(n>x && n>y)
        ans=!BeerusWin(dp,n-1,x,y) || !BeerusWin(dp,n-x,x,y) || !BeerusWin(dp,n-y,x,y);
    else if(n>x && n<y)
        ans=!BeerusWin(dp,n-1,x,y) || !BeerusWin(dp,n-x,x,y);
    else if(n<x && n>y)
        ans=!BeerusWin(dp,n-1,x,y) || !BeerusWin(dp,n-y,x,y);
    else
        ans=!BeerusWin(dp,n-1,x,y);
    
    dp[n]=ans;
    return dp[n];
}


string findWinner(int n, int x, int y)
{
	// Write your code here .
    vector<int> dp(n+1,-1);
    
    int ans=BeerusWin(dp,n,x,y);
    
    if(ans)
        return "Beerus";
    else
        return "Whis";
}

/*Alice and Bob are studying for their class test together. The topic of the test is Prime Numbers. The preparation is getting too boring for their liking. To make it interesting, they turn it into a game. The winner will get an ice-cream treat from the other.

The game is called Count K-Primes. A number is a K-prime if it has exactly K distinct prime factors. The game is quite simple. Alice will give three numbers A, B & K to Bob. Bob needs to tell Alice the number of K-prime numbers between A & B (both inclusive). If Bob gives the correct answer, he gets a point. If not, Alice gets a point. They play this game T times.

Bob hasn't prepared so well. But he really wants to win the game. He wants you to tell him the correct answer.

Input
First line of input contains a single integer T, the number of times they play.
Each game is described in a single line containing the three numbers A,B & K.
Output
For each game, output on a separate line the number of K-primes between A & B.

Constraints:
1=T=10000
2=A=B=100000
1=K=5
Example:
Sample Input
4
2 5 1
4 10 2
14 15 2
2 20 3
Sample Output
4
2
2
0*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  vector<int> v(100002);
  for (int i = 2; i < 100002; i++)
  {
    if (v[i])
      continue;
    v[i] = 1;
    for (int j = 2 * i; j < 100002; j += i)
      v[j]++;
  }
  int t;
  cin >> t;
  while (t--)
  {
    int a,b,k;
    int cnt=0;
    cin>>a>>b>>k;
    for(int i=a;i<=b;i++)
    {
      if(v[i]==k)cnt++;
    }
    cout<<cnt<<endl;
  }
}


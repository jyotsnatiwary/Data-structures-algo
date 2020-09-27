#include<iostream>

#include<bits/stdc++.h>

using namespace std;

#define ff first 

#define ss second



int main()

 {

  int n;

  cin>>n;

  double dp[n+10];

  vector<pair<pair<int,int>,int> > v;

  for(int i=0;i<n;i++)

  {

  int a,b,c;

   cin>>a>>b>>c;

    v.push_back(make_pair(make_pair(a,b),c));

   }

    dp[0]=v[0].ss;

  //  cout<<dp[0]<<endl;

    for(int i=1;i<n;i++ )

     {

      double temp=-999999999.000;

      double x1=v[i].ff.ff;

      double y1=v[i].ff.ss;

      for(int j=0;j<i;j++)

       {

          double  x2=v[j].ff.ff;

          double   y2=v[j].ff.ss;

          double dec=(x1-x2)*((x1-x2))+(y1-y2)*(y1-y2);

          dec=sqrt(dec);

       //  cout<<"dec val "<<dec<<endl;

        temp=max(temp,dp[j]+v[i].ss-dec);

    }

    dp[i]=temp;

  // cout<<dp[i]<<endl;

  }

 printf("%.6lf\n",dp[n-1]);

 }
 
 
 Suppose we're standing at the i-th city and we wanna know 
 what is the maximal amount of fun we could get traveling 
 through some cities starting our trip from the 1-st one, 
 and store this value in dp[i]. Let's take a look on all 
 cities from which we could straight travel to the i-th one. 
 We will choose such city j that dp[j] - dist(i, j) is maximal 
 overall j < i, where dist(i, j) is Euclidean distance between 
 i-th and j-th cities.
  To complete calculating value of dp[i] 
 don't forget to addf[i] (amount of fun from visiting i-th city) 
 to it. Finally, the answer will be in dp[n].



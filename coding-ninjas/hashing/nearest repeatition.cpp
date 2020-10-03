/*Given an integer array, find and return the minimum distance between indexes of an element and its repetition.
Input Format :
Line 1 : Integer N, Size of array
Line 2 : Elements of the array (separated by space)
Output Format :
Print the minimum distance 
Contraints :
1<= N <=10^6
Sample Input 1:
6
1 3 1 5 4 3
Sample Output 1:
2
Sample Input 2:
7
5 47 82 4 4 6 2 
Sample Output 2:
1*/
#include <cmath>
#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
#include<unordered_map>

long long int minDistance(int arr[],int n){
long long int d=0;
long long int min=0;
int minc=0;
unordered_map<int,vector<int>>m;
for(long long int i=0;i<n;i++)
{   
   m[arr[i]].push_back(i);
}
unordered_map<int,vector<int>>::iterator it=m.begin();
while(it!=m.end())
  {int i=0;
   int j=1;
   vector<int>::iterator g =it->second.begin();
   while(g!=it->second.end())
   {
      d=*(g+1)-*(g);
      
   if(d>0)
   { 
       if(minc>d ||minc==0)
           minc=d;
       
   }
          g++;
   }
   if(minc>0)
   { 
       if(min>minc ||min==0)
           min=minc;
       
   }
   it++;   
  }
    if(min>0)
return(min);
    else 
        return(n);
    
}

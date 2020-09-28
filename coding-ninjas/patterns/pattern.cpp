#include<bits/stdc++.h>
using namespace std;
//#define min(a, b) ((a) < (b) ? (a) : (b))

void printPattern(int n){	
    int i,j,m,num=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}

int main(){
	int n; cin>>n;
	printPattern(n);
}

/*
void printPattern(int n){	
   int s=1;
for(int i=1;i<=n;i++){
   for(int j=s;j<s+n;j++){
       cout<<j<<" ";
   }
   cout<<"\n";
   
 if(i==(n+1)/2){
     if(n%2 !=0){
          s=n*(n-2)+1;
        }
        else{
          s= n*(n-1) +1;
      }
     }
      else if(i>(n+1)/2){
        s=s-2*n; 
       }
       else{
             s=s+2*n;
     } 
   }
}

int main(){
	int n; cin>>n;
	printPattern(n);
}*/


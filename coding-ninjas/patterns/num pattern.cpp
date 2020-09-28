#include<bits/stdc++.h>
using namespace std;
#define min(a, b) ((a) < (b) ? (a) : (b))

void printPattern(int n){	
	/* Don't write main().
 	Don't read input, it is passed as function argument.
	Print pattern as per the question.
	*/  
    int i,j,m,len=n*2-1;
    for(i=0;i<len;i++){
        for(j=0;j<len;j++){
            m=min(i,j);
            m=min(m,len-i-1);
            m=min(m,len-j-1);
            cout<<n-m<<" ";
        }
        cout<<endl;
    }
}

int main(){
	int n; cin>>n;
	printPattern(n);
}

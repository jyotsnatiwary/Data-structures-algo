#include <iostream>
#define op_io ios::sync_with_stdio(0);cin.tie(0);
#define MAX_N 100002
using namespace std;
 
int StringBinario[MAX_N];
int segTree[3*MAX_N];
 
void buildSegmentTree(int lo,int hi,int pos){
    if(lo == hi){
        segTree[pos] = StringBinario[lo];
        return;
    }
    int m = lo + (hi-lo)/2;
    buildSegmentTree(lo,m,2*pos+1);
    buildSegmentTree(m+1,hi,2*pos+2);
 
    int mf = (hi-lo)/2 + lo + 1;
    int numDigits = (hi - mf + 1);
    int leftMod = segTree[2*pos+1];
    if(numDigits%2 == 1){
        if(leftMod == 2)leftMod = 1;
        else if(leftMod == 1)leftMod = 2;
    }
    segTree[pos] = (leftMod + segTree[2*pos+2])%3;
}
int query(int lo,int hi,int qlo,int qhi,int pos){
    //if(qhi - qlo == 1) return (StringBinario[qhi] + 2*StringBinario[qlo])%3;
    if(qhi < lo || hi < qlo) return 0;
    if(qlo <= lo && qhi>=hi) {
        int d = 1;
        if((qhi - hi)%2 == 1) d*=2;
        return (d*segTree[pos])%3;
    }
 
    int m = lo + (hi-lo)/2;
    int l = query(lo,m,qlo,qhi,2*pos+1);
    int r = query(m+1,hi,qlo,qhi,2*pos+2);
    return (l+r)%3;
}
void update(int lo,int hi,int index,int pos){
    if(lo == hi){
        StringBinario[index] = 1;
        segTree[pos] = 1;
        return;
    }
    int m = lo + (hi-lo)/2;
    if(lo <= index && index <= m) update(lo,m,index,2*pos+1);
    else update(m+1,hi,index,2*pos+2);
 
    int mf = (hi-lo)/2 + lo + 1;
    int numDigits = (hi - mf + 1);
    int leftMod = segTree[2*pos+1];
    if(numDigits%2 == 1){
        if(leftMod == 2)leftMod = 1;
        else if(leftMod == 1)leftMod = 2;
    }
    segTree[pos] = (leftMod + segTree[2*pos+2])%3;
}
int main(){
    op_io
    int n;
    int numQueries;
    bool queryType;
    char ithDigit;
    int a;
    int b;
    int index;
 
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ithDigit;
        if(ithDigit == '0') StringBinario[i] = 0;
        else StringBinario[i] = 1;
    }
 
    buildSegmentTree(0,n-1,0);
 
    cin>> numQueries;
    for(int i=0;i<numQueries;i++){
        cin>>queryType;
        if(queryType){
            cin >> index;
            if(StringBinario[index] == 0) update(0,n-1,index,0);
        }
        else{
            cin >> a >> b;
            cout << query(0,n-1,a,b,0) << endl;
        }
    }
    return 0;
}

/*Code : In-place heap sort
Send Feedback
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2*/

#include <bits/stdc++.h>
using namespace std;
void up_heapify(int pq[],int n){
        int CI=n-1;
        while(CI>0){
            int PI=(CI-1)/2;            
            if(pq[PI]>pq[CI]){
                int temp=pq[PI];
                pq[PI]=pq[CI];
                pq[CI]=temp;
            }
            else
                break;
            CI=PI;
        }
}
void down_heapify(int pq[],int n){
        int pIndex=0;
        int lchild=1;
        int rchild=2;        
        while(lchild<n){
            int maxIndex=pIndex;
            
            if(pq[lchild]<pq[maxIndex])
                maxIndex=lchild;
            if(rchild<n && pq[rchild]<pq[maxIndex])
                maxIndex=rchild;
            
            if(maxIndex==pIndex)
                break;
            int temp=pq[maxIndex];
            pq[maxIndex]=pq[pIndex];
            pq[pIndex]=temp;
            
            pIndex=maxIndex;
            lchild=2*pIndex+1;
            rchild=2*pIndex+2;
        }
}
void printarr(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void heapSort(int input[], int n){//Assuem the first element is heap
    for(int i=1;i<n;i++){
        up_heapify(input,i+1);
        //printarr(input,n);
    }
    for(int i=n-1;i>=0;i--){
        int temp=input[0];
        input[0]=input[i];
        input[i]=temp;
        //printarr(input,n);
        down_heapify(input,i);
    }
}



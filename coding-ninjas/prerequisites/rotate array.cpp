Rotate array
Send Feedback
Given a random integer array of size n, write a function that rotates the given array by d elements (towards left)
Change in the input array itself. You don't need to return or print elements.
Input format :
Line 1 : Integer n (Array Size)
Line 2 : Array elements (separated by space)
Line 3 : Integer d
Output Format :
Updated array elements in a single line (separated by space)
Constraints :
0 <= N <= 10^7
0 <= d <= N
Sample Input 1:
7
1 2 3 4 5 6 7
2
Sample Output 1:
3 4 5 6 7 1 2
Sample Input 2:
7
1 2 3 4 5 6 7
0
Sample Output 2:
1 2 3 4 5 6 7

#include<bits/stdc++.h>
using namespace std;

/*void Rotate(int arr[], int d, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
    /*int i,a1[d],j,a2[size-d];
    for(i=0;i<=d;i++)
    {
        a1[i]=arr[i];
        reverse(a1,a1+d);
    }
    for(j=0;j>d;j++)
    {
        a2[j]=arr[j];
        reverse(a2+d+1,a2+size);
    }
}*/

void Rotate(int arr[], int d, int n) {
    d=d%n;
  int* temp=new int[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    int i;
    for(i=0;i<n-d;i++){
        arr[i]=arr[i+d];
    }
    for(int j=0;j<d;j++){
        arr[i++]=temp[j];
    }
    delete[] temp;
 
}

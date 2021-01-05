/*Check Max-Heap
Send Feedback
Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains true if it represents max-heap and false if it is not a max-heap.
Constraints:
1 <= N <= 10^5
1 <= Ai <= 10^5
Time Limit: 1 sec
Sample Input 1:
8
42 20 18 6 14 11 9 4
Sample Output 1:
true*/

bool checkhelper(int* arr,int n,int pa){
    if(pa>=n){
        return true;
    }
    bool bsdk=true;
    int l=pa*2+1,r=pa*2+2;
    if(l<n && arr[l] >arr[pa]){
        bsdk= false;
    }
    if(r<n && arr[r]>arr[pa]){
        bsdk= false;
    }
    if(checkhelper(arr,n,pa*2+1) && checkhelper(arr,n,pa*2+2) && bsdk){
        return true;
    }
    return false;
}

bool isMaxHeap(int arr[], int n){
	return checkhelper(arr,n,0);
}

/*Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

 

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]
 

Note:

1 <= arr.length <= 10000
0 <= arr[i] <= 9*/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int count = 0, n = arr.size();
        for(int i: arr)
            if(i == 0)
                ++count;
        for(int i = n - 1, j = n - 1 + count; i >= 0; --i, --j){
            if(arr[i] == 0) {
                if(j < n)
                    arr[j] = 0;
                --j;
            }
            if(j < n)
                arr[j] = arr[i];
        }
    }
};

/*python
i=0
while(i<len(arr)-1:
	if(arr[i]==0):
		arr.insert(i+1,0)
		del arr[len(arr)-1]
		i=i+2
	else:
		i=i+1*/

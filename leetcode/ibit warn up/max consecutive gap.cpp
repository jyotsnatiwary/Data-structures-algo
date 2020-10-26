/*Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.*/

int Solution::maximumGap(const vector<int> &A) {
vector nums=A;
sort(nums.begin(),nums.end());
int dif=0; int temp;
for(int i=1;i<nums.size();i++){
temp=(abs(nums[i]-nums[i-1]));
if(temp>dif)
dif=temp;
}
return dif;
}


/*Given a read only array of n + 1 integers between 1 and n, find one number that 
repeats in linear time using less than O(n) space 
and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1*/

###-editorial
int Solution::repeatedNumber(const vector<int> &nums) {
    
    int tortoise = nums[0];
    int hare = nums[0];
    do {
    tortoise = nums[tortoise];
    hare = nums[nums[hare]];
    } while (tortoise != hare);


    tortoise = nums[0];
    while (tortoise != hare) {
    tortoise = nums[tortoise];
     hare = nums[hare];
    }

return hare;
}

###-my ans
int Solution::repeatedNumber(const vector<int> &A) {
int B[A.size()]={0};
int i;
for(i=0;i<A.size();i++)
{
    B[A[i]]++;
    if( B[ A[i] ] >1)
    return A[i];
}
return -1;
}


//longest subarray with sum 0

/*Create a hash table H and store sum and its ending index as key-value pairs.
Declare a variable maxLen = 0, which will store the maximum length of subarray whose sum is zero.
Iterate through the array and for every A[i], calculate the sum from 0 to i.
If sum turns out to be 0, then update maxLen to i, if (maxLen < i).
Check if that sum is present in the hash table or not.
If exist, then update the maxLen if ( i - H[sum]> maxLen ) to i - H[sum].
If not, insert it in hashmap, H[sum] = i.
5. Return maxLen.*/

int maxLengthSubarraySumToZero(int A[], int n)
{
    Create a HashTable H
    int sum = 0
    int maxLen = 0
    for(i = 0 to n-1)
    {
        sum = sum + A[i]
        if (sum == 0)
        {
            if (maxLen < i)
            {
                maxLen = i+1
            }
        }
        else if(sum in H)
        {
            if(maxLen < i-H[sum])
            {
                maxLen = i-H[sum]
            }
        }
        else
            H[sum] = i
    }
    return maxLen
}

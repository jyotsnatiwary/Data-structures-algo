//reverse pair
/*If \text{start}start>=\text{end}end this implies that elements can no longer be broken further and hence we return 0
Otherwise, set \text{mid}=(\text{start} + \text{end})/2mid=(start+end)/2
Store countcount by recursively calling \text{mergesort\_and\_count}mergesort_and_count on range \text{[start,mid]}[start,mid] and \text{[mid+1,end]}[mid+1,end] and adding the results. This is the divide step on our routine, breaking it into the 2 ranges, and finding the results for each range separately
Now, we that we have separately calculated the results for ranges \text{[start,mid]}[start,mid] and \text{[mid+1,end]}[mid+1,end], but we still have to count the elements in \text{[start,mid]}[start,mid] that are greater than 2 * elements in \text{[mid+1,end]}[mid+1,end]. Count all such elements and add the result to \text{count}count
Finally, \text{merge}merge the array from \text{start}start to \text{end}end
Make 2 array : LL from elements in range \text{[start,mid]}[start,mid] and RR from elements in range \text{R[mid+1,end]}R[mid+1,end]
Keep pointers ii and jj to LL and RR respectively both initialized to start to the arrays
Iterate over kk from \text{start}start to \text{end}end and set \text{A[k]}A[k] to the smaller of \text{L[i]}L[i] or \text{R[j]}R[j] and increment the respective index
*/

void merge(vector<int>& A, int start, int mid, int end)
{
    int n1 = (mid - start + 1);
    int n2 = (end - mid);
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = A[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];
    int i = 0, j = 0;
    for (int k = start; k <= end; k++) {
        if (j >= n2 || (i < n1 && L[i] <= R[j]))
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

int mergesort_and_count(vector<int>& A, int start, int end)
{
    if (start < end) {
        int mid = (start + end) / 2;
        int count = mergesort_and_count(A, start, mid) + mergesort_and_count(A, mid + 1, end);
        int j = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (j <= end && A[i] > A[j] * 2LL)
                j++;
            count += j - (mid + 1);
        }
        merge(A, start, mid, end);
        return count;
    }
    else
        return 0;
}

int reversePairs(vector<int>& nums)
{
    return mergesort_and_count(nums, 0, nums.size() - 1);
}

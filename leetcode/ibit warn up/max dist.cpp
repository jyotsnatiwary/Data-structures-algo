/*Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the maximum value of j - i;



Example Input
Input 1:

 A = [3, 5, 4, 2]


Example Output
Output 1:

 2


Example Explanation
Explanation 1:

 Maximum value occurs for pair (3, 4).*/
 
 class Solution {
    public:
        int maximumGap(const vector<int> &num) {
            if (num.size() == 0) return -1;
            if (num.size() == 1) return 0;
            vector<pair<int, int> > toSort; 
            for (int i = 0; i < num.size(); i++) {
                toSort.push_back(make_pair(num[i], i));
            }
            sort(toSort.begin(), toSort.end());
            int len = toSort.size();
            int maxIndex = toSort[len - 1].second;
            int ans = 0;
            for (int i = len - 2; i >= 0; i--) {
                ans = max(ans, maxIndex - toSort[i].second);
                maxIndex = max(maxIndex, toSort[i].second);
            }
            return ans;
        }
};

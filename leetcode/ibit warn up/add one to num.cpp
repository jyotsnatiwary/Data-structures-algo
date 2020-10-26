/*Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.*/

class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            reverse(digits.begin(), digits.end());
            vector<int> ans;
            int carry = 1;
            for (int i = 0; i < digits.size(); i++) {
                int sum = digits[i] + carry;
                ans.push_back(sum%10);
                carry = sum / 10;
            }
            while (carry) {
                ans.push_back(carry%10);
                carry /= 10;
            }
            while (ans[ans.size() - 1] == 0 && ans.size() > 1) {
                ans.pop_back();
            }
            reverse(ans.begin(), ans.end());
            reverse(digits.begin(), digits.end());
            return ans;
        }
};

#############-fast
vector<int> Solution::plusOne(vector<int> &A) {
    int n=A.size()-1;
    int sum=A[n]+1;
    A[n]=sum%10;
    int carry=sum/10;
    for(int i=n-1;i>=0;i--)
    {
        int sum=A[i]+carry;
        A[i]=sum%10;
        carry=sum/10;
    }
    vector<int> B;
    if(carry==1)
    {
        B.push_back(1);
        for(int i=0;i<A.size();i++)
            B.push_back(A[i]);
        return B;
    }
    else 
    {
        bool done=false;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=0)
                done=true;
            if(done)
                B.push_back(A[i]);
        }
        
    }
}


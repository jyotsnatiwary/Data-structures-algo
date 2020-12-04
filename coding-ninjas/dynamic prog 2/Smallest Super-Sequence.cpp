/*Smallest Super-Sequence
Send Feedback
 Given two strings S and T with lengths M and N. Find and return the length of their shortest 'Super Sequence'.
 The shortest 'Super Sequence' of two strings is defined as the smallest string possible that will have both the given strings as its subsequences.
Note :
If the two strings do not have any common characters, then return the sum of the lengths of the two strings. 
Input Format:
The first only line of input contains a string, that denotes the value of string S. The following line contains a string, that denotes the value of string T.
Output Format:
Length of the smallest super-sequence of given two strings. 
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
ab
ac
Sample Output 1 :
3
Explanation of Sample Output 1 :
Their smallest super sequence can be "abc" which has length = 3.
Sample Input 2 :
pqqrpt
qerepct
Sample Output 2 :
9*/

int smallestSuperSequence(string str1, string str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    int ** superseq = new int * [len1 + 1];
    for (int i = 0; i <= len1; i++) {
      superseq[i] = new int[len2 + 1];
      for (int j = 0; j <= len2; j++) {
        if (i == 0) {
          superseq[i][j] = j;
        } else if (j == 0) {
          superseq[i][j] = i;
        } else if (str1[i - 1] == str2[j - 1]) {
          superseq[i][j] = 1 + superseq[i - 1][j - 1];
        } else {
          superseq[i][j] = 1 + min(superseq[i - 1][j], superseq[i][j - 1]);
        }
      }
    }
    int result = superseq[len1][len2];
    for (int i = 0; i <= len1; i++) {
      delete[] superseq[i];
    }
    delete[] superseq;
    return result;
}

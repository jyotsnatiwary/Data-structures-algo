/*Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.



Input Format:

The first and the only argument contains an integer, A.
Output Format:

Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:

1 <= A <= 1000
Examples:

Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]

Input 2:
    4

Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]*/
        
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
            int dir = 0;
            vector< vector<int> > matrix(n, vector<int> (n, 0));
            int i = 0, j = 0, k = 1;
            while (k <= n * n) {
                matrix[i][j] = k++;
                if (dir == 0){
                    j++;
                    if (j == n || matrix[i][j] != 0) dir = 1, j--, i++;
                } else
                if (dir == 1) {
                    i++;
                    if (i == n || matrix[i][j] != 0) dir = 2, i--, j--;
                } else
                if (dir == 2) {
                    j--;
                    if (j < 0 || matrix[i][j] != 0) dir = 3, j++, i--;
                } else
                if (dir == 3) {
                    i--;
                    if (i < 0 || matrix[i][j] != 0) dir = 0, i++, j++;
                }
            }
            return matrix;
        }
};

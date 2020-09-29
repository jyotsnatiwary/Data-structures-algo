/*For a given two-dimensional integer array/list of size (N x M), print it in a spiral form. That is, you need to print in the order followed for every iteration:
a. First row(left to right)
b. Last column(top to bottom)
c. Last row(right to left)
d. First column(bottom to top)
 Mind that every element will be printed only once.
Refer to the Image:
Alt txt

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

Second line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith row constitutes 'M' column values separated by a single space.
Output format :
For each test case, print the elements of the two-dimensional array/list in the spiral form in a single line, separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= M <= 10^3
Time Limit: 1sec
Sample Input 1:
1
4 4 
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16
Sample Output 1:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
Sample Input 2:
2
3 3 
1 2 3 
4 5 6 
7 8 9
3 1
10
20
30
Sample Output 2:
1 2 3 6 9 8 7 4 5 
10 20 30 */

/*void spiralPrint(int **input, int nRows, int mCols)
{
    //Write your code here
    if(nRows==0 || mCols==0) return;
    
    int i, rowStart=0, colStart=0;
    int num=nRows*mCols, count=0;
    
    while(count<num){
    	
    	for(i=colStart;count<num && i<mCols; ++i){
    		cout<<input[rowStart][i]<<" ";
    		count++;
		}
		rowStart++;
		
		for(i=rowStart; count<num && i<nRows; ++i){
			cout<<input[i][mCols-1]<<" ";
    		count++;
		}
		mCols--;
		
		for(i=mCols-1; count<num && i>=colStart; --i){
			cout<<input[nRows-1][i]<<" ";
    		count++;
		}
		nRows--;
		
		for(i=nRows-1; count<num && i>=rowStart; --i){
			cout<<input[i][colStart]<<" ";
    		count++;
		}
		colStart--;
	}
}*/

#include <iostream>
using namespace std;

void spiralPrint(int **a, int m, int n){
	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Print output and don't return it.
	*/
	int i, k = 0, l = 0; 
    /* k - starting row index  
        m - ending row index  
        l - starting column index  
        n - ending column index  
        i - iterator  
    */
    while (k < m && l < n) { 
        /* Print first row from remaining rows */
        for (i = l; i < n; ++i) { 
            cout << a[k][i] << " "; 
        } 
        k++; 
        /* Print last column from remaining columns */
        for (i = k; i < m; ++i) { 
            cout << a[i][n - 1] << " "; 
        } 
        n--; 
        /* Print last row from remaining rows */
        if (k < m) { 
            for (i = n - 1; i >= l; --i) { 
                cout << a[m - 1][i] << " "; 
            } 
            m--; 
        }   
        /* Print first column from remaining columns */
        if (l < n) { 
            for (i = m - 1; i >= k; --i) { 
                cout << a[i][l] << " "; 
            } 
            l++; 
        } 
    } 
}



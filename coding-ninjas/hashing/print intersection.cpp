/*Given two random integer arrays, print their intersection. That is, print all the elements that are present in both the given arrays.
Input arrays can contain duplicate elements.
Note : Order of elements are not important
Input format :
Line 1 : Integer N, Array 1 Size
Line 2 : Array 1 elements (separated by space)
Line 3 : Integer M, Array 2 Size
Line 4 : Array 2 elements (separated by space)
Output format :
Print intersection elements in different lines
Constraints :
0 <= M, N <= 5 * 10^7
Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2 
4 
3
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
2 
2
1*/

#include<bits/stdc++.h>
using namespace std;

void intersection(int input1[], int input2[], int size1, int size2) {
	input1.sort(input1, input1+size1);
	input2.sort(input2, input2+size2);
	int i=0, j=0;
	while(i<size1 && j<size2){
		if(input1[i]>input2[j]) j++;
		if(input1[i]<input2[j]) i++;
		if(input1[i]==input2[j]){
			cout<<input[i]<<endl;
			i++;
			j++;
		}
	}

}

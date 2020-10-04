Longest consecutive Sequence
Send Feedback
You are given with an array of integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
0 <= n <= 10^8
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 
9 
10 
11 
12
Sample Input 2 :
7
3 7 2 1 9 8 1
Sample Output 2 :
7
8
9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 
16

#include <unordered_map> 
#include<vector> 
using namespace std; 
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{ 
    unordered_map <int, bool> visitedElements ; 
    unordered_map <int, int> elementToIndexMapping; 
    for(int i = 0; i < n; i++)
    { 
        elementToIndexMapping[arr[i]] = i; 
        if(visitedElements.count(arr[i]) == 0)
        { 
            visitedElements[arr[i]] = true; 
        } 
    } 
    vector<int> longestSequence; 
    int globalMaxSequenceLength = 1; 
    int globalMinStartIndex = 0; 
    for(int i = 0; i < n; i++)
    { 
        int num = arr[i]; 
        int currentMinStartIndex = i; 
        int count = 0; int tempNum = num; 
        //Forward 
        while(visitedElements.count(tempNum) == 1 && visitedElements[tempNum] == true)
        { 
            visitedElements[tempNum] = false; 
            count++; 
            tempNum++; 
        } 
        //Backward 
        tempNum = num-1; 
        while(visitedElements.count(tempNum) == 1 && visitedElements[tempNum] == true)
        { 
            visitedElements[tempNum] = false; 
            count++; 
            currentMinStartIndex = elementToIndexMapping[tempNum]; 
            tempNum--; 
        } 
        if(count > globalMaxSequenceLength)
        { 
            globalMaxSequenceLength = count; 
            globalMinStartIndex = currentMinStartIndex; 
        } 
        else if(count == globalMaxSequenceLength) 
        { 
            if(currentMinStartIndex < globalMinStartIndex) 
            { 
                globalMinStartIndex = currentMinStartIndex; 
            } 
        } 
    } 
    int globalStartNum = arr[globalMinStartIndex]; 
    longestSequence.push_back(globalStartNum); 
    globalMaxSequenceLength--; 
    while(globalMaxSequenceLength != 0)
    { 
        globalStartNum++; 
        longestSequence.push_back(globalStartNum); 
        globalMaxSequenceLength--; 
    } 
    return longestSequence; 
}

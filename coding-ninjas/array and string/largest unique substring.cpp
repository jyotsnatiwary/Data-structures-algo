/*Given a string S, find the largest substring with no repetition i.e. largest substring which contain all unique characters.
Input Format :
String S
Output Format :
Largest unique substring
Constraints :
1 <= Length os String S <= 10^3
Sample Input:
abcdabceb
Sample Output:
dabce*/

#include<bits/stdc++.h>
using namespace std;

/*void findLargestUniqueSubstring(char input[], char output[]){
	// Write your code here
    int len=0,i=0;
	while(input[i] != ‘\0’){
		len++;
		i++;
	}
	int res=0;
	int i=0;
}
#define NO_OF_CHARS 256 

int longestUniqueSubsttr(string str) 
{ 	// last index of all characters is initialized 
	// as -1 
	vector<int> lastIndex(NO_OF_CHARS, -1); 

	// Initialize start of current window 
	int i = 0; 

	// Move end of current window 
	for (int j = 0; j < n; j++) { 
		i = max(i, lastIndex[str[j]] + 1); 
		res = max(res, j - i + 1); 
		lastIndex[str[j]] = j; 
	} 
	return res; 
} 
*/
// input - given string
// output - output string that contains largest unique substring
void findLargestUniqueSubstring(char input[], char output[]) {
  // Write your code here
  long int i = 0;
  int start = 0;
  int end = 0;
  int ml = 0;
  int ms = 0;
  int me = 0;
  int cl = 0;
  int b = 0;
  while (input[i] != '\0') {
    start = i;
    end = i + 1;
    while (input[start] != input[end] && input[end] != '\0') {
      end++;
    }
    for (int a = start + 1; a < end; a++) {
      for (b = a + 1; b < end; b++)
        if (input[a] == input[b])
          break;
      end = b;

    }
    cl = end - start;
    if (ml < cl) {
      ms = start;
      me = end;
      ml = cl;
    }

    i++;
  }
  int j = 0;
  for (int k = ms; k < me; k++) {
    output[j] = input[k];
    j++;
  }
  output[j] = '\0';
}


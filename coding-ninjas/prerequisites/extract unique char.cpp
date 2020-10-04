Extract Unique characters
Send Feedback
Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde


#include<bits/stdc++.h>
char* uniqueChar(char *str){
    // Write your code here
    int count = 0;
    while(str[count] != '\0'){
        count++;
    }
    int index = 0;
 
    for (int i=0; i<count;i++){
 
        int j; 
        for (j=0; j<=i; j++)  
            if (str[i] == str[j]) 
                break; 
 
 
        if (j == i) 
            str[index++] = str[i]; 
    }
    str[index]='\0';
    return str;
}

/*Palindrome Pair
Send Feedback
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.
Input Format :
The first line of the test case contains an integer value denoting 'n'.

The following contains 'n' number of words each separated by a single space.
Output Format :
The first and only line of output contains true if the conditions described in the task are met and false otherwise.
Constraints:
0 <= n <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome
Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'*/

#include<bits/stdc++.h> 
#include <string>
#include <vector>
using namespace std; 

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    // For user
    void add(string word)
    {
        if (add(root, word))
        {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
    bool isPalindromeHelp(string str) 
  { 
    int len = str.length(); 
  
    // compare each character from starting 
    // with its corresponding character from last 
    for (int i = 0; i < len/2; i++ ) 
        if (str[i] != str[len-i-1]) 
            return false; 
  
    return true; 
  } 

    bool isPalindromePair(vector<string> words)
    {
		//Write your code here
        if(words.size()==0){
            return false;
        }
        
        if(words.size()==1){
            return isPalindromeHelp(words[0]);
        }
        
        for (int i = 0; i< words.size()-1; i++) 
     { 
        for (int j = i+1; j< words.size(); j++) 
         { 
            string check_str; 
  
            check_str = words[i] + words[j]; 
  
     
            if (isPalindromeHelp(check_str)) 
                return true; 
  
            
            check_str = words[j] + words[i]; 
            if (isPalindromeHelp(check_str)) 
                return true; 
        } 
    } 
    return false; 
  }

};

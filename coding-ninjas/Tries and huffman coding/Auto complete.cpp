/*Auto complete
Send Feedback
Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Note : Order of words does not matter.
Input Format :
The first line of input contains an integer, that denotes the value of n.
The following line contains n space separated words.
The following line contains the word w, that has to be auto-completed.
Output Format :
Print all possible words in separate lines.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
7
do dont no not note notes den
no
Sample Output 2 :
no
not
note
notes
Sample Input 2 :
7
do dont no not note notes den
de
Sample Output 2 :
den
Sample Input 3 :
7
do dont no not note notes den
nom
Sample Output 3 :
(Empty) There is no word which starts with "nom"*/

#include <iostream>
#include <string>
using namespace std;
#include <vector>


class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
    // code
    
    
    void print(TrieNode *root, string s){
        if(root == NULL){
            return;
        }
        if(root->isTerminal){
            cout<<s<<endl;
        }
        for(int i=0;i<26;i++){
            if(root->children[i]){
                string t = s+root->children[i]->data;
                print(root->children[i],t);
            }
        }
    }
    void helper(TrieNode *root, string pattern , string output){
        if(root == NULL){
            return ;
        }
        if(pattern.size() == 0){
            if(root->isTerminal){
                cout<<output<<endl;
            }
            for(int i=0;i<26;i++){
                if(root->children[i]!=NULL){
                    string s = output + root->children[i]->data;
                    print(root->children[i],s);
                }
            }
            return ;
        }
        int index = pattern[0]-'a';
        output += pattern[0];
        helper(root->children[index],pattern.substr(1),output);
    }
    void autoComplete(vector<string> input, string pattern) {
        // Complete this function
        // Print the output as specified in question
        for(int i=0;i<input.size();i++){
            insertWord(input[i]);
        }
        string output = "";
        helper(root,pattern,output);
    }
};

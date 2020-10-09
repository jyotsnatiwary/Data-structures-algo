/*Generate all parenthesis
Send Feedback
Given n pairs of parentheses, write a function to generate and print all combinations of well-formed parentheses. That is, you need to generate all possible valid set of parenthesis that can be formed with given number of pairs.
Input format :
Integer n
Output format :
Print all possible valid parenthesis in different lines
Note: Order in which different combinations of well-formed parentheses are printed in different lines doesn't matter.
Constraints :
1 <= n <= 10
Sample Input :
3
Sample Output :
((()))
(()())
(())()
()(())
()()()*/

# include<stdio.h> 
# define MAX_SIZE 100 

void _printParenthesis(int pos, int n, int open, int close); 

void printWellFormedParanthesis(int n) 
{ 
	if(n > 0) _printParenthesis(0, n, 0, 0); 
	return; 
}	 

void _printParenthesis(int pos, int n, int open, int close) 
{ 
	static char str[MAX_SIZE];	
	if(close == n) 
	{ 
		printf("%s \n", str); 
		return; 
	} 
	else
	{ 
		if(open > close) 
		{ 
			str[pos] = ')'; 
			_printParenthesis(pos+1, n, open, close+1); 
		} 		
		if(open < n) 
		{ 
		str[pos] = '('; 
		_printParenthesis(pos+1, n, open+1, close); 
		} 
	} 
} 





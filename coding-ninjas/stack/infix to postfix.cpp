/*Infix to postfix
Send Feedback
Given an infix expression S in the form of a string. 
You need to convert and print that input expression in 
postfix form. After that, evaluate and print the result 
of given expression in next line.
Input Format :
Infix expression
Output Format :
Line 1 : Corresponding postfix expression
Line 2 : Result of input expression after evaluation
Constraints :
1 <= Length of S <= 100
Sample Input 1 :
3+4
Sample Output 1 :
34+
7*/


#include<stack>
int length(char input[]){
	int i=0;
	while(input[i])
		i++;
	return i;
}

int priority(char c)
{
	if(c == '*' || c == '/') return 2;
	else if(c == '+' || c == '-') return 1;
	else return -1;
}

int evaluate(int op1, int op2, char operate) {
	switch (operate) {
		case '*': return op2 * op1;
		case '/': return op2 / op1;
		case '+': return op2 + op1;
		case '-': return op2 - op1;
		default : return 0;
	}
}
void infixToPostfix(char *input)
{
stack<char> s;
int len = length(input),index=0;
char output[1000];
for(int i = 0; i < len; i++)
{
if((input[i] >= '0' && input[i] <= '9')) {
output[index++] = input[i];
} else if(input[i] == '(') {
s.push('(');
} else if(input[i] == ')')
{

while(!s.empty() && s.top() != '(')
{
char c = s.top();
s.pop();
output[index++] = c;
}
if(s.top() == '(')
{
char c = s.top();
s.pop();
}
} else{
while(!s.empty() && priority(input[i]) <= priority(s.top()))
{
char c = s.top();
    s.pop();
output[index++]= c;
}
s.push(input[i]);
}
}

while(!s.empty())
{
char c = s.top();
s.pop();
output[index++] = c;
}
output[index] = '\0';
cout << output << "\n";
//copying to change input expression from calling function evaluatePostfix
int i=0;
while(i < length(output)){
input[i] = output[i];
i++;
}
input[i] = '\0';
}
void evalPostfix(char postfix[]) {
stack<int> s;
int i = 0;
char ch;
int val;
int len = length(postfix);
while (i < len) {
ch = postfix[i];
if (isdigit(ch)) {
s.push(ch-'0');
}
else {
int op1 = s.top();
s.pop();
int op2 = s.top();
s.pop();
val = evaluate(op1, op2, ch);
s.push(val);
}
i++;
}
cout << val;
}
void evaluatePostfix(char exp[]) {
infixToPostfix(exp);
evalPostfix(exp);
}

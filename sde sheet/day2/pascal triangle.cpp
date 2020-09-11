//pascal triangle print
//print 5th row and 6th column element
//print a particular row of triangle

// C++ program for Pascal’s Triangle 
// A O(n^2) time and O(1) extra space 
// function for Pascal's Triangle 

void printPascal(int n) 
{ 	
for (int line = 1; line <= n; line++) 
{ 
	int C = 1; // used to represent C(line, i) 
	for (int i = 1; i <= line; i++) 
	{ 
		// The first value in a line is always 1 
		cout<< C<<" "; 
		C = C * (line - i) / i; 
	} 
	cout<<"\n"; 
} 
} 
int main() 
{ 
	int n = 5; 
	printPascal(n); 
	return 0; 
} 


//print nth row
void generateNthrow(int N) 
{ 
	// nC0 = 1 
	int prev = 1; 
	cout << prev; 

	for (int i = 1; i <= N; i++) { 
		// nCr = (nCr-1 * (n - r + 1))/r 
		int curr = (prev * (N - i + 1)) / i; 
		cout << ", " << curr; 
		prev = curr; 
	} 
} 
int main() 
{ 

	int N = 5; 
	generateNthrow(N); 
	return 0; 
} 



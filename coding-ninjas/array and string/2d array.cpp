#include <iostream>
using namespace std;

void printArray(int input[][100], int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0;  j < n; j++) {
			cout << input[i][j] << " ";
		}
		cout << endl;	
	}

}

int main() {
	int a[100][100];
	int m, n;
	
	// Rows - m
	// Cols - n
	cin >> m >> n;


	// Taking input
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
    }

	printArray(a, m, n);

}


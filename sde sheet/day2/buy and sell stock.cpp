//buy and sell stock
/*Find the local minima and store it as starting index. If not exists, return.
Find the local maxima. and store it as ending index. If we reach the end, set the end as ending index.
Update the solution (Increment count of buy sell pairs)
Repeat the above steps if end is not reached.*/

void stockBuySell(int price[], int n) 
{ 
	// Prices must be given for at least two days 
	if (n == 1) return; 
	int i = 0; 
	while (i < n - 1) { 
		// Find Local Minima 
		// Note that the limit is (n-2) as we are comparing present element to the next element 
		while ((i < n - 1) && (price[i + 1] <= price[i])) i++; 

		// If we reached the end, break  
		if (i == n - 1) break; 

		// Store the index of minima 
		int buy = i++; 

		// Find Local Maxima 
		// Note that the limit is (n-1) as we are comparing to previous element 
		while ((i < n) && (price[i] >= price[i - 1])) i++; 

		// Store the index of maxima 
		int sell = i - 1; 

		cout << "Buy on day: " << buy 
			<< "\t Sell on day: " << sell << endl; 
	} 
} 

int main() 
{ 
	// Stock prices on consecutive days 
	int price[] = { 100, 180, 260, 310, 40, 535, 695 }; 
	int n = sizeof(price) / sizeof(price[0]); 

	// Fucntion call 
	stockBuySell(price, n); 

	return 0; 
} 



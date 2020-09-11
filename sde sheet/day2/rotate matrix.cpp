//rotate matrix
void rotate(int **input, int n){    
     for(int i=0;i<n;i++){
     	for(int j=0;j<i;j++) swap(input[i][j],input[j][i]);
	 }
	 for (int i = 0; i < n/2; ++i) 
    {
        for(int j = 0; j < n; j++)
        {
            std::swap(input[i][j], input[n-i-1][j]);
        }
    }
}

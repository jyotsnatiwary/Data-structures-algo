//if element is 0 set entire row n coulumn to 0

int setZero(int[][] matrix){
	int c=1, rows=matrix.length, cols=matrix[0].length;
	for(int i=0; i <rows;i++){
		if(matrix[i][0]==0) c=0;
		for(int j=0; j<cols;j++){
			if(matrix[i][j]==0) matrix[i][0]=matrix[0][j]=0;
		}
	}
	for(int i=rows-1;i>=0;i--){
		for(int j=cols-1;j>=1;j--){
			if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
		}
		if(c==0) matrix[i][0]=0;
	}
}

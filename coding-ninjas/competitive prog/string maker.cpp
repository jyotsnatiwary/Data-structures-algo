char a[55], b[55],c[55]
int dp[55][55][55],mod=100000007; 
solver(intx,int y, int z)
{
	if(z==0) return 1;
	if((x<=0&&y<=0) return 0;
	if (dp!=1) return dp[x][y][z];
	int way=0;
	for(i=x-1,i>=0;i--)
	{
		if(a[i]==c[z-1]) update ways
		ways = (ways+solver(i,y,z-1))%mod;
	}
	same for b
}

solve(char A[],B,C)
{
	for(i=0;A[i];i++)
	{
		a[i]=A[i]
	same for B C
	for(i=0;i<52;i++)
		for(j)
			for(k)
				dp[i][j][k]=-1
	return solver(strlen(A), B,C)	
	}
}

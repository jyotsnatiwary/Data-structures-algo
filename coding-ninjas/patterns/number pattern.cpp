void printPattern(int n){
    int a=0, b=n-1,c=1;
    int arr[n][n];
    for(int i=0; i<n; i++)
    {
        if(i%2==0){
            for(int j=0; j<n; j++){
                arr[a][j] = c;
                c++;
            }
            a++;
        }
        else{
            for(int j=0; j<n; j++){
                arr[b][j] = c;
                c++;
            }
            b--;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}


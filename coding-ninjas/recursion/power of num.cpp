int power(int x, int n) {
    if(x==0) return 0;
    if(n==0) return 1;
    return x*power(x, n-1);

}

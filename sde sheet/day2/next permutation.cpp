//next permutation
//using nextpermutation library

//traverse from back and a[i]<a[i+1], swap elements and reverse

void nextp(int a[]){
	if (a==null || a.length<=1) return;
	int i=a.length-1;
	if(i>=0){
		int j=a.length-1;
		while(a[j]<=a[i]) j--;
		swap(a,i,j);
	}
	reverse(a,i+1,a.length-1);
}
void reverse(int a[], int i, int j){
	while(i<j) swap(a,i++,j--);
}

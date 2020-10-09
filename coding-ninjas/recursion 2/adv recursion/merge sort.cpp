void merging(int b[],int srt,int ed){
  int *array = new int[ed+1];
  int middle = (srt+ed)/2;
  int i=srt,j=middle+1,h=0;
  while(i<=middle && j<=ed){
    if(b[i]>b[j]){
      array[h] = b[j];
        j++;
        h++;
    }else{
      array[h] = b[i];
        i++;
        h++;
    }
  }
  if(i!=middle+1){
    for(i;i<=middle;i++){
      array[h] = b[i];
      h++;
    }
  }
  else if(j!=ed+1){
    for(j;j<=ed;j++){
      array[h] = b[j];
      h++;
    }
  }
  for(int i=srt;i<=ed;i++)
  {
    b[i]=array[i-srt];
  }
}

void merge(int a[],int s,int e){
  if(s>=e ){
    return;
  }
  int mid = (s+e)/2;
  merge(a,s,mid);
  merge(a,mid+1,e);
  merging(a,s,e);
  
}


void mergeSort(int input[], int size){
	// Write your code here
 int start =0,end = size-1;
  merge(input,start,end);
  
}


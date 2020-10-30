//num of numbers with duplicates
/*Code : No. of numbers - with duplicates
Send Feedback
Given a number n, find number of numbers that are greater than n using the same set of digits as n. n might have duplicate digits.
Input Format :
Integer n
Output Format :
Count of greater numbers
Sample Input :
122
Sample Output :
2*/

#include<iostream>
using namespace std;
long helper(long *arr,long n,long *freq,long *fact,long deno)
{
    if(n==1)
        return(0);
    long  ans=0;
    
    for(int i=arr[0]+1;i<10;i++)
    {
        if(freq[i]>0)
        {
            ans+=(fact[n-1]*freq[i])/deno;
          
            
        }
        else
            continue;      
    }      
    deno=deno/fact[freq[arr[0]]];
    freq[arr[0]]--;
    if(freq[arr[0]]>0)
        deno=deno*fact[freq[arr[0]]];
    ans+=helper(arr+1,n-1,freq,fact,deno);
    return(ans);    
}
long numberOfNumbersWithDuplicates(long num){
	// Write your code here
long n=0;
long temp=num;
while(temp>0)
{
    n++;
    temp=temp/10;
}
long *arr=new long [n];
long freq[10]={0};
long *fact=new long [n+1];
fact[0]=1;
for(long i=0;i<n;i++)
{
    arr[n-1-i]=num%10;
    num=num/10;
    freq[arr[n-1-i]]++;
    fact[i+1]=(i+1)*fact[i];
}
long denominator=1;
for(long  i=0;i<10;i++)
{
    if(freq[i]!=0)
        denominator*=fact[freq[i]];
    else
        continue;
}    
    long ans=helper(arr,n,freq,fact,denominator);
    delete [] arr;
    delete [] fact;
    return(ans);
}

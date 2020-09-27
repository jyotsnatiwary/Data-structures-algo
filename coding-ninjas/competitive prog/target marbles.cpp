
void solve(int tar,int* arr,int n)
{
	int start=0,end=0;
	int sum=arr[0];
	while(sttart<n && end<n)
	{
		if(sum<tar)
		{
			end++;
			sum+=arr[end];
		}
		else if(sum>tar)
		{
			sum-=arr[start];
			start++;
		}
		else
		{
			cout<<"true"<<endl;
			for(int i=start;i<=end;i++)
			{
				cout<<arr[i]<<" ";
			}
			return;
		}
	}
	cout<<"false"<<endl;
}
int main()

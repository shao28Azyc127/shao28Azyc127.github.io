#include<bits/stdc++.h>
using namespace std;
int a[10005];
int b[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,sum=0,g=0;
	cin>>n>>d;
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		int t=0;
		for(int j=2;j<n;j++)       
		{
			t+=a[j-1];
			if(i<j&&i!=1)
			{
				continue;
			}   
			if(b[i]>b[j])                            
			{
				int q=(ceil(t/d)-g)*b[i];
				sum+=q;
				g=ceil(t/d)*d-t;
			}
		}
	}
	cout<<sum;
	return 0;
}
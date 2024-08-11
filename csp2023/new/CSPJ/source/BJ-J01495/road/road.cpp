#include <bits/stdc++.h>
using namespace std;
int v[100005];
int a[100005];
int dp[100005];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<n;i++)
	{
		cin>>v[i];
	}
	int minx=1e9;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		minx=min(minx,a[i]);
	}
	if(minx==a[1]) 
	{
		long long sum=0;
		for(int i=1;i<n;i++) sum+=v[i];
		if(sum%d==0)
		{
			cout<<sum/d*minx;
		}
		else
		{
			cout<<(sum/d+1)*minx;
		}
		return 0;
	}
	
	return 0;
}

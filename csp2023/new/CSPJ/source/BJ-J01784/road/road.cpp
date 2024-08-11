#include<bits/stdc++.h>
using namespace std;
long long a[1000005],v[1000005],dp[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,i,m=0x3f3f3f3f,d;
	memset(dp,127,sizeof(dp));
	cin>>n>>d;
	for(i=2;i<=n;i++)
	{
		cin>>v[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[0]=0;
	dp[1]=0;
	for(i=2;i<=n;i++)
	{
		long long t=ceil(v[i]*1.0/d*1.0);
		m=min(m,a[i]);
		dp[i]=dp[i-1]+t*m;
	}
	cout<<dp[n];
	return 0;
}
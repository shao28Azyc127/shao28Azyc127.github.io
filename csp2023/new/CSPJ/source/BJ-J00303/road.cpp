#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,inf=1e12;
int read()
{
	int ret=0,f=1;char c=getchar();
	while(!(c>='0'&&c<='9'))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret*f;
}
int n,dis[N],d,pre[N],v[N],dp[N],can[N],minn[N];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),d=read();
	for(int i=1;i<n;i++)
	{
		dis[i+1]=read();pre[i+1]=pre[i]+dis[i+1];
	}
	for(int i=0;i<=n;i++)
	{
		minn[i]=inf;
	}
	for(int i=1;i<=n;i++)
	{
		v[i]=read();
		dp[i]=inf;
		minn[i]=min(minn[i-1],v[i]);
	}
	dp[1]=0;can[1]=0;
	for(int i=2;i<=n;i++)
	{
		int last=can[i-1];
		if(last>=pre[i]) 
		{
			dp[i]=dp[i-1];
			can[i]=last;
			continue;
		}
		int need=pre[i]-last;
		dp[i]=dp[i-1]+minn[i-1]*((need-1)/d+1);
		can[i]=can[i-1]+d*((need-1)/d+1);
	}
	cout<<dp[n];
	return 0;
}
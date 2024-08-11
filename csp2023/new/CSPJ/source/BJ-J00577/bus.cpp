#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
	int start,end,time;
}a[1000005];
int dp[1000005];
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].start>>a[i].end>>a[i].time;
	}
	for(int i=1;i<=1000005;i++)
	{
		dp[i]=1000000000;
	}
	dp[1]=0;
	for(int i=1;i<=m;i++)
	{
		dp[a[i].end]=min(dp[a[i].end],dp[a[i].start]+1);
	}
	if(dp[n]==1000000000)
	{
		cout<<-1;
		return 0;
	}
	else
	{
		if(dp[n]%k!=0)
		{
			dp[n]+=k;
			dp[n]-=dp[n]%k;
		}
		cout<<dp[n];
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long a[3010],b[3010],c[3010],d[3010],dp[3010][3010];
long long h[3010],ne[6010],t[6010],k,ans;
void add(long long x,long long y)
{
	t[++k]=y;
	ne[k]=h[x];
	h[x]=k;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	long long n,i,j,l,u,v;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		d[i]=(a[i]+b[i]-1)/b[i];
	}
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	for(i=1;i<=n;i++)
		dp[0][i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(l=h[j];l;l=ne[l])
			{
				int y=t[l];
				dp[i][j]=min(dp[i][j],max(dp[i-1][y],d[j]+i-1));
			}
		}
	}
	ans=dp[n][1];
	for(i=2;i<=n;i++)
		ans=min(ans,dp[n][i]);
	cout<<ans;
	return 0;
}

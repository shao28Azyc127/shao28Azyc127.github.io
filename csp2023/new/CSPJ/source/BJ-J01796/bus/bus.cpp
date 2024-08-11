#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int g[N][N];
int n,m,k,a,b,c,ans=2147483647;
void dfs(int x,int t)
{
	if(x==n) ans=min(ans,t);
	int i;
	for(i=1;i<=n;i++)
	{
		if(g[x][i]<=t) dfs(i,t+1);
	}
	return;
}
void dfs2(int x,int t)
{
	if(x==n&&t%k==0) ans=min(ans,t);
	int i;
	for(i=1;i<=n;i++)
	{
		if(g[x][i]==1) dfs2(i,t+1);
	}
	return;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	int j;
	if(k<=1)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a>>b>>c;
			g[a][b]=c;
		}
		dfs(1,k);
	}
	else 
	{
		for(j=1;j<=n;j++)
		{
			cin>>a>>b>>c;
			g[a][b]=1;
		}
		dfs2(1,k);
	}
	cout<<ans;
	return 0;
}

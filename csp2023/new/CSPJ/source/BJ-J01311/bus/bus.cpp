#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int g[1005][1005];
int vis[1005];
bool ok=0;
void dfs(int x,int tim)
{
	//cout<<x<<" "<<tim<<endl;
	if(x==n)
	{
		if(tim%k==0)ok=1;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(g[x][i]!=-1&&!vis[i]&&i!=x)
		{
			if(g[x][i]<=tim)
			{
				vis[i]=1;
				dfs(i,tim+1);
				vis[i]=0;
			}
		}
	}
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	memset(g,-1,sizeof(g));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,a;
		cin>>u>>v>>a;
		g[u][v]=a;
	}
	for(int i=k;;i+=k)
	{
		memset(vis,0,sizeof(vis));
		vis[1]=1;
		dfs(1,i);
		if(ok)
		{
			cout<<i+k<<endl;
			return 0;
		}
	}
	return 0;
}
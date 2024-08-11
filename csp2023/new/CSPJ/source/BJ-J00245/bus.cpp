#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,minn=1e7;
bool a[10005][10005],vis[10005];
void dfs(int step,int x)
{
	vis[x]=1;
	if(x==n)
	{
		if(step%k==0)
		{
			minn=min(minn,step);
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[x][i]==1&&vis[i]==0) dfs(step+1,i);
	}
	vis[x]=0;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u][v]=1;
	}
	dfs(0,1);
	cout<<minn<<endl;
	return 0;
}

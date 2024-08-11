#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[(int)(1e6+10)],b[(int)(1e6+10)];
int c[(int)(1e6+10)];
vector<int>edge[(int)(1e6+10)];
int d[(int)(1e6+10)];
int p[(int)(1e6+10)];
void dfs(int u,int fa)
{
	d[u]=ceil((double)a[u]/(double)b[u]);
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
	int tot=0;
	for(int i=0;i<edge[u].size();i++)
	{
		int v=edge[u][i];
		if(v==fa) continue;
		p[++tot]=d[v];
	}
	sort(p+1,p+1+tot);int now=1;
	for(int i=tot;i>=1;i--)
	{
		d[u]=max(d[u],p[i]+now);
		now++;
	}
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;bool f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		f&=(c[i]==0);
	}
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	cout<<d[1];
}
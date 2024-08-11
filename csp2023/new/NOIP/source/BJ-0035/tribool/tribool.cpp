#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m,fa[MAXN],ans,t,x,y,cl[MAXN];
char c;
bool vis[MAXN];
vector<int> E[MAXN],G[MAXN];
vector<int> pt;
void dfs1(int u)
{
	vis[u]=1,ans++;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(vis[v]) continue;
		dfs1(v);
	}
}
void dfs2(int u)
{
	vis[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(vis[v]) continue;
		dfs2(v);
	}
}
void dfs3(int u)
{
	vis[u]=1,pt.push_back(u);
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i],w=G[u][i];
		if(vis[v]) continue;
		cl[v]=cl[u]^w;
		dfs3(v);
	}
}
void solve()
{
	cin>>n>>m;
	fa[n+1]=n+1,fa[0]=0,ans=0;
	for(int i=1;i<=n;i++) fa[i]=i,E[i].clear(),G[i].clear();
	while(m--)
	{
		cin>>c;
		if(c=='U')
		{
			cin>>x;
			fa[x]=0;
		}
		if(c=='T')
		{
			cin>>x;
			fa[x]=n+1;
		}
		if(c=='F')
		{
			cin>>x;
			fa[x]=-n-1;
		}
		if(c=='+')
		{
			cin>>x>>y;
			fa[x]=fa[y];
		}
		if(c=='-')
		{
			cin>>x>>y;
			fa[x]=-fa[y];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(fa[i]==i) fa[i]=n+1;
		else if(fa[i]==-i) fa[i]=0;
		else
		{
			bool flag=(fa[i]<0);
			fa[i]=abs(fa[i]);
			if(fa[i]>=1&&fa[i]<=n)
			{
				E[fa[i]].push_back(i),E[i].push_back(fa[i]);
				G[i].push_back(flag),G[fa[i]].push_back(flag);
			}
		}
	}
	memset(vis,0,sizeof(vis));
	memset(cl,-1,sizeof(cl));
	for(int i=1;i<=n;i++)
	{
		if(!fa[i]) dfs1(i);
		if(fa[i]>n||fa[i]<0) dfs2(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		cl[i]=0;
		pt.clear();
		dfs3(i);
		bool flag=0;
		for(int j=0;j<pt.size();j++)
		{
			int u=pt[j];
			// cout<<u<<' '<<cl[u]<<endl;
			for(int k=0;k<E[u].size();k++)
			{
				int v=E[u][k],w=G[u][k];
				if((cl[u]^w)!=cl[v]) flag=1;
			}
		}
		if(flag) ans+=pt.size();
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t>>t;
	while(t--) solve();
	return 0;
}
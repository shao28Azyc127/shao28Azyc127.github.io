#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	char op;
	int x,y;
}a[(int)(1e6+10)];
int n,m;
int d[(int)(1e6+10)],f[(int)(1e6+10)];
int res=0;
void dfs(int x)
{
	if(x==n+1)
	{
		for(int i=1;i<=n;i++) f[i]=d[i];
		for(int i=1;i<=m;i++)
		{
			if(a[i].op=='+')
			{
				f[a[i].x]=f[a[i].y];
			}
			else if(a[i].op=='-')
			{
				if(f[a[i].y]==2) f[a[i].x]=2;
				else f[a[i].x]=(f[a[i].y]^1);
			}
			else 
			{
				if(a[i].op=='T') f[a[i].x]=1;
				else if(a[i].op=='F') f[a[i].x]=0;
				else f[a[i].x]=2;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]!=d[i]) return;
			cnt+=(f[i]==2);
		}
		res=min(res,cnt);
		return ;
	}
	d[x]=0;
	dfs(x+1);
	d[x]=1;
	dfs(x+1);
	d[x]=2;
	dfs(x+1);
}
int cnt=-1,vis[(int)(1e6+10)];
vector<int>edge[(int)(1e6+10)];
void dd(int x)
{
	if(vis[x]) return ;
	vis[x]=1;
	cnt++;
	for(int i=0;i<edge[x].size();i++)
	{
		int v=edge[x][i];
		dd(v);
	}
}
int p[(int)(1e6+10)];
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;cin>>c>>t;
	if(c<=2)
	{
		while(t--)
		{
			cin>>n>>m;
			for(int i=1;i<=n;i++) f[i]=d[i]=0;
			for(int i=1;i<=m;i++)
			{
				cin>>a[i].op;
				if(a[i].op=='+'||a[i].op=='-') cin>>a[i].x>>a[i].y;
				else cin>>a[i].x;
			}
			res=n;
			dfs(1);
			cout<<res<<"\n";
		}
	}
	if(c==3||c==4)
	{
		while(t--)
		{
			cin>>n>>m;
			for(int i=1;i<=m;i++)
			{
				char op;cin>>op;
				int x;cin>>x;
				if(op=='U') p[x]=1;
				else p[x]=0;
			}
			res=0;
			for(int i=1;i<=n;i++) res+=p[i];
			for(int i=1;i<=n;i++) p[i]=0;
			cout<<res<<"\n";
		}
	}
	if(c==5||c==6)
	{
		while(t--)
		{
			cin>>n>>m;
			for(int i=1;i<=n;i++) p[i]=d[i]=i;
			for(int i=1;i<=m;i++)
			{
				char op;cin>>op;
				if(op=='U')
				{
					int x;cin>>x;p[x]=0;
				}
				else
				{
					int x,y;cin>>x>>y;
					p[x]=p[y];
				}
			}
			for(int i=1;i<=n;i++)
			{
				// cout<<p[i]<<" ";
				edge[i].push_back(p[i]);
				edge[p[i]].push_back(i);
			}
			cnt=-1;
			dd(0);
			for(int i=0;i<=n;i++) edge[i].clear(),vis[i]=0;
			cout<<cnt<<"\n";
		}
	}
}
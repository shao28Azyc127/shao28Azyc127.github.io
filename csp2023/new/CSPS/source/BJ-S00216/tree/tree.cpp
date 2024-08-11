#include<bits/stdc++.h>
#define int long long
using namespace std;
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
	return f*ret;
}
int n,a[1005],b[1005],c[1005],vis[1005],ans=1e9,hi[25];
vector<int> e[1005];
void dfs(int u,int day)
{
	if(day==n)
	{	
		memset(hi,0,sizeof(hi));
		int p;
		for(p=1;p<=100005;p++)
		{
			for(int i=1;i<=n;i++)
			{
				if(vis[i]<=p)
				{
					hi[i]+=max(1ll,(b[i]+p*c[i]));
				}
				
			}
			int f=0;
			for(int i=1;i<=n;i++)
			{
				if(hi[i]<a[i]) 
				{
					f=1;break;
				}
			}
			if(!f) break;
		}
		ans=min(ans,p);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			for(int j=0;j<e[i].size();j++)
			{
				int to=e[i][j];
				if(vis[to]==0)
				{
					vis[to]=day+1;
					dfs(to,day+1);
					vis[to]=0;
				}
			}
		}
	}
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read(),c[i]=read();
	}
	for(int i=1;i<n;i++)
	{
		int u,v;u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	vis[1]=1;
	dfs(1,1);
	cout<<ans;
	return 0;
}
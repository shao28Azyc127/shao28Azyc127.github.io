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
	return ret*f;
}
int vis[10005],n,m,k,dis[100005],ans=1e9;
struct edge
{
	int v,w;
};
vector<edge> v[10005];
void dfs(int u,int tim,int dis)
{
	if(u==n)
	{
		if(dis%k==0)
		{
			int now=tim+dis;
			if(now%k) now=k*((now/k)+1);
			ans=min(ans,now);
		}
	}
	for(int i=0;i<v[u].size();++i)
	{
		int to=v[u][i].v;
		if(vis[to]) continue;
		vis[to]=1;
		dfs(to,max(tim,max(0ll,v[u][i].w-dis-1)),dis+1);
		vis[to]=0;
	}
}
void bfs()
{
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		if(vis[t]) continue;
		vis[t]=true;
		for(int i=0;i<v[t].size();i++)
		{
			int to=v[t][i].v;
			if(vis[to]) continue;
			dis[to]=dis[t]+1;
			q.push(to);
		}
	}
}
signed main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;cin>>a>>b>>c;
		v[a].push_back({b,c});
	}
	if(n<=10)
	{
		vis[1]=true;
		dfs(1,0,0);
		if(ans==1e9) cout<<-1;
		else cout<<ans<<endl;
	}
	dis[n]=-1;
	bfs();
	cout<<dis[n]<<endl;
	return 0;
}
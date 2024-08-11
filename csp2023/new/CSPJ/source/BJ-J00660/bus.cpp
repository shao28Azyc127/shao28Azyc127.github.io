#include <iostream>
#include <vector>
using namespace std;
int n,m,k;
struct node 
{
	int v;
	int open;
} a[20005];
vector<int> vec[20005];
bool vis[10005];
int open[20005];
int dis=0,ans=1e9;
void dfs(int u,int fa,int t)
{
	if(u==n)
	{
		if(dis%k==0)
		{
			ans=min(ans,dis);
		}
		return ;
	}
	for(auto v:vec[u])
	{
		if(vis[v]==false&&t>=a[u].open)
		{
			dis++;
			vis[v]=true;
			dfs(v,u,t+1);
			vis[v]=false;
			dis--;
		}
	}
	return ;
}
void dfs2(int u,int fa)
{
	if(u==n)
	{
		if(dis%k==0)
		{
			ans=min(ans,dis);
		}
		return ;
	}
	for(auto v:vec[u])
	{
		if(vis[v]==false)
		{
			dis++;
			vis[v]=true;
			dfs2(v,u);
			vis[v]=false;
			dis--;
		}
	}
	return ;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int u,v,o;
	cin>>n>>m>>k;
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v>>o;
		maxx=max(maxx,o);
		a[u].v=v;
		a[u].open=o;
		vec[u].push_back(v);
	}
	vis[1]=true;
	if(maxx==0||n>=3500)
	{
		dfs2(1,0);
		cout<<ans+k<<endl;
	}
	else
	{
		int minx=1e9+1+k;
		for(int i=k;i<=maxx+k;i+=k)
		{
			dfs(1,0,i);
			minx=min(ans+i,minx);
		}
		if(ans==1e9)
		{
			cout<<-1;
		}
		else
		{
			cout<<minx;
		}
	}
	return 0;
}

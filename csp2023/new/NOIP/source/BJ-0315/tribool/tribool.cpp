#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,m,d[100005],a[100005],ans;
vector<ll> mp[100005],w[100005];
bool vis[100005];
void fu(ll x)
{
	queue<ll> q;
	q.push(x);
	while(!q.empty())
	{
		ll u=q.front();q.pop();
		vis[u]=1;
		a[u]=0;
		ans++;
		ll sz=mp[u].size();
		for(ll i=0;i<sz;i++)
		{
			if(!vis[mp[u][i]]) q.push(mp[u][i]),vis[mp[u][i]]=1;
		}
	}
}
bool dfs(ll x,ll op)
{
	if(vis[x])
	{
		if(op==-1) return 1;
		else return 0;
	}
	vis[x]=1;
	ll sz=mp[x].size();
	for(ll i=0;i<sz;i++)
	{
		if(dfs(mp[x][i],op*w[x][i]))
		{
			vis[x]=0;
			return 1;
		}
	}
	vis[x]=0;
	return 0;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		ans=0;
		for(ll i=1;i<=n;i++) mp[i].clear(),w[i].clear(),d[i]=1,a[i]=1,vis[i]=0;
		while(m--)
		{
			char op;
			cin>>op;
			if(op=='T')
			{
				ll x;
				cin>>x;
				a[x]=1;
			}
			else if(op=='F')
			{
				ll x;
				cin>>x;
				a[x]=-1;
			}
			else if(op=='U')
			{
				ll x;
				cin>>x;
				a[x]=0;
			}
			else if(op=='+')
			{
				ll x,y;
				cin>>x>>y;
				mp[y].push_back(x);
				w[y].push_back(1);
			}
			else
			{
				ll x,y;
				cin>>x>>y;
				mp[y].push_back(x);
				w[y].push_back(-1);
			}
		}
		for(ll i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			if(a[i]==0||dfs(i,a[i])) fu(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
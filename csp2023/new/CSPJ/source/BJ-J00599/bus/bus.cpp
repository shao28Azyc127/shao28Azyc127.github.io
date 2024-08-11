#include<bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=114514;

ll n,m,k;
vector<pii> g[N];
ll ans=LLONG_MAX;
bitset<N> vis;
inline void dfs(int u,ll mt,ll dis,ll to1,ll tds)
{
	if (u==n)
	{
		ans=min(ans,ll(ceil(1.0*(max(k+to1,mt)+dis)/k)*k));
		//cout<<mt<<' '<<dis<<' '<<to1<<' '<<tds<<endl;
		return;
	}
	vis[u]=1;
	for (auto [v,w]:g[u])
	{
		if (!vis[v])
		{
			if (mt<w) dfs(v,w,0,tds,tds+1);
			else dfs(v,mt,dis+1,to1+1,tds+1);
		}
	}
	vis[u]=0;
}

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb({v,w});
	}
	dfs(1,0,0,0,0);
	cout<<(ans!=LLONG_MAX?ans:-1)<<endl;
	
	return 0;
}

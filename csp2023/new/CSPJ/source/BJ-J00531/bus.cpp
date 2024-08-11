#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,s[1000005],ans=1e18;
bool f[1000005],vis[1000005];
vector<ll> mp[10005],w[10005];
void dfs(ll x,ll t,ll mx)
{
	if(x==n)
	{
		if(!f[t]) f[t]=1,s[t]=mx;
		else s[t]=min(s[t],mx);
		return;
	}
	vis[x]=1;
	ll sz=mp[x].size();
	for(ll i=0;i<sz;i++)
	{
		if(!vis[mp[x][i]]) dfs(mp[x][i],t+1,max(mx,w[x][i]-t));
	}
	vis[x]=0;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++)
	{
		ll x,y,a;
		scanf("%lld%lld%lld",&x,&y,&a);
		mp[x].push_back(y);
		w[x].push_back(a);
	}
	dfs(1,0,0);
	for(ll i=0;i<1000000;i+=k)
	{
		if(f[i])
		{
			ll e=s[i]/3;
			if(e*3!=s[i]) e++;
			ans=min(ans,i+e*3);
		}
	}
	printf("%lld",ans);
	return 0;
}
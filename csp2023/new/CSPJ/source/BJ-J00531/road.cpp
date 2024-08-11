#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,v[100005],a[100005],f[100005],s[100005],cnt,ans,now;
priority_queue<pair<ll,ll> > q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld",&n,&d);
	for(ll i=1;i<n;i++) scanf("%lld",&v[i]),s[i]=s[i-1]+v[i];
	for(ll i=1;i<n;i++) scanf("%lld",&a[i]),q.push({-a[i],i});
	scanf("%lld",&a[n]);
	f[++cnt]=n;
	while(!q.empty())
	{
		ll x=q.top().second;
		q.pop();
		if(x>f[cnt]) continue;
		f[++cnt]=x;
		if(x==1) break;
	}
	for(ll i=cnt;i>1;i--)
	{
		ll l=s[f[i-1]-1]-s[f[i]-1];
		if(l>now)
		{
			ll s=(l-now)/d;
			if(s*d+now<l) s++;
			now=(s*d+now)-l;
			ans+=a[f[i]]*s;
		}
		else now=l-now;
	}
	printf("%lld",ans);
	return 0;
}
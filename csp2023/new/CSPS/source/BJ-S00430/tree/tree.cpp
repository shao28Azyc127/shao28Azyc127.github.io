#include <bits/stdc++.h>
using namespace std;

const long long N=1e5+5;

long long a[N],b[N],c[N],t[N],n;
vector <long long> g[N];

void dfs(long long x,long long fa)
{
	for(auto to:g[x])
	{
		if(to==fa)
			continue;

		dfs(to,x);
		t[x]=min(t[x],t[to]-1);
	}
}

__int128 calc(long long l,long long r,long long b,long long c)
{
	if(c>=0)
		return (__int128)c*(l+r)*(r-l+1)/2+b*(r-l+1);

	long long lim=(b-1)/(-c);
	if(lim>=r)
		return (__int128)c*(l+r)*(r-l+1)/2+b*(r-l+1);

	if(lim<l)
		return (r-l+1);

	return calc(l,lim,b,c)+calc(lim+1,r,b,c);
}

bool check(long long lim)
{
	for(long long i=1;i<=n;i++)
	{
		long long l=1,r=lim,ans=0;
		while(l<=r)
		{
			long long mid=(l+r)/2;
			if(calc(mid,lim,b[i],c[i])>=a[i])
				ans=mid,l=mid+1;
			else
				r=mid-1;

			t[i]=ans;
		}

		if(ans<=0)
			return false;
	}

	dfs(1,-1);
	sort(t+1,t+n+1);

	for(long long i=1;i<=n;i++)
		if(t[i]<i)
			return false;

	return true;
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin >> n;
	for(long long i=1;i<=n;i++)
		scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);

	for(long long i=1;i<n;i++)
	{
		long long x,y;
		scanf("%lld %lld",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	long long l=0,r=1000000000,ans=0;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid))
			ans=mid, r=mid-1;
		else
			l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}
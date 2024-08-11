#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long v[100005],a[100005];
long long s[100005],f[100005];
long long minn=1e9,wei;
long long up(long long x,long long y)
{
	if(x%y==0)
	{
		return x/y;
	}
	return x/y+1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld",&n,&d);
	for(long long i=2;i<=n;i++)
	{
		scanf("%lld",&v[i]);
		s[i]=s[i-1]+v[i];
		if(v[i]<minn)
		{
			minn=v[i],wei=i;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(wei==1)
	{
		printf("%lld",up(s[n],d)*a[1]);
		return 0;
	}
	for(long long i=2;i<=n;i++)
	{
		long long minn=1e9;
		for(long long j=1;j<i;j++)
		{
			minn=min(minn,f[j]+(s[i]-s[j])*a[j]);
		}
		f[i]=minn;
	}
	printf("%lld",f[n]);
	return 0;
}
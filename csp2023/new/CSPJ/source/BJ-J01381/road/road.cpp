#include<bits/stdc++.h>
using namespace std;
long long n,d,cnt=1,ans,t=1,l=0,now=1,tar;
long long v[100005],p[100005],s[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld",&n,&d);
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&v[i]);
		s[i]=s[i-1]+v[i];
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p[i]);
	}
	while(now<n)
	{
		for(int i=now;i<=n;i++)
		{
			if(p[i]<p[now])
			{
				tar=i;
				break;
			}
		}
		if(tar==now)tar=n;
		long long q=s[tar]-s[now];
		q-=l;
		long long g=q/d;
		if(q%d)g++;
		ans+=p[now]*g;
		l=g*d;
		l-=q;
		now=tar;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

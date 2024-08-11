#include <bits/stdc++.h>
using namespace std;
long long dp[1010][1010],a[1010][1010],x1[1010],z,o=-0x3f3f3f3f3f3f3f3f;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	long long c,t;
	scanf("%lld%lld",&c,&t);
	if(c==17||c==18)
	{
		while(t--)
		{
			long long n,m,k,d,x,y,v,i,ans=0;
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
			for(i=1;i<=m;i++)
			{
				scanf("%lld%lld%lld",&x,&y,&v);
				if(x-y>=0&&y<=k)
					ans+=max(z,v-y*d);
			}
			cout<<ans<<'\n';
		}
	}
	else
	{
		while(t--)
		{
			memset(dp,0,sizeof(dp));
			long long n,m,k,d,x,y,v,lx,i,j;
			scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
			for(i=1;i<=m;i++)
			{
				scanf("%lld%lld%lld",&x,&y,&v);
				a[x][y]+=v;
			}
			lx=0;
			for(i=1;i<=n;i++)
			{
				dp[i][0]=lx;
				long long s=0;
				for(j=1;j<=k;j++)
				{
					s+=a[i][j];
					dp[i][j]=dp[i-1][j-1]-d+s;
					lx=max(lx,dp[i][j]);
				}
			}
			printf("%lld",lx);
		}
	}
	return 0;
}

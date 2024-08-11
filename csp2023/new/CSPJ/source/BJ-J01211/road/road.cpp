#include <bits/stdc++.h>

using namespace std;

long long u[100005],a[100005];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	long long ans=0,cnt=0;
	scanf("%d %d",&n,&d);
	for(int i=1;i<n;i++)
	{
		scanf("%lld",&u[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<n;i++)
	{
		long long q=1;
		while(true)
		{
			if(q*d+cnt >= u[i])
			{
				if(i == 1)
				{
					cnt=q*d;
				}
				else
				{
					cnt-=u[i];
				}
				break;
			}
			q++;
		}
		ans+=q*a[i];
	}
	printf("%lld\n",ans);
	return 0;
}

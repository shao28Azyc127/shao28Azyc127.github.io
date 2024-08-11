#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int n,d,ans;
int dis[N],pr[N],dp[N];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	
	cin>>n>>d;
	
	for(int i=2;i<=n;i++)
	{
		cin>>dis[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>pr[i];
	}
	
	int cnt = 0;
	if(dis[2] % d != 0)
	{
		dp[2] = (dis[2]/d)*pr[1]+pr[1];
		cnt = (dis[2]/d)*d + d;
	}
	else
	{
		dp[2] = (dis[2]/d)*pr[1];
		cnt = dis[2];
	}	

	for(int i=3;i<=n;i++)
	{
		int minn = 0x3f3f3f3f;
		
		for(int j=1;j<i;j++)
		{
			if(pr[j] < minn)
			{
				minn = pr[j];
			}	
		}
		
		if((dis[i]-cnt+dis[i-1])/d != 0)
		{
			dp[i] = (dis[i]-cnt+dis[i-1])/d * minn + minn;
			cnt = (dis[i]/d)*d + d;
		}	
		else
		{
			dp[i] = (dis[i]-cnt+dis[i-1])/d * minn;
			cnt = dis[i];
		}	
	}
	
	for(int i=2;i<=n;i++)
	{
		ans += dp[i];
	}		
	cout<<ans;
	return 0;
}

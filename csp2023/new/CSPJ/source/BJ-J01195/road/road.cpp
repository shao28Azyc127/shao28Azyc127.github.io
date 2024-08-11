#include <bits/stdc++.h>
using namespace std;
int v[100010],a[100010],dp[100010],b[100010];
int main()
{	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,d;
	cin>>n>>d;
	long long sum=0;
	for(int i=1;i<n;i++)
	{
		cin>>v[i];
		b[i+1]=b[i]+v[i];
		sum+=v[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>1000)
	{
		if(sum%d==0)
		{
			cout<<sum/d*a[1]<<endl;
		}
		else
		{
			cout<<(sum/d+1)*a[1]<<endl;
		}
		return 0;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=dp[1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if((b[i]-b[j])%d==0)
			{
				dp[i]=min(dp[i],dp[j]+a[j]*((b[i]-b[j])/d));
			}
			else
			{
				dp[i]=min(dp[i],dp[j]+a[j]*((b[i]-b[j])/d+1));
			}
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
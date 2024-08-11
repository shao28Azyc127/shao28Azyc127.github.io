#include <bits/stdc++.h>
using namespace std;
int v[100002],a[100002];
long long dp[100002];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	long long sum=0;
	int mina=100001;
	cin>>n>>d;
	for(int i=2;i<=n;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<mina)
			mina=a[i];
	}
	if(mina==a[1])
	{
		long long ans=ceil(sum/d)*a[1];
		cout<<ans<<endl;
	}
	else
	{
		for(int i=2;i<=n;i++)
			v[i]=ceil(v[i]/d);
		dp[0]=0;
		for(int i=1;i<=n;i++)
		{
			dp[i]=dp[i-1];
			int tmp=a[i-1];
			for(int j=1;j<i;j++)
				if(a[j]<tmp)
					tmp=a[j];
			dp[i]+=tmp*v[i];
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
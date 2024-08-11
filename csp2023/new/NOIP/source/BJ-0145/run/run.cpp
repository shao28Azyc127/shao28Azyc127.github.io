#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,m,k,d;
int x[100005];
int y[100005];
int v[100005];
int a[3005][3005];
int dp[3005][3005];
signed main()
{
	// system("deff run2.ans 4.out");
	// return 0;
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	if(c<=9)
	{
		while(t--)
		{
			int ans=0;
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;i++)
			{
				cin>>x[i]>>y[i]>>v[i];
				a[x[i]-y[i]+1][x[i]]+=v[i];
			}
			for(int i=n;i>=1;i--)
			{
				for(int j=1;j<=n;j++)
				{
					a[i][j]+=a[i+1][j]+a[i][j-1]-a[i+1][j-1];
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=min(i-1,k);j++) dp[i][0]=max(dp[i][0],dp[i-1][j]);
				for(int j=1;j<=min(i,k);j++)
				{
					dp[i][j]=dp[i-j][0];
					dp[i][j]+=a[i-j+1][i]-j*d;
					ans=max(ans,dp[i][j]);
				}
			}
			cout<<ans<<endl;
			memset(dp,0,sizeof(dp));
			memset(a,0,sizeof(a));
		}
		return 0;
	}
	if(c==17||c==18)
	{
		while(t--)
		{
			int ans=0;
			cin>>n>>m>>k>>d;
			for(int i=1;i<=m;i++)
			{
				cin>>x[i]>>y[i]>>v[i];
				if(y[i]>k) continue;
				if(x[i-1]==x[i]-y[i]&&y[i-1]<=k)
				{
					if(y[i-1]+y[i]<=k) ans+=max(-y[i]*d+v[i],0ll);
					else
					{
						ans-=max(-y[i-1]*d+v[i-1],0ll);
						ans+=max(0ll,max(-y[i-1]*d+v[i-1],-y[i]*d+v[i]));
					}
				}
				else if(y[i]<=k) ans+=max(-y[i]*d+v[i],0ll);
			}
			cout<<ans<<endl;
		}
	}
}

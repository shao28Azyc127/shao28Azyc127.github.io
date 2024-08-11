#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,m,k,d;
struct node
{
	int x,y,v;
}a[(int)(1e6+10)];
int dp[1005][1005],p[1005][1005];
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	if(c==17||c==18)
	{
		while(t--)
		{
			cin>>n>>m>>k>>d;int res=0;
			for(int i=1;i<=m;i++)
			{
				cin>>a[i].x>>a[i].y>>a[i].v;
				if(a[i].y<=k&&a[i].v-a[i].y*d>=0) res+=a[i].v-a[i].y*d;
			}
			cout<<res<<"\n";
		}
		return 0;
	}
	while(t--)
	{
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].v;
			p[a[i].x][a[i].y]+=a[i].v;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) p[i][j]+=p[i][j-1];
	 	int mx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(i,k);j++)
			{
				if(j==0) dp[i][j]=mx;
				else dp[i][j]=dp[i-1][j-1]-d+p[i][j];
				mx=max(dp[i][j],mx);
				// cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
			}

		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) p[i][j]=0;
		cout<<mx<<"\n";
	}
}
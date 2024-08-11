#include <bits/stdc++.h>
using namespace std;
#define int long long
int v[100005];
int s[100005];
int a[100005];
int dp[1005][1005];
int ans=1e9;
int n,D;
void dfs(int x,int sum,int last)
{
	//cout<<x<<" "<<sum<<last<<endl;
	//x是到了那里，sum是花的钱，last是剩下的油
	if(sum>ans)return;
	//cout<<x<<" "<<sum<<" "<<last<<endl;
	if(x==n)
	{
		ans=sum;
	}
	for(int i=x+1;i<=n;i++)
	{
		int d=s[i]-s[x];
		d-=last;
		int use=ceil(1.0*d/D);
		//d是两点间的距离
		//use是需要用的油
		int cost=use*a[x];
		//cost是需要花的钱
		int l=use*D-d;
		dfs(i,sum+cost,l);
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>D;
	bool flag=1;
	for(int i=2;i<=n;i++)
	{
		cin>>v[i];
		s[i]=s[i-1]+v[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//cout<<a[1]<<" "<<a[i]<<endl;
		if(a[1]>a[i]&&i!=1)
		{
			flag=0;
		}
	}
	if(flag)
	{
		int d=s[n];
		int ans=ceil(1.0*d/D)*a[1];
		cout<<ans<<endl;
		return 0;
	}

	if(n<=8)
	{
		dfs(1,0,0);
		cout<<ans<<endl;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
	{
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int d=s[i+1]-s[i];
		int use=ceil(1.0*d/D);
		//d是两点间的距离
		//use是需要用的油
		int cost=use*a[i];
		dp[i][i+1]=cost;
	}
	for(int len=3;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			for(int k=i;k<j;k++)
			{
				bool flag=0;
				if(k-i+1<2||j-k+2<2)flag=1;
				int d1=s[j]-s[i];
				int use1=ceil(1.0*d1/D);
				//d是两点间的距离
				//use是需要用的油
				int ans1=use1*a[i];
				if(!flag)
				{
					int d=s[k]-s[i];
					int use=ceil(1.0*d/D);
					int cost=use*a[i];

					int d2=s[j]-s[k+1];
					int use2=ceil(1.0*d2/D);
					int cost2=use2*a[k+1];
					dp[i][j]=min({ans1,cost+cost2,dp[i][j]});
				}
				else 
				{
					dp[i][j]=min(dp[i][j],ans1);
				}
				
			}
		}
	}
	cout<<dp[1][n]<<endl;
	}
	return 0;
}

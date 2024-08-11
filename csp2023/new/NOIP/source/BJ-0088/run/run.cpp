#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T;
int n,m,k,w;
struct node
{
	int dis,val;
};
vector<node> v[1010];
bool cmp(node x,node y)
{
	return x.dis<y.dis;
}
int dp[1010][1010];
void solve()
{
	scanf("%lld%lld%lld%lld",&n,&m,&k,&w);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		v[x].push_back(node{y,z});
	}
	for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end(),cmp);
	memset(dp,-0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k&&j<=i-1;j++) dp[i][0]=max(dp[i][0],dp[i-1][j]);
		int t=0,sval=0;
		int len=v[i].size();
		for(int j=1;j<=k&&j<=i;j++)
		{
			while(t<len&&v[i][t].dis<=j) sval+=v[i][t].val,t++;
			dp[i][j]=max(dp[i][j],dp[i-1][j-1]+sval-w);
		}
	}
	int ans=0;
	for(int j=0;j<=k;j++) ans=max(ans,dp[n][j]);
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++) v[i].clear();
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--) solve();
	return 0;
}
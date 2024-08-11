#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long LL;
const int N = 1010;
LL INF = 1e18;
LL n,m,d;
int k;
LL dp[N][N],sum[N][N],ans = 0;
void solve()
{
	ans = 0;
	cin >> n >> m >> k >> d;
	for(int i = 1;i <= n;++i)
	for(int i = 0;i <= n;++i)
		for(int j = 0;j <= k;++j) dp[i][j] = -INF;
	dp[0][0] = 0;
	memset(sum,0,sizeof(sum));
	for(int i = 1;i <= m;++i)
	{
		LL x,y,z;
		cin >> x >> y >> z;
		sum[x][y] += z;
	}
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= k;++j)
			sum[i][j] += sum[i][j-1];
	for(int i = 1;i <= n;++i)
	{
		dp[i][0] = 0;
		for(int j = 0;j <= k;++j) dp[i][0] = max(dp[i-1][j],dp[i][0]);
		for(LL j = 1;j <= min(i,k);++j)
			dp[i][j] = dp[i-1][j-1] + sum[i][j] - d;
	}
	for(int i = 0;i <= k;++i) ans = max(ans,dp[n][i]);
	cout << ans << '\n';
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin >> c >> t;
	while(t -- ) solve();
	return 0;
}

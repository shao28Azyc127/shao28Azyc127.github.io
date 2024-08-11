#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e3+5;

int typ,__;
ll n,m,k,d;
int day[N],lim[N];
ll val[N],f[N],g[N],sum[N];
ll dp[M][M];
vector<int> v[N];

bool cmp(int i,int j) {
	return lim[i]<lim[j];
}

void solve() {
	memset(dp,~0x3f,sizeof dp);
	dp[0][0]=0;
	ll ans=0;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=k; j++)
			dp[i][0]=max(dp[i][0],dp[i-1][j]);
		for (int j=1; j<=k; j++) {
			ll sum=0;
			for (int p=1; p<=m; p++)
				if (day[p]==i&&lim[p]<=j) sum+=val[p];
			dp[i][j]=max(dp[i][j],dp[i-1][j-1]+sum-d);
			ans=max(ans,dp[i][j]);
		}
			/*
		for (int j=0; j<v[i].size(); j++)
			dp[i][lim[v[i][j]]]=sum[v[i][j]];
		for (int j=1; j<=k; j++) dp[i][j]=max(dp[i][j],dp[i][j-1]-d);
		for (int j=1; j<=k; j++) ans=max(ans,dp[i][j]+=dp[i-1][j-1]-d);
		*/
	} cout<<ans<<'\n';
	return;
	cout<<dp[1][0]<<' '<<dp[1][1]<<'\n';
	for (int i=1; i<=n; i++)
		for (int j=1; j<=k; j++) cout<<dp[i][j]<<" \n"[j==k];
}

int main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>typ>>__;
	while (__--) {
		cin>>n>>m>>k>>d;
		for (int i=1; i<=n; i++) v[i].clear();
		for (int i=1; i<=m; i++) {
			cin>>day[i]>>lim[i]>>val[i];
			if (lim[i]<=k) v[day[i]].push_back(i);
		}
		for (int i=1; i<=n; i++) {
			sort(v[i].begin(),v[i].end(),cmp);
			for (int j=0; j<v[i].size(); j++)
				sum[v[i][j]]=(j?sum[v[i][j-1]]:0)+val[v[i][j]];
		}
		if (typ<=9) {
			solve();
			continue;
		}
	}
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[1005][1005];
int val[1005][1005];
const int INF=1e18;
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t,n,m,k,d,x,y,v;
	cin>>c>>t;
	while(t--){
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				val[i][j]=0;
				dp[i][j]=-INF;
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%lld%lld%lld",&x,&y,&v);
			val[x][y]+=v;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) val[i][j]+=val[i][j-1];
		dp[0][0]=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<=min(i,k);j++){
				if(j+1<=k) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+val[i+1][j+1]-d);
				dp[i+1][0]=max(dp[i+1][0],dp[i][j]+val[i+1][0]);
			}
		}
		int ret=-INF;
		for(int i=0;i<=n;i++){
			ret=max(ret,dp[n][i]);
		}
		printf("%lld\n",ret);
	}
	return 0;
}
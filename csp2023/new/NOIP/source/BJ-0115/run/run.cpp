#include <bits/stdc++.h>
#define for0(i,n) for(i=0;i<(n);i++)
#define for1(i,n) for(i=1;i<=(n);i++)
#define forlr(i,l,r) for(i=(l);i<=(r);i++)
using namespace std;
typedef long long ll;
const int N=1010;
int C,T,n,m,k;
ll dp[N][N],d,ans,s[N][N];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int tim,i,j,x,y;
	ll z;
	scanf("%d%d",&C,&T);
	for1(tim,T){
		memset(dp,0xcf,sizeof(dp));
		memset(s,0,sizeof(s));
		scanf("%d%d%d%lld",&n,&m,&k,&d);
		for1(i,m){
			scanf("%d%d%lld",&x,&y,&z);
			s[x][y]+=z;
		}
		dp[0][0]=0;
		for1(i,n){
			dp[i][0]=dp[i-1][0];
			for1(j,k) dp[i][0]=max(dp[i][0],dp[i-1][j]),s[i][j]+=s[i][j-1];
			for1(j,k) dp[i][j]=dp[i-1][j-1]+s[i][j]-d;
		}
		ans=dp[n][0];
		for1(i,k) ans=max(ans,dp[n][i]);
		printf("%lld\n",ans);
	}
	return 0;
}

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;
LL n,m,k,d;
LL a[1010][1010];
LL dp[1010][1010];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int T1,T2;cin>>T1>>T2;
	while(T2--){
		cin>>n>>m>>k>>d;
		if(T1==17||T1==18){
			LL ans=0;
			for(int i=1;i<=m;i++){
				LL x,y,z;cin>>x>>y>>z;
				if(y<=k&&y*d<z) ans+=z-y*d;
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=0;j<=k+1;j++)
				a[i][j]=0,dp[i][j]=0;
		for(int i=1;i<=m;i++){
			LL x,y,z;cin>>x>>y>>z;
			if(y<=k) a[x][y]+=z;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
				a[i][j]+=a[i][j-1];
		for(int i=1;i<=n;i++){
			for(int j=0;j<=k;j++)
				dp[i][0]=max(dp[i][0],dp[i-1][j]);
			for(int j=1;j<=k;j++){
				dp[i][j]=dp[i-1][j-1]-d+a[i][j];
			}
		}
		LL ans=0;
		for(int i=0;i<=k;i++) ans=max(ans,dp[n][i]);
		cout<<ans<<"\n";
	}
	return 0;
}

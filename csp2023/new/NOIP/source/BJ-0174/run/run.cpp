#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define REPG(i,h,x) for(int i=h[x];~i;i=edge[i].next)
#define CLR(a,x) memset(a,x,sizeof(a))
const int INF=0x3f3f3f3f;

const int N=1005;
int T,n,m,K,lim[N];
ll D,delta[N],f[N][N];
inline void solve(){
	scanf("%d%d%d%lld",&n,&m,&K,&D);
	for(int i=1,x;i<=m;i++) scanf("%d",&x),scanf("%d%lld",&lim[x],&delta[x]);
	for(int i=0;i<=n;i++) for(int j=0;j<=K;j++) f[i][j]=-9e18; 
	for(int i=0;i<=n;i++) f[i][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++) for(int k=0;k<=min(K,j);k++) f[i][0]=max(f[i][0],f[j][k]);
		for(int j=1;j<=min(K,i);j++){
			if(j>=lim[i]) for(int k=1;k<=j;k++) f[i][j]=max(f[i][j],f[i-k][j-k]-k*D+delta[i]);
			else for(int k=1;k<=j;k++) f[i][j]=max(f[i][j],f[i-k][j-k]-k*D);
		}
	}
	ll ans=-9e18;
	for(int i=0;i<=K;i++) ans=max(ans,f[n][i]);
	printf("%lld\n",ans);
}
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%*d%d",&T);
	while(T--) solve();
	return 0;
}
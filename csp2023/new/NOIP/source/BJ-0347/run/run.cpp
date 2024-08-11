#include <bits/stdc++.h>
using namespace std;
#define M 100005
#define ll long long
ll c,T,f[M],n,m,k,d,x[M],y[M],v[M],ans;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		ans=0;
		memset(f,0,sizeof(f));
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		for(ll i=1;i<=m;i++){
			scanf("%lld%lld%lld",&x[i],&y[i],&v[i]);
		}
		for(int i=1;i<=n;i++){
			if(y[i]*d<v[i]&&y[i]<=k&&y[i]<=x[i]){
				ans+=v[i]-y[i]*d;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
				

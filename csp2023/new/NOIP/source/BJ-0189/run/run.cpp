#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100010;
int c,t,n,m;
long long dp[N],mx[N],d,k;
struct ev{
	long long x,y,v;
} e[N];
int sta[N],st[N],cntst=0;
bool cmp(ev a,ev b){
	return a.x<b.x;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d %d",&c,&t);
	if(c==17 || c==18){
		for(int xyz=1; xyz<=t; ++xyz){
			scanf("%d %d %lld %lld",&n,&m,&k,&d);
			long long ans=0,x,y,v;
			for(int i=1; i<=m; ++i){
				scanf("%lld %lld %lld",&x,&y,&v);
				long long w=v-y*d;
				if(w>0 && y<=k)
					ans+=w;
			}
			printf("%lld\n",ans);
		}
	}
	else{
		for(int xyz=1; xyz<=t; ++xyz){
			scanf("%d %d %lld %lld",&n,&m,&k,&d);
			memset(dp,0,sizeof(dp));
			memset(mx,0,sizeof(mx));
			long long ans=0;
			for(int i=1; i<=m; ++i)
				scanf("%lld %lld %lld",&e[i].x,&e[i].y,&e[i].v);
			sort(e+1,e+m+1,cmp);
			for(int i=1; i<=n; ++i){
				for(int j=1; j<=k && j<=i; ++j){
					long long w=-d*j;
					for(int f=1; f<=m && e[f].x<=i; ++f)
						if(e[f].x-e[f].y+1>=i-j+1)
							w+=e[f].v;
					dp[i+1]=max(dp[i+1],mx[i-j]+w);
				}
				mx[i+1]=max(mx[i],dp[i+1]);
			}
			printf("%lld\n",mx[n+1]);
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define REPG(i,h,x) for(int i=h[x];~i;i=edge[i].next)
#define CLR(a,x) memset(a,x,sizeof(a))
const int INF=0x3f3f3f3f;
const int G=2e5+5;
int head[G],gcnt=1;
struct Edge{int v,next,w;}edge[G];
inline void addedge(int u,int v,int w){edge[++gcnt]={v,head[u],w},head[u]=gcnt;}

const int N=1e5+5;
int n,V2;
ll a[N],b[N],c[N],V,ans;
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	CLR(head,-1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]),V=max(V,c[i]);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),addedge(u,v,0),addedge(v,u,0),V2=max(V2,v-u);
	if(V==0){
		ll ans=INF,ans2=-INF;
		for(int i=2;i<=n;i++){
			ll delta=a[i]/b[i];
			if(a[i]%b[i]) delta++;
			ans=min(ans,delta),ans2=max(ans,delta);
		}
		ll ans3=a[1]/b[1];
		if(a[1]%b[1]) ans3++;
		printf("%lld\n",max(max(ans+n-1,ans2),ans3));
		return 0;
	}
	// if(V2==1){
	// 	for(int i=1;i<=n;i++){
	// 		ll delta=
	// 	}
	// }
	return 0;
}
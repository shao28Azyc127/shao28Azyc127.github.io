#include <bits/stdc++.h>
#define for0(i,n) for(i=0;i<(n);i++)
#define for1(i,n) for(i=1;i<=(n);i++)
#define forlr(i,l,r) for(i=(l);i<=(r);i++)
using namespace std;
const int N=100005;
typedef long long ll;
vector<int> v[N];
int n,p[N];
bool vis[N];
ll a[N],b[N],c[N],d[N],ans,f[N],t;
void dfs(int x,int fx){
	f[x]=fx;
	for(int y:v[x]) if(y!=fx) dfs(y,x);
}
bool cmp(int x,int y){
	return d[x]>d[y];
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int i,x,y;
	scanf("%d",&n);
	for1(i,n) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]),d[i]=(a[i]+b[i]-1)/b[i],p[i]=i;
	for1(i,n-1) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs(1,0);
	vis[1]=1;
	sort(p+1,p+n+1,cmp);
	for1(i,n){
		x=p[i];y=x;
		while(!vis[x]) vis[x]=1,x=f[x],++t;
		ans=max(ans,t+d[y]);
	}
	printf("%lld\n",ans);
	return 0;
}

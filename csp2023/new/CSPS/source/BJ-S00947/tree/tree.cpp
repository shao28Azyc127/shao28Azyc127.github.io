#include<cstdio>
#include<vector>
#include<algorithm>
const int N=100010;
std::vector<int> G[N];
typedef long long ll;
ll a[N];
int b[N],c[N],k[N];
ll X[N],Y[N];
int t[N],n;
void dfs(int u,int fa){for(int v:G[u]) if(v!=fa) dfs(v,u),t[u]=std::min(t[u],t[v]-1);}
inline __int128 S(int i,int x)
{
	if(c[i]>=0) return (ll)x*b[i]+__int128(((ll)(x)*(x+1))>>1)*c[i];
	else
	{
		if(k[i]<x) return x-k[i]+X[i]+__int128(Y[i])*c[i];
		else return (ll)x*b[i]+__int128(((ll)(x)*(x+1))>>1)*c[i];
	}
}
inline int Get(int i,int x)
{
	__int128 s=S(i,x);
	if(s<a[i]) return -1;
	int l=1,r=x;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(s-S(i,mid-1)>=a[i]) l=mid;
		else r=mid-1;
	}
	return l;
}
int cnt[N];
inline bool check(int x)
{
	for(int i=1;i<=n;++i) if((t[i]=Get(i,x))==-1) return false;
	dfs(1,0);
	if(t[1]<1) return false;
	for(int i=1;i<=n;++i) cnt[i]=0;
	for(int i=1;i<=n;++i) ++cnt[std::min(t[i],n)];
	for(int i=1,s=0;i<=n;++i) if((s+=cnt[i])>i) return false;
	return true;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%d%d",&a[i],&b[i],&c[i]);
		if(c[i]<0) k[i]=(b[i]-1)/(-c[i]),X[i]=(ll)k[i]*b[i],Y[i]=((ll)k[i]*(k[i]+1))>>1;
	}
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].emplace_back(v),G[v].emplace_back(u);
	}
	int l=n,r=1000000000;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
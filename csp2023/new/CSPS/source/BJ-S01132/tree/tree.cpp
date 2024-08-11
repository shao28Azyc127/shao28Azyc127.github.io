#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll inf_=0x3f3f3f3f;
int n;
int a[100010],b[100010],c[100010];
int head[100010],to[200010],nxt[200010],tot=0;
void add(int x,int y)
{
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int fa[100010];
void dfs(int u,int f)
{
	fa[u]=f;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==f) continue;
		dfs(v,u);
	}
}
int vis[100010];
struct node
{
	int v,id;
}d[100010];
bool cmp(node x,node y){return x.v<y.v;}
ll calc(int l,int r,int i)
{
	if(c[i]>=0)
	{
		ll x=b[i]+c[i]*l;
		ll y=b[i]+c[i]*r;
		if(x+y>=inf_) return inf;
		return (x+y)*(r-l+1)/2ll;
	}
	else
	{
		int k=(b[i]-1)/(-c[i]);
		if(r<=k)
		{
			ll x=b[i]+c[i]*l;
			ll y=b[i]+c[i]*r;
			if(x+y>=inf_) return inf;
			return (x+y)*(r-l+1)/2ll;
		}
		else if(k<l)
		{
			return r-l+1;
		}
		else
		{
			ll x=b[i]+c[i]*l;
			ll y=b[i]+c[i]*k;
			if(x+y>=inf_) return inf;
			return (x+y)*(k-l+1)/2ll+(r-k);
		}
	}
}
int T;
void find(int u)
{
	if(vis[u]) return;
	if(!vis[fa[u]]) find(fa[u]);
	vis[u]=++T;
}
bool check(int x)
{
	for(int i=1;i<=n;i++)
	{
		int l=0,r=x+1,ans;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(calc(mid,x,i)>=a[i]) l=mid+1,ans=mid;
			else r=mid;
		}
		d[i].v=ans;
		d[i].id=i;
		// cout<<ans<<"\n";
	}
	sort(d+1,d+n+1,cmp);
	memset(vis,0,sizeof(vis)); vis[0]=1;
	T=0;
	for(int i=1;i<=n;i++) find(d[i].id);
	// for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
	// cout<<"\n";
	for(int i=1;i<=n;i++) if(vis[d[i].id]>d[i].v) return 0;
	return 1;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=2;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	ll l=0,r=1000000001;
	ll ans;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid,ans=mid;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}
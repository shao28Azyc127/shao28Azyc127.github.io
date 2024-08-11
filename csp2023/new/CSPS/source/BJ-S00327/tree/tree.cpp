#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;
const int N=1e5+5;
const ll inf=1e9+7;
int n;
ll a[N];
int b[N],c[N];
int bd[N];
vector<int> edg[N];
int dep[N],dfn[N],kk=0;
int inv[N];
int zu[N][20];
int siz[N];
void dfs(int idx,int fa)
{
	dfn[idx]=++kk;
	inv[kk]=idx;
	zu[idx][0]=fa;
	dep[idx]=dep[fa]+1;
	siz[idx]=1;
	for(int to:edg[idx])
	{
		if(to==fa) continue;
		dfs(to,idx);
		siz[idx]+=siz[to];
	}
}
void dfss(int idx)
{
	int i;
	for(i=1;i<=17;i++)
		zu[idx][i]=zu[zu[idx][i-1]][i-1];
	for(int to:edg[idx])
	{
		if(to==zu[idx][0]) continue;
		dfss(to);
	}
}
void init()
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(c[i]>=0) bd[i]=inf;
		else {
			bd[i]=-(b[i]/c[i]);
		}
	}
	dep[0]=0;
	kk=0;
	dfs(1,0);
	dfss(1);
}
bool calc(int x,int lim,int tv)
{
	if(tv>=bd[x]) return lim-tv+1;
	i128 vv=max(0,lim-bd[x]+1);
	lim=min(lim+1,bd[x]);
	ll tvv;
	vv+=(ll)b[x]*(lim-tv)+vv;
	vv+=(i128)(tv+lim-1)*(lim-tv)/2*c[x];
	return vv>=a[x];
}
int mn[N];
void get(int x,int lim)
{
	int l=1,r=lim,mid,tv=0;
	if(c[x]==0) {
		mn[x]=lim+1-((a[x]-1)/b[x]+1);
		return;	
	}
	while(l<=r)
	{
		mid=(l+r)>>1;
		//cout<<x<<" "<<l<<" "<<r<<" "<<mid<<endl;
		if(calc(x,lim,mid)) l=mid+1,tv=mid;
		else r=mid-1;
	}
	mn[x]=tv;
}
struct node{
	int v;
	int pos;
	node(int a=0,int b=0):v(a),pos(b){}
}v[N<<2];
int tag[N<<2];
node minn(node a,node b){ return a.v<=b.v?a:b;}
void build(int l,int r,int idx)
{
	tag[idx]=0;
	if(l==r)
	{
		v[idx]=node(mn[inv[l]]-dep[inv[l]],inv[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,idx<<1);
	build(mid+1,r,idx<<1|1);
	v[idx]=minn(v[idx<<1],v[idx<<1|1]);
}
void modify(int l,int r,int tl,int tr,int vv,int idx)
{
	if(l>=tl&&r<=tr)
	{
		tag[idx]+=vv;
		v[idx].v+=vv;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=tl) modify(l,mid,tl,tr,vv,idx<<1);
	if(mid<tr) modify(mid+1,r,tl,tr,vv,idx<<1|1);
	v[idx]=minn(v[idx<<1],v[idx<<1|1]);
	v[idx].v+=tag[idx];
}
int in[N];
int get_fa(int x)
{
	int i;
	for(i=17;i>=0;--i)
		if(in[zu[x][i]]==-1) x=zu[x][i];
	return x;
}
bool check(int lim)
{
	int i,j;
	for(i=1;i<=n;i++) in[i]=-1;
	in[0]=0;
	for(i=1;i<=n;i++) {
		get(i,lim);
		if(mn[i]<=0) return false;
	}	
	build(1,n,1);
	node x;
	int fa;
	for(i=1;i<=n;i++)
	{
		x=v[1];
		if(i>mn[x.pos]) return false;
		fa=get_fa(x.pos);
		in[fa]=i;
		modify(1,n,dfn[fa],dfn[fa],inf,1);
		if(siz[fa]>1) modify(1,n,dfn[fa],dfn[fa]+siz[fa]-1,1,1);
	}
	return true;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++) scanf("%lld%d%d",&a[i],&b[i],&c[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		edg[j].push_back(k);
		edg[k].push_back(j);
	}
	init();
	int l=0,r=inf-7,mid,tv;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)) r=mid-1,tv=mid;
		else l=mid+1;
	}
	printf("%d\n",tv);
	return 0;
}
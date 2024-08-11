#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=5e5+10;
int n,m,k,d;
struct sgt{
	int tot;
	struct seg{
		int ls,rs;ll max,add;
		seg(){ls=rs=add=0,max=-1e18;}
	}t[N<<5];
	sgt(){tot=0;}
	void init()
	{
		for(int i=0;i<=tot;i++)t[i].ls=t[i].rs=t[i].add=0,t[i].max=-1e18;
		tot=0;
	}
	void build(int &p,int l,int r)
	{
		p=++tot;
		t[p].max=1ll*(r+1)*d;
	}
	void pd(int p,int l,int r)
	{
		if(t[p].add)
		{
			int mid=(l+r)>>1;
			if(!t[p].ls)build(t[p].ls,l,mid);
			if(!t[p].rs)build(t[p].rs,mid+1,r);
			t[t[p].ls].add+=t[p].add;
			t[t[p].rs].add+=t[p].add;
			t[t[p].ls].max+=t[p].add;
			t[t[p].rs].max+=t[p].add;
			t[p].add=0;
		}
	}
	void modify(int &p,int l,int r,int L,int R,ll d)
	{
		if(L>R)return;
		if(!p)build(p,l,r);
		if(L<=l&&r<=R)
		{
			t[p].add+=d;
			t[p].max+=d;
			return;
		}pd(p,l,r);
		int mid=(l+r)>>1;
		if(L<=mid)modify(t[p].ls,l,mid,L,R,d);
		if(R>mid)modify(t[p].rs,mid+1,r,L,R,d);
		t[p].max=max(t[t[p].ls].max,t[t[p].rs].max);
	}
	ll query(int p,int l,int r,int L,int R)
	{
		if(!p)return 1ll*(R+1)*d;
		if(L<=l&&r<=R)return t[p].max;
		pd(p,l,r);
		int mid=(l+r)>>1;ll ans=0;
		if(L<=mid)ans=max(ans,query(t[p].ls,l,mid,L,R));
		if(R>mid)ans=max(ans,query(t[p].rs,mid+1,r,L,R));
		return ans;
	}
	void cover(int &p,int l,int r,int x,ll d)
	{
		if(!p)build(p,l,r);
		if(l==r)
		{
			t[p].max=max(t[p].max,d);
			return;
		}pd(p,l,r);
		int mid=(l+r)>>1;
		if(x<=mid)cover(t[p].ls,l,mid,x,d);
		else cover(t[p].rs,mid+1,r,x,d);
		t[p].max=max(t[t[p].ls].max,t[t[p].rs].max);
	}
}T;
struct node{
	int l,r,v;
	node(){v=l=r=0;}
}a[N];
bool cmp(node x,node y){return x.r<y.r;}
void sol()
{
	n=read(),m=read(),k=read(),d=read();
	T.init();//[-1, n]
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),val=read();
		int l=x-y+1,r=x;
		a[i].l=l,a[i].r=r,a[i].v=val;
	}
	sort(a+1,a+m+1,cmp);
	ll last=0;int rt=0;
	for(int i=1;i<=m;i++)
	{
		int l=a[i].l,r=a[i].r,val=a[i].v;
		T.modify(rt,-1,n,-1,l-2,val);
		ll f=-1ll*r*d+T.query(rt,-1,n,max(-1,r-k-1),r-2);
		f=max(f,last);
		T.cover(rt,-1,n,r,1ll*(r+1)*d+f);
		T.modify(rt,-1,n,r+1,n,-last);
		T.modify(rt,-1,n,r+1,n,f);
		last=max(last,f);
	}
	printf("%lld\n",last);
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c=read(),T=read();
	for(int i=1;i<=T;i++)sol();
	return 0;
}
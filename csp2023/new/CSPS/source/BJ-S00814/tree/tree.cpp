#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int a[100005],n,A[100005],B[100005],C[100005],dep[100005],dfn[100005],sz[100005];
vector<int> e[100005];
int dfnow,dfp[100005];
void dfs0(int u,int f)
{
	sz[u]=1,dfn[u]=++dfnow,dfp[dfnow]=u;
	for(auto v:e[u])
		if(v!=f) dep[v]=dep[u]+1,dfs0(v,u),sz[u]+=sz[v];
}
__int128 mul(int x,int y)
{
	return (__int128)x*y;
}
__int128 cal(int b,int c,int t)
{
	if(c<0) b+=(t+1)*c,c=-c;
	int l=b+1*c,r=b+t*c;
	if(r<=1) return (__int128)t;
	if(l>=1) return mul((l+r),t)/2;
	int p=1;
	int d=(1-l)/c-1;
	p=max(p,d);
	while(b+(p+1)*c<1) ++p;
	while(b+(p)*c>1) --p;
	return p+mul((b+(p+1)*c+r),(t-p))/2;//bao long long?
}
void dfs1(int u,int f)
{
	for(auto v:e[u])
		if(v!=f) dfs1(v,u),a[u]=min(a[u],a[v]-1);
}
const int K=1e7;
struct ds
{
	struct node
	{
		int add,mn,mnpos;
	}t[300005];
	int b[100005];
	void upd(int u)
	{
		t[u].mn=min(t[u*2].mn,t[u*2+1].mn);
		if(t[u*2+1].mn==t[u].mn) t[u].mnpos=t[u*2+1].mnpos;
		else t[u].mnpos=t[u*2].mnpos;
	}
	void give(int u,int x)
	{
		t[u].add+=x,t[u].mn+=x;
	}
	void pd(int u)
	{
		give(u*2,t[u].add);
		give(u*2+1,t[u].add);
		t[u].add=0;
	}
	void build(int u,int l,int r)
	{
		t[u]={0,0,0};
		if(l==r)
		{
			t[u]={0,b[l],l};
			return ;
		}
		int mid=(l+r)/2;
		build(u*2,l,mid),build(u*2+1,mid+1,r);
		upd(u);
	}
	void init()
	{
		for(int i=1;i<=n;i++)
			b[dfn[i]]=(a[i]-dep[i]+1)*K+dep[i];
		build(1,1,n);
	}
	int getmn()
	{
		return dfp[t[1].mnpos];
	/*	int mn=1e18,pos=0;
		for(int i=1;i<=n;i++)
			if(b[i]<mn) mn=b[i],pos=i;
		return dfp[pos];*/
	}
	void ADD(int u,int l,int r,int ql,int qr,int x)
	{
		if(l==ql&&r==qr)
		{
			give(u,x);
			return ;
		}
		pd(u);
		int mid=(l+r)/2;
		if(mid>=qr) ADD(u*2,l,mid,ql,qr,x);
		else if(mid+1<=ql) ADD(u*2+1,mid+1,r,ql,qr,x);
		else ADD(u*2,l,mid,ql,mid,x),ADD(u*2+1,mid+1,r,mid+1,qr,x);
		upd(u);
	}
	void add(int l,int r,int x)
	{
		ADD(1,1,n,l,r,x);
	//	for(int i=l;i<=r;i++) b[i]+=x;
	}
}D;
bool check(int T)
{
	for(int i=1;i<=n;i++)
	{
		int L=0,R=T;
		__int128 X=cal(B[i],C[i],T);
	/*	if(T==5)
		{
			cout << i << "?" << X << "!\n";
		}*/
		if(X<A[i]) return 0;
		a[i]=0;
		while(L<=R)
		{
			int M=(L+R)/2;
			if(X-cal(B[i],C[i],M)>=A[i]) a[i]=M+1,L=M+1;
			else R=M-1;
		//	cerr << L << " " << R << "\n";
		}
	}
/*	if(T==5)
	{
		for(int i=1;i<=n;i++)
		{
			cout << a[i] << "?";
		}
		cout << "\n";
	}*/
	dfs1(1,0);
	if(a[1]<=0) return 0;
	D.init();
	for(int i=1;i<=n;i++)
	{
		int id=D.getmn();
		if(i>a[id]) return 0;
		//if(T==5) cerr << id << " "<< "???\n";
		D.add(dfn[id],dfn[id]+sz[id]-1,K);
		D.add(dfn[id],dfn[id],3e18);
	}
	return 1;
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> A[i] >> B[i] >> C[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dep[1]=1;
	dfs0(1,0);
	int l=n,r=1e9,ans=1e9;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
//	check(5);
	cout << ans;
	return 0;
}
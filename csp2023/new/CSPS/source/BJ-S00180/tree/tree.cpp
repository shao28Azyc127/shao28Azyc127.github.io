//lxy qwq
//Csp-s Rp++
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define int long long
#define ull unsigned long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i++)
#define C continue
#define WA cerr<<"QWQ\n"
#define MAXN 100019
#define H cout<<"\n"
#define pb push_back
#define pk pop_back
const int MOD=998244353;
int ksm(int x,int y) 
{
	int ba=x,ans=1;
	while(y) 
	{ 
		if(y&1) { ans*=ba; ans%=MOD; } 
		ba*=ba; ba%=MOD;
	}
	return ans%MOD;
}
int n;
struct qw{int a,b,c; } l[MAXN];
vector<int> pq[MAXN];
int ti[MAXN];
int mx[MAXN];
int clac(int p,int tt)
{
	int tot=0;
	int pl=-1;
	int aa=l[p].a,bb=l[p].b,cc=l[p].c;
	For(i,tt,11451419)
	{
		tot+=max(1ll,bb+i*cc);
		if(bb+i*cc<0) { pl=i; break; }
		if(tot>=aa) return i;
	}
	pl+=(aa-tot);
	return min(pl,aa+tt);
}
bool cmp(qw x,qw y)
{
	if(n<=500) { return (x.a==y.a)?(x.c>y.c):(x.a<y.a); }
	if(x.c==y.c) return x.b>y.b;
	return x.c>y.c;
}
void dfs(int p,int fa,int t)
{
	int ans=0;
	int tot=t;
	mx[p]=ti[p]=clac(p,t);
	sort(pq[p].begin(),pq[p].end());
	for(auto i:pq[p])
	{
		if(i==fa) C;
		dfs(i,p,tot);
		mx[p]=max(mx[p],mx[i]);
		tot+=ti[p];
	}
	return ;
}
 main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cin>>n;
	For(i,1,n) cin>>l[i].a>>l[i].b>>l[i].c;
	FOR(i,1,n) { int u,v; cin>>u>>v; pq[u].pb(v); pq[v].pb(u); }
	dfs(1,-1,0);
	cout<<mx[1]<<"\n";
	return 0;
}
//Lxy qwq
//Noip Rp++
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(a);i>(b);i--)
#define C continue
#define WA cerr<<"LXY\n";
#define WR(x) cerr<<x<<"\n";
#define G(i,p) for(auto i:pq[p])
#define VG(i,p) for(int i=0;i<pq[p].size();i++)
#define LG(i,p) for(int i=hd[p];i;i=nxt[i])
#define fi first
#define se second
#define pb push_back
#define pk pop_back
#define MAXN 500019
#define H cout<<"\n"
#define WH cerr<<"\n";
#define INF 0x3f3f3f3f
#define pii pair<int,int>
int id,_; int n,m;
vector<int> pq[MAXN*2]; int nt[MAXN]; int tim[MAXN];
int kd[MAXN]; void add(int u,int v) { pq[u].pb(v); }//1 T 2 F 3 U
bool v56[MAXN]; bool gd[MAXN];
void init()
{ For(i,1,n*2) pq[i].clear();
For(i,1,n*2) kd[i]=-1;
	memset(tim,0,sizeof(tim)); memset(nt,0,sizeof(nt)); //memset(kd,0,sizeof(kd));
	memset(gd,0,sizeof(gd)); memset(v56,0,sizeof(v56));
return ;
}
void sub_34() { int rt=0; For(i,1,n) { if(kd[i]=='U') { rt++; } } cout<<rt<<"\n"; return ; }
void dfs56(int p,int ti)
{
if(v56[p]) {return ; }v56[p]=1; nt[p]=max(nt[p],ti);
G(i,p) { if(!v56[i]) { dfs56(i,ti); } } return ;
}
void gfs(int p,int ti)
{
	if(gd[p]) return ;
	gd[p]=1; v56[p]=0;
	G(i,p)
	{
		if(ti>=nt[i]&&!gd[i]) gfs(i,ti);
	}
	return ;
}
void sub_56()
{
	//For(i,1,m) {  char op; int u,v; cin>>op>>u; if(op=='+') { cin>>v; add(u,v); } }
	For(i,1,n) { v56[i]=0; } int rt=0;
	For(i,1,n) if(kd[i]==3) dfs56(i,nt[i]);
	For(i,1,n) if(!v56[i]) gfs(i,tim[i]);
	For(i,1,n) if(v56[i]) rt++;
	cout<<rt<<"\n"; return ;
} bool ins[MAXN]; bool tg[MAXN];
int low[MAXN*2],dfn[MAXN*2]; int cnt=0;
int bl[MAXN*2]; int cdn=0; vector<int> q;
vector<int> ans[MAXN];
void tarjan(int p)
{//WR(p);
	low[p]=dfn[p]=++cdn;
	q.pb(p); ins[p]=1;
	G(i,p)
	{
		if(!dfn[i]) { tarjan(i); low[p]=min(low[p],low[i]); }
		else if(ins[i]){ low[p]=min(low[p],dfn[i]); }
	}
	if(low[p]==dfn[p])
	{++cnt;
		while(!q.empty())
		{
		//WA
			int bk=q.back(); q.pk();
			ins[bk]=0; bl[bk]=cnt; ans[cnt].pb(bk);
			if(bk==p) break;
		}
	}
	return ;
}
bool hf[MAXN]; int sz[MAXN];
int fa[MAXN]; int fd(int x) { if(fa[x]==x) return x; return fa[x]=fd(fa[x]); }
pii dfss(int p)
{
	if(hf[p]) return make_pair(0,tg[bl[p]]);
//if(tg[bl[p]]) {WA }
	hf[p]=1;
	int rt=tg[bl[p]],szz=1;
	if(p>n) szz=0;
	G(i,p)
	{
		if(fa[i]==fa[p]&&!hf[i]) { pii qwq=dfss(i); rt|=qwq.se; szz+=qwq.fi; }
	}
	return make_pair(szz,rt);
}
void sub_78()
{//WA
	For(i,1,n*2) { ins[i]=tg[i]=0; dfn[i]=low[i]=0; sz[i]=0; bl[i]=0; hf[i]=0; ans[i].clear(); }
	q.clear();
	cnt=cdn=0;	int rt=0;
	//cerr<<n<<" "<<m<<"\n";
	For(i,1,n) { if(!dfn[i]) tarjan(i); }
	For(i,1,n*2) fa[i]=i; 
	fa[0]=0;
	//WR(bl[200000]);
	For(i,1,n)
	{
		if(tg[bl[i]]) C;
		if(bl[i+n]==bl[i]&&bl[i]!=0) { tg[bl[i]]=1; }
	}//WA;
	For(i,1,n*2) G(j,i)
	{	
		//if(bl[i]==bl[j]) C;
		fa[fd(i)]=fd(j);
	}
	For(i,1,n*2) { fa[i]=fd(i); }
	For(i,1,n) if(!hf[i]) { pii rtt=dfss(i); if(rtt.se) { rt+=rtt.fi; } }
	cout<<rt<<"\n";
	return ;
}
 main()
{
	//freopen("in.txt","r",stdin);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	//freopen("out.txt","w",stdout);
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>id>>_;//WR(id); 
	For(__,1,_)
	{
		init(); cin>>n>>m;
		For(i,1,m) { char op; int u,v; cin>>op>>u;
		if(op=='+') { cin>>v; tim[v]=i; add(v,u); add(v+n,u+n); }
		if(op=='-') { cin>>v; tim[v]=i; add(v,u+n); add(v+n,u); }
		if(op=='T') { kd[u]=1; nt[u]=i; }
		if(op=='F') { kd[u]=2; nt[u]=i; }
		if(op=='U') { kd[u]=3; nt[u]=i; }
		}
		//if(__==2) C;
        //tarjan(1);
		if(id==3||id==4) { sub_34(); C; }
		if(id==5||id==6) { sub_56(); C; }
		if(id==7||id==8) { sub_78(); C; }
		cout<<"0\n";
	}
	return 0;
}
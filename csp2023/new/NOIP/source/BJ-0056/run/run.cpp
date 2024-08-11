#include<cstdio>
#include<vector>
#include<algorithm>
char buf[1<<21],*p1=buf,*p2=buf;
inline char Getc(){if(p1==p2){p2=(p1=buf)+fread(buf,1,1<<21,stdin);if(p1==p2) return EOF;}return *p1++;}
inline int rd()
{
	static char ch;
	while(ch=Getc(),ch<'0'||ch>'9');
	int x=ch^'0';
	while(ch=Getc(),'0'<=ch&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');
	return x;
}
typedef long long ll;
const int N=100010;
int n,m,k,d;
struct Node{ll mx,tag;}t[N<<2];
inline void pushup(int o){t[o].mx=std::max(t[o<<1].mx,t[(o<<1)|1].mx);}
inline void pushtag(int o,ll v){t[o].mx+=v,t[o].tag+=v;}
inline void pushdown(int o){if(t[o].tag) pushtag(o<<1,t[o].tag),pushtag((o<<1)|1,t[o].tag),t[o].tag=0;}
void build(int o,int L,int R)
{
	t[o].tag=0;
	if(L==R){t[o].mx=(ll)L*d;return ;}
	int mid=(L+R)>>1;
	build(o<<1,L,mid),build((o<<1)|1,mid+1,R);
	pushup(o);
}
void Modify(int o,int ls,int rs,int ql,int qr,ll v)
{
	if(ql<=ls&&rs<=qr){pushtag(o,v);return ;}
	pushdown(o);
	int mid=(ls+rs)>>1;
	if(ql<=mid) Modify(o<<1,ls,mid,ql,qr,v);
	if(mid<qr) Modify((o<<1)|1,mid+1,rs,ql,qr,v);
	pushup(o);
}
ll Query(int o,int ls,int rs,int ql,int qr)
{
	if(ql<=ls&&rs<=qr) return t[o].mx;
	pushdown(o);
	int mid=(ls+rs)>>1;
	ll res=-1e18;
	if(ql<=mid) res=Query(o<<1,ls,mid,ql,qr);
	if(mid<qr) res=std::max(res,Query((o<<1)|1,mid+1,rs,ql,qr));
	return res;
}
int x[N],y[N],v[N];
ll f[N];
std::vector<int> G[N];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c=rd(),T=rd();
	while(T--)
	{
		n=rd(),m=rd(),k=rd(),d=rd();
		for(int i=1;i<=n;++i) G[i].clear();
		for(int i=1;i<=m;++i) x[i]=rd(),y[i]=rd(),v[i]=rd();
		for(int i=1;i<=m;++i) if(x[i]<=n) G[x[i]].emplace_back(i);
		build(1,1,n);
		for(int i=1;i<=n;++i)
		{
			for(int j:G[i]) if(x[j]-y[j]+1>=1) Modify(1,1,n,1,x[j]-y[j]+1,v[j]);
			f[i]=std::max(f[i-1],Query(1,1,n,std::max(i-k+1,1),i)-(ll)(i+1)*d);
			if(i+2<=n) Modify(1,1,n,i+2,i+2,f[i]);
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}
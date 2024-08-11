#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define pc putchar
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
const ll INF=(ll)1e9+7;
const ll LLINF=(ll)1e18+7;
const ld EPS=1e-8;
const ld LDEPS=1e-14;
inline ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
inline ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
inline ll lowbit(ll x){return x&(-x);}
inline ll read()
{
	ll x=0,f=0;char ch=getchar();
	while(!isdigit(ch))
	{
		f|=(ch=='-');
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	return f?-x:x;
}
inline void write(ll x)
{
	if(x<0)
	{
		pc('-');x=-x;
	}
	if(x>9)write(x/10);
	pc(x%10+'0');
}
const ll MAXN=1e5+7;
ll n,m,a[MAXN],vis[MAXN],fa[MAXN],in[MAXN];
struct QUE
{
	char op;ll x,y;
}q[MAXN];
ll f(char c)
{
	if(c=='T')return 1;
	if(c=='F')return -1;
	if(c=='U')return 0;
	return -INF;
}
inline ll Abs(ll x)
{
	return x>0?x:-x;
}
vector<ll>g[MAXN];
void check()
{
	for(ll i=1;i<=m;i++)
	{
		if(q[i].op=='-')
		{
			a[q[i].x]=-a[q[i].y];
		}
		else if(q[i].op=='+')
		{
			a[q[i].x]=a[q[i].y];
		}
		else
		{
			a[q[i].x]=f(q[i].op);
		}
	}
}
ll F[MAXN];
bitset<MAXN>V;
ll find(ll x)
{
	// cout<<x<<'\n';
	V[x]=1;
	if(Abs(F[x])!=x)
	{
		if(!V[Abs(F[x])])
		{
			if(F[x]>0)F[x]=find(F[x]);
			else F[x]=-find(-F[x]);
		}
		
	}V[x]=0;
	return F[x];
}
bool flag[MAXN];
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ll C=read(),T=read();
	while(T--)
	{

		n=read(),m=read();
		for(ll i=1;i<=n;i++)fa[i]=i,vis[i]=0,a[i]=INF,F[i]=0;
		for(ll i=1;i<=m;i++)
		{
			scanf("%c",&q[i].op);
			if(q[i].op=='-')
			{
				q[i].x=read(),q[i].y=read();
				vis[q[i].x]=vis[q[i].y];
				fa[q[i].x]=-fa[q[i].y];
			}
			else if(q[i].op=='+')
			{
				q[i].x=read(),q[i].y=read();
				vis[q[i].x]=vis[q[i].y];
				fa[q[i].x]=fa[q[i].y];
			}
			else
			{
				q[i].x=read();
				vis[q[i].x]=1;fa[q[i].x]=f(q[i].op);
			}
		}
		// if(T!=2)continue;
		ll ans=0;
		for(ll i=1;i<=n;i++)
		{
			if(vis[i])a[i]=fa[i];
			else
			{
				if(fa[i]==-i)a[i]=0;
				else if(fa[i]==i)a[i]=1;
				else a[i]=INF;
			}
		}

		// for(ll i=1;i<=n;i++)cout<<fa[i]<<' ';pc(10);
		// a[3]=9,a[8]=-1,a[6]=1,a[5]=-1,a[4]=1,a[3]=1;
		// check();
		// for(ll i=1;i<=n;i++)
		// {
		// 	cout<<a[i]<<' ';
		// }pc(10);
		for(ll i=1;i<=n;i++)g[i].clear(),in[i]=0;
		for(ll i=1;i<=n;i++)
		{
			if(!vis[i]&&fa[i]!=i&&fa[i]!=-i)
			{
				g[Abs(fa[i])].push_back(i);
				in[i]++;
			}
			
		}
		queue<ll>q;
		for(ll i=1;i<=n;i++)if(a[i]!=INF)q.push(i);
		while(q.size())
		{
			ll u=q.front();q.pop();
			for(ll i=0;i<g[u].size();i++)
			{
				ll v=g[u][i];--in[v];
				if(fa[v]>0)a[v]=a[u];
				else a[v]=-a[u];
				if(!in[v])q.push(v);
			}
		}
		// puts("AWA");
		for(ll i=1;i<=n;i++)if(a[i]==INF||a[i]==-INF)F[i]=fa[i];
		for(ll i=1;i<=n;i++)if(a[i]==INF||a[i]==-INF)
		{
			// cout<<F[i]<<'\n';
			if(find(i)==-i)
			{
				flag[i]=1;
				a[i]=0;
			}
		}
		for(ll i=1;i<=n;i++)g[i].clear(),in[i]=0;
		for(ll i=1;i<=n;i++)if(a[i]==INF||a[i]==-INF)
		{
			g[Abs(F[i])].push_back(i);in[Abs(F[i])]++;
		}
		for(ll i=1;i<=n;i++)if(flag[i])q.push(i);
		while(q.size())
		{
			ll u=q.front();q.pop();
			for(ll i=0;i<g[u].size();i++)
			{
				ll v=g[u][i];--in[v];
				if(F[v]>0)a[v]=a[u];
				else a[v]=-a[u];
				if(!in[v])q.push(v);
			}
		}
		for(ll i=1;i<=n;i++)if(!a[i])ans++;
		write(ans),pc(10);
	}
	return 0;
}
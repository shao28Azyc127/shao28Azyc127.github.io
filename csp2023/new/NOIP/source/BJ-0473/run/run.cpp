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
#define F first
#define S second
const ll MAXN=2007;
ll n,m,K,D,dp[MAXN],w[MAXN][MAXN];
struct NODE
{
	ll l,r,v;
	bool operator<(const NODE& xx)const
	{
		return l!=xx.l?l<xx.l:r<xx.r;
	}
}a[MAXN];
set<pair<ll,ll> >s;
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ll C=read(),T=read();
	while(T--)
	{
		n=read(),m=read(),K=read(),D=read();
		mem(w,0);mem(dp,0);
		for(ll i=1;i<=m;i++)
		{
			ll l=read(),r=read(),v=read();
			if(l-r+1<1)
			{
				i--,m--;continue;
			}
			ll x=l-r+1,y=l;
			a[i].l=x,a[i].r=y,a[i].v=v;
		}sort(a+1,a+m+1);
		a[0].l=0;s.clear();
		for(ll i=1;i<=n;i++)
		{
			ll pos=0;
			while(pos<=m&&a[pos].l<i)pos++;
			for(ll j=i;j<=n;j++)
			{
				while(pos<=m&&a[pos].l<=j)
				{
					// cout<<pos<<' '<<a[pos].v<<'\n';
					s.insert(make_pair(a[pos].r,a[pos].v));
					pos++;
				}
				ll sum=0;
				while(s.size()&&(*s.begin()).F<=j)
				{
					sum+=(*s.begin()).S;
					s.erase(s.begin());
				}
				w[i][j]=w[i][j-1]+sum;
			}
		}
		// for(ll i=1;i<=n;i++)
		// {
		// 	for(ll j=1;j<=n;j++)
		// 	{
		// 		cout<<w[i][j]<<' ';
		// 	}pc(10);
		// }
		for(ll i=1;i<=n;i++)
			for(ll j=i;j<=n;j++)
			{
				if((j-i+1)<=K)dp[j]=max(dp[j],w[i][j]-(j-i+1)*D);
			}
		for(ll i=1;i<=n;i++)
		{
			dp[i]=max(dp[i],dp[i-1]);
			for(ll j=i;j>=2&&(i-j+1)<=K;j--)
				dp[i]=max(dp[i],dp[j-2]+w[j][i]-(i-j+1)*D);
		}
		write(dp[n]),pc(10);
	}
	return 0;
}
#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define pc putchar
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
const ll INF=1e9+7;
const ll LLINF=1e18+7;
inline ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
inline ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
inline ll lowbit(ll x){return x&(-x);}
inline ll read()
{
	ll x=0,f=0;char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
inline void write(ll x){if(x<0){x=-x;pc('-');}if(x>9)write(x/10);pc(x%10+'0');}
const ll MAXN=1e5+7,MAXM=17;
ll n;
vector<ll>b[MAXN],a[MAXM];
bool check(ll x)
{
	for(ll i=1;i<=n;i++)
	{
		ll pos=-1,pos1=0,cntt=0;
		for(ll j=0;j<5;j++)
		{
			if(b[x][j]!=a[i][j])
			{
				if(pos==-1)pos=j;
				else pos1=j;
				cntt++;
			}
		}
		// cout<<cntt<<'\n';
		if(!cntt)return 0;
		if(cntt>2)return 0;
		if(cntt==1)continue;
		// return 0;
		if(pos1!=pos+1)return 0;
		ll xx=a[i][pos]-b[x][pos],yy=a[i][pos1]-b[x][pos1];
		// if(x==)
		// cout<<xx<<' '<<yy<<'\n';
		if(xx<0)xx+=10;
		if(yy<0)yy+=10;
		// xx=(xx+10)%10,yy=(yy+10)%10;
		if(xx!=yy)return 0;
		// puts("AWA");
	}
	return 1;
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=5;j++)
		{
			ll x=read();
			a[i].push_back(x);
		}
	}
	ll cnt=0;
	for(ll i=0;i<=9;i++)for(ll j=0;j<=9;j++)for(ll k=0;k<=9;k++)for(ll l=0;l<=9;l++)for(ll z=0;z<=9;z++)
	{
		b[++cnt].push_back(i),b[cnt].push_back(j),b[cnt].push_back(k),b[cnt].push_back(l),b[cnt].push_back(z);
	}
	// for(ll i=0;i<5;i++)cout<<b[11116][i]<<' ';pc(10);
	// cout<<check(11116)<<'\n';
	// return 0;
	ll ans=0;
	for(ll i=1;i<=cnt;i++)
	{
		if(check(i))ans++;
	}write(ans),pc(10);
	return 0;
}
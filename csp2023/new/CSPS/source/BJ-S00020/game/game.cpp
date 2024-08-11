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
const ll MAXN=2e6+7;
ll n,l[MAXN],siz[MAXN];
char s[MAXN];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();
	scanf("%s",(s+1));
	// for(ll i=1;i<=n;i++)
	// 	cout<<s[i];pc(10);
	for(ll i=1;i<=n;i++)
		l[i]=i,siz[i]=0;
	ll ans=0;
	for(ll i=2;i<=n;i++)
	{
		ll pre=i-1;
		// cout<<i<<' '<<pre<<'\n';
		// cout<<s[i]<<' '<<s[pre]<<'\n';
		// bool f=1;
		if(l[pre]!=pre)
		{
			// f=0;
			ll xx=l[pre]-1;
			if(s[i]!=s[xx])
			{
				// f=1;
				if(s[pre]==s[i])
				{
					// cout<<i<<'\n';
					if(l[i-2]==i-2)l[i]=i-1,siz[i]=1;
					else l[i]=l[i-2],siz[i]=siz[i-2]+1;
				}
				ans+=siz[i];
				continue;
			}
			ll yy=xx-1;
			if(l[yy]!=yy)l[i]=l[yy],siz[i]=siz[yy]+1;
			else l[i]=xx,siz[i]=1;
		}
		else if(s[pre]==s[i])
		{
			// cout<<i<<'\n';
			if(l[i-2]==i-2)l[i]=i-1,siz[i]=1;
			else l[i]=l[i-2],siz[i]=siz[i-2]+1;
		}
		ans+=siz[i];
	}
	write(ans),pc(10);
	return 0;
}
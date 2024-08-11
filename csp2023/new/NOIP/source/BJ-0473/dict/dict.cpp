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
const ll MAXN=3007,MAXM=35;
ll n,m,a[MAXN][MAXM],ans[MAXN],minn[MAXN],maxn[MAXN];
char s[MAXN][MAXN];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;i++)
	{
		scanf("%s",(s[i]+1));
		for(ll j=1;j<=m;j++)
			a[i][s[i][j]-'a']++;
		minn[i]=-1;
		for(ll j=0;j<26;j++)
		{
			if(a[i][j]&&minn[i]==-1)minn[i]=j;
			if(a[i][j])maxn[i]=j;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		bool f=1;vector<ll>tmp;
		for(ll j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(minn[i]>=maxn[j])
			{
				tmp.push_back(j);f=0;
			}
		}
		// if(i==437)
		// {
		// 	puts("AWA");
		// 	cout<<minn[i]<<' ';pc(10);
		// 	for(ll j=0;j<26;j++)
		// 	{
		// 		cout<<a[i][j]<<' ';
		// 	}pc(10);puts("AWA");
		// 	for(ll j=0;j<tmp.size();j++)
		// 	{
		// 		cout<<tmp[j]<<':';
		// 		for(ll k=0;k<26;k++)cout<<(ll)a[tmp[j]][k]<<' ';pc(10);
		// 	}puts("AWA");
			
		// }
		ans[i]=f;
	}
	for(ll i=1;i<=n;i++)write(ans[i]);pc(10);
	return 0;
}
//Lxy qwq
//Noip Rp++
#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
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
int n,m,c,q;
int a[MAXN],b[MAXN];
int sv()
{
	if(n<=1&&m<=1) { return 1; }
	bool fl=0;
	if(a[1]>b[1]) fl=1;
	if(c==2)
	{
		if(fl) 
		{ 
			return !(a[1]<b[2]&&a[2]<b[2]&&a[2]<b[1]);
		}
		else
		{
			return !(a[1]>b[2]&&a[2]>b[2]&&a[2]>b[1]);
		}
	}
	if(fl) return a[n]<b[m];
	else return a[n]<b[m];
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	For(i,1,n) cin>>a[i];
	For(i,1,m) cin>>b[i];
	cout<<sv();
	while(q--)
	{
		int k1,k2; cin>>k1>>k2;
		For(i,1,k1) { int u,v; cin>>u>>v; a[u]=v; }
		For(i,1,k2) { int u,v; cin>>u>>v; b[u]=v; }
		cout<<sv();
	}cout<<"\n";
	return 0;
}
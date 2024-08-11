//lxy qwq
//Csp-s Rp++
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define WA cerr<<"QWQ\n"
#define INF 0x3f3f3f3f
#define H cout<<"\n"
#define C continue
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(b);i>=(a);i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(b);i>(a);i--)
#define MAXN 200019
#define ull unsigned long long
int n,d,tot;
struct lxy { int v,p; } a[MAXN];
bool cmp(lxy x,lxy y) { return (x.p==y.p)?(x.v<y.v):(x.p<y.p);  }
int dp[MAXN],res[MAXN];
int st[30][MAXN],ps[30][MAXN];
int Q(int l,int r)
{
	int k=log2(r-l+1);
	return (st[k][l]>st[k][r-(1<<k)+1])?(ps[k][r-(1<<k)+1]):(ps[k][l]);
}
 main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>d;
	memset(st,INF,sizeof(st));
	For(i,2,n) cin>>a[i].v;
	For(i,1,n) cin>>a[i].p,st[0][i]=a[i].p,ps[0][i]=i;
	For(i,1,n) a[i].v+=a[i-1].v;
	//For(i,1,n) cerr<<a[i].v<<" ";
	tot=a[n].v;
	//sort(a+1,a+1+n,cmp);
	For(j,1,30) For(i,1,n-(1<<j)+1) 
	st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]),
	ps[j][i]=(st[j-1][i]<st[j-1][i+(1<<(j-1))])?(ps[j-1][i]):(ps[j-1][i+(1<<(j-1))]);
	For(i,2,n)
	{
		int pos=Q(1,i-1);
		//cerr<<pos<<" ";
		int ji=ceil((a[i].v-a[pos].v-res[pos])/(d+0.0));//how L I buy
		int es=ji*d-(a[i].v-a[pos].v-res[pos]);//the res fuel
		//res[pos];
		dp[i]=dp[pos]+ji*a[pos].p;
		res[i]=es;
		//cerr<<dp[i]<<" "<<res[i]<<"\n";
	}
	//cout<<res[n]<<"\n";
	cout<<dp[n]<<"\n";
	return 0;
}
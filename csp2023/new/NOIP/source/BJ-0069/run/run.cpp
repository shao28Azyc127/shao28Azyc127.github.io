#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const ll inf=1e18;
int tid;
int n,m,lim,d;
struct node {
	int l,r;
	ll v;
	node(int a=0,int b=0,ll c=0):l(a),r(b),v(c){}
	bool operator<(node aa) {
		return r<aa.r||(r==aa.r&&l>aa.l);
	}
}opt[N];
namespace sub3
{
	void sol()
	{
		int i;
		ll ans=0;
		for(i=1;i<=m;i++)
		{
			if(opt[i].r-opt[i].l+1<=lim&&
				opt[i].v-(ll)d*(opt[i].r-opt[i].l+1)>0) 
				ans+=opt[i].v-(ll)d*(opt[i].r-opt[i].l+1);
		}
		printf("%lld\n",ans);
	}
}
namespace sub1
{
	const int M=1005;
	ll dp[M][2];
	ll vv[M];
	void sol()
	{
		int i,j;
		for(i=0;i<=n;i++) dp[i][0]=dp[i][1]=-inf;
		dp[0][0]=0;
		int ps=1;
		ll tv;
		memset(vv,0,sizeof(vv));
		for(i=1;i<=n;i++) {
			for(;ps<=m&&opt[ps].r==i;ps++)
				vv[opt[ps].l]+=opt[ps].v;
			tv=0;
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			for(j=i;j>=max(1,i-lim+1);j--) {
				tv-=d;
				tv+=vv[j];
				dp[i][1]=max(dp[i][1],dp[j-1][0]+tv);
			}
		}
		printf("%lld\n",max(dp[n][0],dp[n][1]));
		return;
	}
}
namespace sub2
{
	const int M=4005;
	ll dp[M][2];
	ll vv[M];
	int help[M],kk=0;
	void sol()
	{
		int i,j;
		kk=0;
		for(i=1;i<=m;i++)
		{
			help[++kk]=opt[i].l;
			help[++kk]=opt[i].l+1;
			help[++kk]=opt[i].r;
			help[++kk]=opt[i].r+1;
		}
		sort(help+1,help+1+kk);
		kk=unique(help+1,help+1+kk)-help-1;
		for(i=1;i<=m;i++)
		{
			opt[i].l=lower_bound(help+1,help+1+kk,opt[i].l)-help;
			opt[i].r=lower_bound(help+1,help+1+kk,opt[i].r)-help;
		}
		for(i=1;i<=kk;i++) dp[i][0]=dp[i][1]=-inf;
		dp[0][0]=0;
		memset(vv,0,sizeof(vv));
		int ps=1,lst;
		ll tv;
		for(i=1;i<=kk;i++) 
		{
			for(;ps<=m&&opt[ps].r==i;ps++)
				vv[opt[ps].l]+=opt[ps].v;
			tv=0;
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			lst=help[i];
			for(j=i;j>=1;--j) {
				if(help[i]-help[j]+1>lim) break;
				tv-=(lst-help[j]+1)*d;
				lst=help[j]-1;
				tv+=vv[j];
				dp[i][1]=max(dp[i][1],dp[j-1][0]+tv);
			}
		}
		printf("%lld\n",max(dp[kk][0],dp[kk][1]));
		return;
	}
}

namespace sub4
{
	const int M=400005;
	ll dp[M][2];
	ll vv[M];
	int help[M],kk=0;
	void sol()
	{
		int i,j;
		kk=0;
		for(i=1;i<=m;i++)
		{
			help[++kk]=opt[i].l;
			help[++kk]=opt[i].l+1;
			help[++kk]=opt[i].r;
			help[++kk]=opt[i].r+1;
		}
		sort(help+1,help+1+kk);
		kk=unique(help+1,help+1+kk)-help-1;
		for(i=1;i<=m;i++)
		{
			opt[i].l=lower_bound(help+1,help+1+kk,opt[i].l)-help;
			opt[i].r=lower_bound(help+1,help+1+kk,opt[i].r)-help;
		}
		for(i=1;i<=kk;i++) dp[i][0]=dp[i][1]=-inf;
		dp[0][0]=0;
		memset(vv,0,sizeof(vv));
		int ps=1,lst;
		ll tv;
		for(i=1;i<=kk;i++) 
		{
			for(;ps<=m&&opt[ps].r==i;ps++)
				vv[opt[ps].l]+=opt[ps].v;
			tv=0;
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			lst=help[i];
			for(j=i;j>=1;--j) {
				if(help[i]-help[j]+1>lim) break;
				tv-=(lst-help[j]+1)*d;
				lst=help[j]-1;
				tv+=vv[j];
				dp[i][1]=max(dp[i][1],dp[j-1][0]+tv);
			}
		}
		printf("%lld\n",max(dp[kk][0],dp[kk][1]));
		return;
	}
}
void sol()
{
	scanf("%d%d%d%d",&n,&m,&lim,&d);
	int i,j,k,p;
	for(i=1;i<=m;i++) {
		scanf("%d%d%d",&j,&k,&p);
		opt[i]=node(j-k+1,j,p);
	}
	sort(opt+1,opt+1+m);
	if(tid<=9) {
		sub1::sol();
		return;
	}
	else if(tid<=11) {
		sub2::sol();
		return;
	}	
	else if(tid<=16) {
		sub4::sol();
		return;
	}
	else if(tid<18) {
		sub3::sol();
		return;
	}
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int t;
	scanf("%d%d",&tid,&t);
	while(t)
	{
		--t;
		sol();
	}
	return 0;
}
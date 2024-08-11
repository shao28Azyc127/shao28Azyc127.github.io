#include<bits/stdc++.h>
using namespace std;
const long long N=1e7+11;
long long jl[N],dp[N],a[N],s[N],n,d;
void dfs(long long u,long long q,long long sy){
	long long i,dqsy;
	if(u>n){
		return ;
	}
	dp[u]=min(dp[u],q);
	for(i=u+1;i<=n;i++){
		dqsy=0;
		long long w=s[i-1]-(s[u-1]+sy);
		long long v=w/d;
		if((v*d)<w){
			v++;
			dqsy=(v*d)-w;
		}
		long long dqq=v*a[u]+q;
		dfs(i,dqq,dqsy);
	}
	return ;
}
int main (){
	long long i,j;
	long long m,f0,f1=0,l=0,k;
	memset(dp+1,0x3f,sizeof(dp));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(i=1;i<=n-1;i++){
		cin>>jl[i];
		s[i]=s[i-1]+jl[i];
	}
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	dp[1]=0;
	cout<<dp[n];
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long mp[10005][10005];
long long n,m,k;
long long minx=1e18;
void dfs(long long x,long long cnt){
	if(x==n&&cnt%k==0){
		minx=min(minx,cnt);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(mp[x][i]!=-1&&mp[x][i]<=cnt) dfs(i,cnt+1);
	}
	return ;
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	memset(mp,-1,sizeof(mp));
	cin>>n>>m>>k;
	long long maxx=-1;	
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=w;
		maxx=max(maxx,w);
	}
	for(int i=0;i<=maxx;i+=k){
		dfs(1,i);
	}
	cout<<minx;
	return 0;
}

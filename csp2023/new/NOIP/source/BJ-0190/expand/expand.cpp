#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int c,n,m,q,kx,ky,p,w;
long long x[500005],y[500005],x_[500005],y_[500005];
bool flag=0;
void dfs(int u,int v){
	if(u==n&&v==m){
		flag=1;
	}
	if(flag==1) return;
	if(v+1<=m&&(x[1]-y[1])*(x[u]-y[v+1])>0) dfs(u,v+1);
	if(flag==1) return;
	if(u+1<=n&&(x[1]-y[1])*(x[u+1]-y[v])>0) dfs(u+1,v);
	return;
}
void solve(){
	if((x[1]-y[1])*(x[n]-y[m])<=0){
		printf("0");
		return;
	}
	flag=0;
	dfs(1,1);
	printf("%d",flag);
	return;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&x_[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&y_[i]);
	for(int i=1;i<=n;i++) x[i]=x_[i];
	for(int i=1;i<=m;i++) y[i]=y_[i];
	solve();
	while(q--){
		for(int i=1;i<=n;i++) x[i]=x_[i];
		for(int i=1;i<=m;i++) y[i]=y_[i];
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<=kx;i++){
			scanf("%d%d",&p,&w);
			x[p]=w;
		}
		for(int i=1;i<=ky;i++){
			scanf("%d%d",&p,&w);
			y[p]=w;
		}
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
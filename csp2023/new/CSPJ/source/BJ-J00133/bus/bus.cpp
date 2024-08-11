#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=1e9;
int a[10005][10005];
bool vis[10005];
void dfs(int x,int t){
	if(x==n){
		ans=min(ans,t);
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[x][i]==-1 || vis[i]){
			continue;
		}
		if(t>=a[x][i]){
			vis[i]=1;
			dfs(i,t+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=m;i++){
		int v,w,s;
		cin>>v>>w>>s;
		a[v][w]=s;
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int n,m,k,ans=1e9+1;
int a[N][N];
void dfs(int x,int c){
	if(x==n&&c%k==0)ans=min(ans,c);
	for(int i=1;i<=n;i++){
		if(a[x][i]>0&&a[x][i]<=c)dfs(i,c+1);
	}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
	}
	dfs(1,0);
	if(ans!=1e9+1)cout<<ans;
	else cout<<-1;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n , m , k,ans=0;
int vis[1000005];
int u[1000005];
int v[1000005];
int a[1000005];
int g[10005][10005];
queue <int> q;
void bfs(int cur){
	q.push(cur);
	vis[cur]=1;
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		if(tmp==n){
			return;
		}
		else{
			for(int i = 1 ; i <= n ; i++){
				if(g[cur][i]==1&&vis[i]==0){
					vis[i]=1;
					q.push(i);
					ans++;
				}
			}
		}
	}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ;i++){
		cin >> u[i]>>v[i]>>a[i];
		g[u[i]][v[i]]=1;
	}
	bfs(1);
	if(ans%k==0){
		cout << ans;
	}
	else{
		cout << ((ans/k)+1)*k;
	}
	
	return 0;
}

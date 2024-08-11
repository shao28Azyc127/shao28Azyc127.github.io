#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[10004];
bool vis[10004];
struct node{
	int x,s;
};
int n,m,k,ma;
int bfs(int s);
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1,u,v,a;i<=m;i++){
		cin >> u >> v >> a;
		g[u].push_back({v,a});
		ma=max(ma,a);
	}
	for(int i=0;i<=ma;i+=k){
		int s=bfs(i);
		if(s>=0){
			cout << s;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
int bfs(int s){
	memset(vis,0,sizeof(vis));
	queue<node> q;
	q.push({1,s});
	vis[1]=true;
	while(!q.empty()){
		node now=q.front();
		q.pop();
		for(auto i:g[now.x]){
			if(!vis[i.first]&&now.s>=i.second){
				if(i.first==n){
					if((now.s+1)%k==0) return now.s+1;
				}else{
					vis[i.first]=true;
					q.push({i.first,now.s+1});
				}
			}
		}
	}
	return -1;
}

#include <bits/stdc++.h>
using namespace std;
int n, m, k, dis[10002], t;
vector<int> a[10002];
bool vis[100002];
void bfs(){
	queue<int> q;
	q.push(1);
	dis[1]=0;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		if(vis[top]){
			continue;
		}
		vis[top]=1;
		for(auto i : a[top]){
			dis[i]=min(dis[i], dis[top]+1);
			q.push(i);
		}
	}
}
int main(){
	memset(dis, 0x3f, sizeof(dis));
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin>>n>>m>>k;
	if(k==1){
		for(int i = 1; i <= m; i++){
			int u, v;
			cin>>u>>v>>t;
			a[u].push_back(v);
			if(t!=0){
				cout<<-1;
				return 0;
			}
		}
		bfs();
		if(vis[n]){
			cout<<dis[n];
		}
		else{
			cout<<-1;
		}
	}
	else{
		cout<<-1;
	}
	return 0;
}
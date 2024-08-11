#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 1e4 + 7;
const int K = 107;
ll n, m, k;
ll dis[N][K];
bool vis[N][K];

struct Node{
	ll v, k, t;
	bool operator<(const Node & no)const{
		return t > no.t;
	}
};
vector <Node> adj[N][K];
priority_queue <Node> q;

void Dij(){
	memset(dis, 127, sizeof(dis));
	dis[1][0] = 0;
	q.push({1, 0, 0});
	while(!q.empty()){
		ll u = q.top().v, d = q.top().k;
		q.pop();
		if(vis[u][d]) continue;
		vis[u][d] = 1;
		for(int i = 0; i < adj[u][d].size(); ++i){
			ll v = adj[u][d][i].v, t = adj[u][d][i].t;
			if(t > dis[u][d] * k + d){
				ll tmp;
				if((t - dis[u][d] * k - d) % k == 0){
					tmp = dis[u][d] + (t - dis[u][d] * k - d) / k;
				}else{
					tmp = dis[u][d] + (t - dis[u][d] * k - d) / k + 1;
				}
				if(d + 1 == k){
					if(dis[v][0] > tmp + 1){
						dis[v][0] = tmp + 1;
						q.push({v, (d + 1) % k, tmp + 1});
					}
				}else if(dis[v][(d + 1) % k] > tmp){
					dis[v][(d + 1) % k] = tmp;
					q.push({v, (d + 1) % k, tmp});
				}
			}else{
				if(d + 1 == k){
					if(dis[v][0] > dis[u][d] + 1){
						dis[v][0] = dis[u][d] + 1;
						q.push({v, (d + 1) % k, dis[u][d] + 1});
					}
				}else if(dis[v][(d + 1) % k] > dis[u][d]){
					dis[v][(d + 1) % k] = dis[u][d];
					q.push({v, (d + 1) % k, dis[u][d]});
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i){
		ll u, v, t;
		cin >> u >> v >> t;
		for(int j = 0; j < k; ++j){
			adj[u][j].push_back({v, (j + 1) % k, t});
		}
	}
	Dij();
	if(dis[n][0] * k >= 1e9 + 7){
		cout << "-1" << endl;
	}else{
		cout << dis[n][0] * k << endl;
	}
	return 0;
}
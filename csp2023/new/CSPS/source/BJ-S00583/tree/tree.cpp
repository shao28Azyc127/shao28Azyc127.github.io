#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
const int N = 1e5 + 7;
ll a[N], b[N], c[N], ans = 1e9 + 7;
int n, vis[N];
vector <int> adj[N];

ll Sum(ll x, ll t){
	ll tmp = 0;
	for(ll i = t; i <= 1e9 + 7; ++i){
		tmp += max(b[x] + c[x] * i, ll(1));
		if(tmp >= a[i]){
			return i;
		}
	}
	return 0;
}

void Dfs(ll t, ll now){
	ll cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(vis[i] == 0) cnt++;
		if(vis[i] == 1){
			for(int j = 0; j < adj[i].size(); ++j){
				if(vis[adj[i][j]] == 0){
					vis[adj[i][j]] = 1;
					Dfs(t + 1, max(now, Sum(adj[i][j], t) + t - 1));
					vis[adj[i][j]] = 0;
				}
			}
		}
	}
	if(cnt == 0){
		ans = min(ans, now);
		return;
	}
} 

int main(){
	ios::sync_with_stdio(false);
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> n;
	int opD = 1, opA = 1;
	for(int i = 1; i <= n; ++i){
		cin >> a[i] >> b[i] >> c[i];
		if(c[i] != 0) opA = 0;
	}
	for(int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		if(u != 1) opD = 0;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if(n <= 20){
		vis[1] = 1;
		Dfs(1, 0);
		cout << ans << endl;
	}
	return 0;
}
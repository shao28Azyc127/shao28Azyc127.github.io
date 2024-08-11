#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;
int n, m, col, ans;
int fa[N * 4], use[2 * N], vis[2 * N];
vector <int> adj[N * 2];

void Merge(int x, int y){
	fa[x] = fa[y];
}

void Init(){
	for(int i = 1; i <= 2 * n; ++i){
		fa[i] = i;
		fa[i + 2 * n] = i;
	} 
	fa[4 * n + 1] = 4 * n + 1;
	fa[4 * n + 2] = 4 * n + 2;
	fa[4 * n + 3] = 4 * n + 3;
	col = 0; ans = 0;
	memset(use, 0, sizeof(use));
	memset(adj, 0, sizeof(adj));
	memset(vis, 0, sizeof(vis));
}

void Dfs(int u, int T){
	use[u] = T;
	for(int i = 0; i < adj[u].size(); ++i){
		int v = adj[u][i];
		if(use[v] == 0){
			Dfs(v, T);
		}
	}
}

void Find(int u, int T){
	vis[u] = T;
	for(int i = 0; i < adj[u].size(); ++i){
		int v = adj[u][i];
		if(vis[v] == 0){
			Find(v, T);
		}
	}
}

void Print(int u){
	use[u] = 1;
	for(int i = 0; i < adj[u].size(); ++i){
		int v = adj[u][i];
		if(v > n){
			if(use[v] == 0) Print(v);
			if(use[v - n] == 0) Print(v - n);
		}else{
			if(use[v] == 0) Print(v); 
			if(use[v + n] == 0) Print(v + n);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int C, T;
	cin >> C >> T;
	while(T--){
		cin >> n >> m;
		Init();
		for(int i = 1; i <= m; ++i){
			char op;
			cin >> op;
			if(op == 'T'){
				int x;
				cin >> x;
				Merge(2 * n + x, 4 * n + 1);
				Merge(3 * n + x, 4 * n + 2);
			}else if(op == 'F'){
				int x;
				cin >> x;
				Merge(2 * n + x, 4 * n + 2);
				Merge(3 * n + x, 4 * n + 1);
			}else if(op == 'U'){
				int x;
				cin >> x;
				Merge(2 * n + x, 4 * n + 3);
				Merge(3 * n + x, 4 * n + 3);
			}else if(op == '+'){
				int x, y;
				cin >> x >> y;
				Merge(2 * n + x, 2 * n + y);
				Merge(3 * n + x, 3 * n + y);
			}else{
				int x, y;
				cin >> x >> y;
				if(x == y){
					int tmp = fa[3 * n + y];
					fa[3 * n + x] = fa[2 * n + y];
					fa[2 * n + x] = tmp;
					continue;
				}
				Merge(2 * n + x, 3 * n + y);
				Merge(3 * n + x, 2 * n + y);
			}
		}
		for(int i = 2 * n + 1; i <= 4 * n; ++i){
			if(fa[i] <= 2 * n){
				adj[fa[i]].push_back(i - 2 * n);
				adj[i - 2 * n].push_back(fa[i]);
			}
		}
		for(int i = 2 * n + 1; i <= 4 * n; ++i){
			if(fa[i] > 4 * n){
				Dfs(i - 2 * n, fa[i]);
			}
		}
		for(int i = 1; i <= n; ++i){
			if(use[i] == 4 * n + 3) ans++;
		}
		for(int i = 1; i <= 2 * n; ++i){
			if(use[i] || vis[i]) continue;
			col++;
			Find(i, col);
		}
		memset(use, 0, sizeof(use));
		for(int i = 1; i <= n; ++i){
			if(vis[i] == 0 || use[i]) continue;
			if(vis[i] == vis[i + n]){
				Print(i);
				Print(i + n);
			}
		}
		for(int i = 1; i <= n; ++i){
			if(use[i] == 1) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}	
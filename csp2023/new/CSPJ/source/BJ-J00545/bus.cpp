#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
const int N = 10010;
const int K = 105;
typedef pair<bool, int> P;
P dp[N][K];
vector<int> G[N];
vector<int> T[N];
int n, m, k;
vector<int> topo;
int baoli() {
	int ans = 1e9;
	queue<int> q;
	q.push(1);
	dp[1][0] = {true, 0};
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int j = 0; j < G[u].size(); j++) {
			int v = G[u][j], ti = T[u][j];
			bool upd = false;
			for (int i = 0; i < k; i++) {
				if (dp[u][i].first) {
					P t = dp[v][(i + 1) % k];
					if (!t.first || t.second > max(dp[u][i].second + 1, ti)) {
						dp[v][(i + 1) % k] = {true, max(dp[u][i].second + 1, ti)};
						upd = true;
					}
				}
			}
			if (dp[v][0].first && v == n) {
				ans = min(ans, ((dp[v][0].second + k - 1) / k) * k);
			}
			if (upd) {
				q.push(v);
			}
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	bool P1 = true/*a_i=0*/, P2 = true/*u_i<v_i*/;
	for (int i = 1; i <= m; i++) {
		int u, v, a;
		cin >> u >> v >> a;
		G[u].push_back(v);
		T[u].push_back(a);
		if (a != 0) {
			P1 = false;
		}
		if (u >= v) {
			P2 = false;
		}
	}
	if (n <= 10 || k == 1 || P2) {
		int ans = baoli();
		if (ans == 1e9) {
			cout << -1 << endl;
		} else {
			cout << ans << endl;
		}
	} else if (P1) {
		int ans = baoli();
		if (ans == 1e9) {
			cout << -1 << endl;
		} else {
			cout << ans << endl;
		}
	} else {
		int ans = baoli();
		if (ans == 1e9) {
			cout << -1 << endl;
		} else {
			cout << ans << endl;
		}
	}
	
	return 0;
}
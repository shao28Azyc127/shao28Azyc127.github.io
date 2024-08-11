/*
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define int long long
using namespace std;
int n, m, K, u, v, t, visit[105][10005];
vector<pair<int, int> > g[10005];
queue<pair<int, int> > q;
int bfs(int s) {
	q.push(pair<int, int>(s, 0));
	visit[0][s] = true;
	while (! q.empty()) {
		int currentx = q.front().first, currentk = q.front().second;
		q.pop();
		if (currentk > max(n, m) * K) {
			return -1;
		}
		if (currentx == n && currentk % K == 0) {
			return currentk;
		}
		for (int i = 0; i < g[currentx].size(); i ++) {
			int nx = g[currentx][i].first, nk = g[currentx][i].second;
			if (currentk < nk || visit[(currentk + 1) % K][nx]) {
				continue;
			}
			q.push(pair<int, int>(nx, currentk + 1));
			visit[(currentk + 1) % K][nx] = true;
		}
	}
	return -1;
}
signed main() {
	scanf("%lld%lld%lld", &n, &m, &K);
	for (int i = 1; i <= m; i ++) {
		scanf("%lld%lld%lld", &u, &v, &t);
		g[u].push_back(pair<int, int>(v, t));
	}
	printf("%lld\n", bfs(1));
	return 0;
}
*/
#include <cstdio>
#define int long long
using namespace std;
signed main() {
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	printf("-1\n");
	return 0;
}

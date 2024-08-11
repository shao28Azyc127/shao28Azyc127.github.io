#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e4 + 10, M = 2e4 + 10;

int n, m, k;
int h[N], e[M], ne[M], a[M], idx;
bool st[N];

void add(int u, int v, int w) {
	e[idx] = v;
	ne[idx] = h[u];
	a[idx] = w;
	h[u] = idx ++ ;
}

int main() {
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	memset(h, -1, sizeof h);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i ++ ) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	queue<PII> q;
	q.push({1, 0});
	bool flag = false;
	while (!q.empty()) {
		PII t = q.front(); q.pop();
		if (t.first == n && t.second % k == 0) {
			cout << t.second << endl;
			flag = true;
			break;
		}
		for (int i = h[t.first]; ~i; i = ne[i]) {
			int j = e[i];
			if (t.second > a[i] || st[j]) continue;
			q.emplace(j, t.second + 1);
			//st[j] = true;
		}
	}
	if (!flag) cout << -1 << endl;
	return 0;
}

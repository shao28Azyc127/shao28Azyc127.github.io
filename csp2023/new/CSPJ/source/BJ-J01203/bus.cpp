#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
const int N = 2e4 + 10, M = N * 2;
int n, m, k;
int h[N], e[M], w[M], ne[M], idx;
PII f[N][110];

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

bool zhuan(int a, int b, int c) {
	bool flag = false;
	for (int i = 0; i < k; i ++ ) {
		LL t = 1ll * k * f[a][i].x + i;
		if (!f[a][i].y) continue;
		if (c > t) t += 1ll * (c - t + k - 1) / k * k;
		int v = t / k, j = (i + 1) % k;
		if (j == 0) v ++;
		if (!f[b][j].y || v < f[b][j].x) {
			f[b][j].y = 1;
			f[b][j].x = v, flag = true;
		}
	}
	return flag;
}

int main() {
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	memset(h, -1, sizeof h);
	while (m -- ) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	f[1][0].x = 1, f[1][0].y = 1;
	queue<int> q;
	q.push(1);
	while (q.size()) {
		int t = q.front(); q.pop();
		for (int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];
			if (zhuan(t, j, w[i])) q.push(j);
		}
	}
	if (!f[n][0].y) puts("-1");
	else cout << 1ll * f[n][0].x * k << endl;
	return 0;
}

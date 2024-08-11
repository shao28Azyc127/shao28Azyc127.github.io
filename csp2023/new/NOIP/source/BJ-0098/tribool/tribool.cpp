#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <numeric>
#include <algorithm>
#define int long long
using namespace std;
int C, T, n, m, x, y, a[100005], b[100005], color[100005], _count, _sum;
bool flag;
char op;
vector<pair<int, bool> > g[100005];
inline int myxor(int a, int b) {
	if (b == 0) {
		return a;
	}
	if (a == 0) {
		return 1;
	} else if (a == 1) {
		return 0;
	} else {
		return 2;
	}
}
void dfs(int current) {
	_count ++;
	for (int i = 0; i < g[current].size(); i ++) {
		int nx = g[current][i].first;
		bool nw = g[current][i].second;
		if (color[nx] != -1) {
			if (color[nx] != myxor(color[current], nw)) {
				flag = true;
			}
			continue;
		}
		color[nx] = myxor(color[current], nw);
		dfs(nx);
	}
}
signed main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	scanf("%lld%lld", &C, &T);
	while (T --) {
		scanf("%lld%lld", &n, &m);
		memset(a, 0, sizeof(a));
		iota(b + 1, b + n + 1, 1);
		for (int i = 1; i <= m; i ++) {
			cin >> op;
			if (op == 'T' || op == 'F' || op == 'U') {
				scanf("%lld", &x);
				a[x] = 2;
				if (op == 'T') {
					b[x] = 1;
				} else if (op == 'F') {
					b[x] = 0;
				} else {
					b[x] = 2;
				}
			} else {
				scanf("%lld%lld", &x, &y);
				if (op == '+') {
					a[x] = a[y];
					b[x] = b[y];
				} else {
					if (a[y] == 2) {
						a[x] = 2;
						b[x] = myxor(b[y], 1);
					} else {
						a[x] = ! a[y];
						b[x] = b[y];
					}
				}
			}
		}
		for (int i = 1; i <= n; i ++) {
			g[i].clear();
		}
		for (int i = 1; i <= n; i ++) {
			if (a[i] != 2) {
				g[b[i]].emplace_back(i, a[i]);
				g[i].emplace_back(b[i], a[i]);
			}
		}
		memset(color, -1, sizeof(color));
		_sum = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] == 2) {
				color[i] = b[i];
				_count = 0;
				dfs(i);
				if (b[i] == 2) {
					_sum += _count;
				}
			}
		}
		for (int i = 1; i <= n; i ++) {
			if (color[i] == -1) {
				color[i] = 0;
				flag = false;
				_count = 0;
				dfs(i);
				if (flag) {
					_sum += _count;
				}
			}
		}
		printf("%lld\n", _sum);
	}
	return 0;
}

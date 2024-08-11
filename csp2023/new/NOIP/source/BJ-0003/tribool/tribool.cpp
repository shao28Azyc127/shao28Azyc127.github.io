#include <bits/stdc++.h>
using namespace std;
int a[500005], fa[500005], siz[500005];
bool b[500005];
inline int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void join(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) return;
	fa[fx] = fy;
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int C, T;
	cin >> C >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) a[i] = i, b[i] = false;
		for (int i = 1; i <= m; i++) {
			char opt;
			int x, y;
			cin >> opt >> x;
			if (opt == '+') {
				cin >> y;
				a[x] = a[y];
				b[x] = b[y];
			}
			else if (opt == '-') {
				cin >> y;
				a[x] = a[y];
				b[x] = b[y] ^ 1;
			}
			else if (opt == 'T') a[x] = n + 1, b[x] = false;
			else if (opt == 'F') a[x] = n + 2, b[x] = false;
			else a[x] = n + 3, b[x] = false;
		}
		for (int i = 1; i <= n + n + 6; i++) fa[i] = i;
		for (int i = 1; i <= n; i++) {
			// cout << i << ' ' << b[i] << ' ' << a[i] << '\n';
			if (b[i]) {
				join(i + n + 3, a[i]);
				join(i, a[i] + n + 3);
			}
			else {
				join(i, a[i]);
				join(i + n + 3, a[i] + n + 3);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (find(i) == find(n + 3) || find(i) == find(n + n + 6) || find(i) == find(i + n + 3)) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
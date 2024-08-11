#include <bits/stdc++.h>
using namespace std;
#define int __int128
inline int read() {
	int cnt = 0, f = 1;
	char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') {
		f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		cnt = (cnt << 1) + (cnt << 3) + (c ^ 48);
		c = getchar();
	}
	return cnt * f;
}
inline void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) {
		putchar(x ^ 48);
		return;
	}
	write(x / 10);
	putchar(x % 10 ^ 48);
}
int zhangrongjian = 1;
int a[100005], b[100005], c[100005], d[100005], t[100005];
vector<int> v[100005];
int n;
void dfs(int x, int f) {
	for (int i = 0; i < v[x].size(); i++) {
		if (v[x][i] != f) {
			dfs(v[x][i], x);
			t[x] = min(t[x], t[v[x][i]] - 1);
		}
	}
}
int get(int x, int T) {
	return max(b[x] + c[x] * T, zhangrongjian);
}
int calc(int x, int tt, int T) {
	if (d[x] >= T) {
		return (tt + T) * (T - tt + 1) / 2 * c[x] + (T - tt + 1) * b[x];
		// return (get(x, tt) + get(x, T)) * (T - tt + 1) / 2;
	}
	else if (d[x] < tt) {
		return T - tt + 1;
	}
	else {
		return calc(x, tt, d[x]) + calc(x, d[x] + 1, T);
		// return (get(x, tt) + get(x, d[x]) * (d[x] - tt + 1)) / 2 + T - d[x];
	}
}
bool check(int x) {
	for (int i = 1; i <= n; i++) {
		int l = 1, r = x, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			int y = calc(i, mid, x);
			// cout << x << ' ' << i << ' ' << mid << ' ' << x << ' ' << y << '\n';
			if (calc(i, mid, x) >= a[i]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		// cout << x << ' ' << i << ' ' << ans << '\n';
		if (ans == -1) return false;
		t[i] = ans;
	}
	dfs(1, 0);
	sort(t + 1, t + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (i > t[i]) return false;
	}
	return true;
}
signed main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read(), b[i] = read(), c[i] = read();
		if (c[i] < 0) d[i] = (b[i] - 1) / -c[i];
		else d[i] = 1e9+1;
	}
	for (int i = 1; i < n; i++) {
		int x = read(), y = read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int l = 1, r = 1e9, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	write(ans); putchar('\n');
	return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5;
int n, m;

char lastass[maxn];
void solve3() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) lastass[i] = 'T';
	for (int i = 1; i <= m; ++i) {
		char now; int ind; cin >> now >> ind;
		lastass[ind] = now;
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) cnt += (lastass[i] == 'U');
	cout << cnt << endl;
}
char op[maxn], a[maxn], run[maxn]; int x[maxn], y[maxn], ans = 1e9;
bool check() {
	for (int i = 1; i <= n; ++i) run[i] = a[i];
	for (int i = 1; i <= m; ++i) {
		if (op[i] == '+') {
			run[x[i]] = run[y[i]];
		} else if (op[i] == '-') {
			if (run[y[i]] == 'T') run[x[i]] = 'F';
			else if (run[y[i]] == 'F') run[x[i]] = 'T';
			else if (run[y[i]] == 'U') run[x[i]] = 'U';
		} 
		else if (op[i] == 'T') run[x[i]] = 'T';
		else if (op[i] == 'F') run[x[i]] = 'F';
		else if (op[i] == 'U') run[x[i]] = 'U';
	}
	for (int i = 1; i <= n; ++i) {
		if (run[i] != a[i]) return false;
	}
	return true;
}
inline void dfs(int dep) {
	if (dep == n + 1) {
		if (check()) {
			int cnt = 0;
			for (int i = 1; i <= n; ++i) cnt += (a[i] == 'U');
			ans = min(ans, cnt);
		}
		return ;
	}
	a[dep] = 'T';
	dfs(dep + 1);
	a[dep] = 'F';
	dfs(dep + 1);
	a[dep] = 'U';
	dfs(dep + 1);
}
void solve1() {
	ans = 1e9;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) a[i] = 0;
	for (int i = 1; i <= m; ++i) {
		cin >> op[i];
		if (op[i] == '+' || op[i] == '-') cin >> x[i] >> y[i];
		else cin >> x[i];
	}
	dfs(1);
	cout << ans << endl;
}
signed main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int c, t; cin >> c >> t;
	while (t--) {
		if (c == 3 || c == 4) {
			solve3();
		} else if (c == 1 || c == 2) {
			solve1();
		}
	}
	return 0;
}
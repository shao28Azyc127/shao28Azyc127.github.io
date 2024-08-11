#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
const ll inf = 1e18;

int n;
ll a[N], b[N], c[N];
ll k[N];
vector<int> e[N];

inline ll calc(int i, int l, int r) {
	if (c[i] >= 0) {
		__int128 t = (__int128)(b[i] + c[i] * l + b[i] + c[i] * r) * (r - l + 1) / 2;
		if (t < inf) return t;
		else return inf;
	} else {
		if (k[i] <= l) return r - l + 1;
		else if (k[i] <= r) return (b[i] + c[i] * l + b[i] + c[i] * (k[i] - 1)) * (k[i] - l) / 2 + (r - k[i] + 1);
		else return (b[i] + c[i] * l + b[i] + c[i] * r) * (r - l + 1) / 2;
	}
}

int s[N];
int cnt[N], mn[N];
void dfs(int u, int p) {
	mn[u] = s[u];
	for (auto &v: e[u]) if (v != p) {
		dfs(v, u);
		mn[u] = min(mn[u], mn[v]);
	}
	if (u != p && mn[u] <= n) ++cnt[mn[u]];
}

bool check(int x) {
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = x; s[i] = 0;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (calc(i, mid, x) >= a[i]) s[i] = mid, l = mid + 1;
			else r = mid - 1;
		}
		if (!s[i]) return false;
	}
	memset(cnt, 0, sizeof cnt); cnt[1] = 1;
	dfs(1, 1);
	for (int i = 1; i <= n; ++i) {
		cnt[i] += cnt[i - 1];
		if (cnt[i] > i) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
		if (c[i] < 0) k[i] = (b[i] - c[i] - 1) / (-c[i]);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}	
	
	int l = n, r = 1e9, ans;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	
	cout << ans << endl;
	
	return 0;
}
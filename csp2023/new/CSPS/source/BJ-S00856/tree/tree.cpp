#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
const int N = 1e5 + 10, M = N * 2;
int n;
LL a[N], b[N], c[N];
int h[N], e[M], ne[M], idx, p[N];
LL f[2000000];
bool st[N];

void add(int u, int v) {
	e[idx] = v, ne[idx] = h[u], h[u] = idx ++;
}

bool check(LL now, int i, LL len) {
	LL ed = now + len - 1;
	if (c[i] >= 0) {
		__int128 st = b[i] + (__int128)now * c[i], ls = b[i] + (__int128)ed * c[i];
		if ((ls + st) * len / 2 >= a[i]) return true;
		else return false;
	}
	else {
		LL ti = b[i] / abs(c[i]) + !(!(b[i] % abs(c[i])));
		ti = max(ti, now);
		long long ans = ed - ti + 1, x = ti - now;
		if (ti > now) {
			long long st = b[i] + 1ll * now * c[i], lst = b[i] + 1ll * (ti - 1) * c[i];
			if ((lst + st) * x / 2 >= a[i] - ans) return true;
			return false;
		}
		if (ans >= a[i]) return true;
		return false;
	}
}

bool chk() {
	for (int i = 1; i <= n; i ++ )
		if (c[i]) return false;
	return true;
}

LL get_time(LL now, int pos) {
	LL l = 1, r = 1e18;
	while (l < r) {
		LL mid = l + r >> 1;
		if (check(now, pos, mid)) r = mid;
		else l = mid + 1;
	}
	return now + l - 1;
}

void dfs(int u, int fa) {
	p[u] = fa;
	for (int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		if (j == fa) continue;
		dfs(j, u);
	}
}

int main() {
	freopen("tree.in", "r", stdin);
freopen("tree.out", "w", stdout);
	memset(h, -1, sizeof h);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
	for (int i = 1; i < n; i ++ ) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	if (chk()) {
		priority_queue<PII> q;
		q.push(make_pair((a[1] + b[1] - 1) / b[1], 1ll));
		st[1] = true;
		LL ans = 0, cnt = 0;
		while (q.size()) {
			PII t = q.top(); q.pop();
			LL u = t.second;
			cnt ++;
			ans = max(ans, cnt + t.first - 1);
			for (int i = h[u]; ~i; i = ne[i]) {
				int j = e[i];
				if (st[j]) continue;
				q.push(make_pair((a[j] + b[j] - 1) / b[j], (LL)j));
			}
		}
		cout << ans << endl;
	}
	else if (n <= 20) {
		memset(f, 0x3f, sizeof f);
		f[1] = get_time(1, 1);
		dfs(1, 0);
		p[1] = 114514;
		for (int i = 2; i < (1 << n); i ++ ) {
			if ((i & 1) == 0) continue;
			for (int j = 0; j < n; j ++ ) 
				if (i >> (j - 1) & 1 && i >> (p[j - 1] - 1) & 1) st[p[j - 1] - 1] = true;
			int cnt = 0;
			for (int j = 0; j < n; j ++ ) cnt += (i >> j & 1);
			for (int j = 1; j < n; j ++ )
				if (i >> j & 1 && !st[j]) {
					f[i] = min(f[i], max(f[i - (1 << j) ], get_time(cnt, j + 1)));
				}
			for (int j = 0; j < n; j ++ ) st[j] = false;
		}
		cout << f[(1 << n) - 1] << endl;
		return 0;
	}
	else {
		LL ans = 0, now = 0;
		for (int i = 1; i <= n; i ++ ) {
			now ++;
			ans = max(ans, get_time(now, i));
		}
		cout << ans << endl;
	}
	return 0;
}

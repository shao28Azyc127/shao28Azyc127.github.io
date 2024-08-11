#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
ll a[N], b[N], c[N];
int cnt, head[N];
struct edge {
	int v, next;
} e[N << 1];
void add(int u, int v) {
	e[++cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}
int n, f[N];
void dfs(int p) {
	for (int i = head[p]; i; i = e[i].next) {
		int v = e[i].v;
		if (v != f[p]) {
			f[v] = p;
			dfs(v);
		}
	}
}
struct node {
	int id, lim;
} ar[N];
bool cmp(node a, node b) {
	return a.lim < b.lim;
}
bool vis[N];
inline ll gs(ll a, ll b) {
	return (a + b) * (b - a + 1) / 2;
}
int res;
inline ll calc(ll x, ll b, ll c) {
	if (c >= 0)
		return (res - x + 1) * b + gs(x, res) * c;
	else {
		int d = (1 - b) / c + 1;
		if (d > res)
			d = res + 1;
		//cerr << res << ' ' << x << ' ' << b << ' ' << c << ' ' << d << '\n';
		return (d > x ? (d - x) * b + gs(x, d - 1) * c : 0) + (d <= res ? (res - d + 1) : 0);
	}
}
int bs2(int l, int r, ll a, ll b, ll c) {
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (calc(mid, b, c) >= a)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return r;
}
bool check() {
	for (int i = 1; i <= n; i++) {
		ar[i].id = i;
		ar[i].lim = bs2(1, res, a[i], b[i], c[i]);
		//*********************
		ll now = 0;
		for (int j = ar[i].lim; j <= res; j++)
			now += max(b[i] + c[i] * j, 1ll);
		//cerr << res << ' ' << i << ' ' << ar[i].lim << ' ' << a[i] << ' ' << now << ' ' << b[i] << ' ' << c[i] << "!\n";
	}
	memset(vis, 0, sizeof(vis));
	sort(ar + 1, ar + n + 1, cmp);
	int t = 0;
	for (int i = 1; i <= n; i++) {
		int p = ar[i].id;
		while (p && !vis[p]) {
			vis[p] = 1;
			p = f[p];
			++t;
		}
		if (t > ar[i].lim)
			return 0;
	}
	return 1;
}
int bs(int l, int r) {
	while (l <= r) {
		res = (l + r) >> 1;
		if (check())
			r = res - 1;
		else
			l = res + 1;
	}
	return l;
}
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
	}
	bool f = 0;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
		//if (u == i)
	}
	dfs(1);
	printf("%d\n", bs(0, 1e9));
	return 0;
}
//还没醒来，还在期待命运能温柔摊牌。还没醒来，那个藏在赌局背后的小孩。

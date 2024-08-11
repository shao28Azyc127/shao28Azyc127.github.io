#include <bits/stdc++.h>
using namespace std;
int n, m, nn, mm;
int a[500005], b[500005], aa[500005], bb[500005];
int maxn[2000005], minn[2000005];
void update(int x) {
	maxn[x] = max(maxn[(x << 1)], maxn[(x << 1) | 1]);
	minn[x] = min(minn[(x << 1)], minn[(x << 1) | 1]);
}
void build(int x, int l, int r) {
	int mid = (l + r) / 2;
	if (l == r) {
		maxn[x] = minn[x] = b[l];
		return;
	}
	build((x << 1), l, mid);
	build((x << 1) | 1, mid + 1, r);
	update(x);
}
int queryr(int x, int l, int r, int q, int v) {
	// cout << x << ' ' << l << ' ' << r << ' ' << q << ' ' << v << ' ' << maxn[x] << '\n';
	int mid = (l + r) / 2;
	if (l == r) {
		if (maxn[x] < v) return l;
		return l - 1;
	}
	if (q > mid) return queryr((x << 1) | 1, mid + 1, r, q, v);
	if (q <= l && maxn[x] < v) return r;
	int num = queryr((x << 1), l, mid, q, v);
	if (num == mid) return queryr((x << 1) | 1, mid + 1, r, q, v);
	else return num;
}
int queryl(int x, int l, int r, int q, int v) {
	// cout << x << ' ' << l << ' ' << r << ' ' << q << ' ' << v << '\n';
	int mid = (l + r) / 2;
	if (l == r) {
		if (minn[x] >= v) return l;
		return l + 1;
	}
	if (q <= mid) return queryl((x << 1), l, mid, q, v);
	if (q >= r && minn[x] >= v) return l;
	int num = queryl((x << 1) | 1, mid + 1, r, q, v);
	if (num == mid + 1) return queryl((x << 1), l, mid, q, v);
	else return num;
}
bool solve() {
	if (a[1] == b[1]) return false;
	if (a[1] < b[1]) swap(a, b), swap(n, m);
	build(1, 1, m);
	int j = 0;
	for (int i = 1; i <= n; i++) {
		// cout << i << ' ' << j << ' ' << a[i] << '\n';
		if (a[i] > b[j]) {
			j = queryr(1, 1, m, j, a[i]);
		}
		else {
			j = queryl(1, 1, m, j, a[i]) - 1;
		}
		if (j == 0) return false;
	}
	if (j == m) return true;
	return false;
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int C, Q;
	cin >> C >> n >> m >> Q;
	nn = n; mm = m;
	for (int i = 1; i <= n; i++) {cin >> a[i]; aa[i] = a[i];}
	for (int i = 1; i <= m; i++) {cin >> b[i]; bb[i] = b[i];}
	if (solve()) putchar('1');
	else putchar('0');
	while (Q--) {
		n = nn; m = mm;
		for (int i = 1; i <= n; i++) a[i] = aa[i];
		for (int i = 1; i <= m; i++) b[i] = bb[i];
		int k0, k1;
		cin >> k0 >> k1;
		for (int i = 1; i <= k0; i++) {
			int x, y;
			cin >> x >> y;
			a[x] = y;
		}
		for (int i = 1; i <= k1; i++) {
			int x, y;
			cin >> x >> y;
			b[x] = y;
		}
		if (solve()) putchar('1');
		else putchar('0');
	}
	putchar('\n');
	return 0;
}
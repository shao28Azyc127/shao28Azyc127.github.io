#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N * 10], fa[N * 10], sz[N * 10], lst[N], an[N * 10];

int find(int x) {
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

void solve() {
	scanf("%d%d", &n, &m);
	memset(an, 0, sizeof an);
	memset(sz, 0, sizeof sz);
	for (int i = 1; i <= n * 2 + m * 2 + 3; i ++ ) p[i] = fa[i] = i;
	for (int i = 1; i <= n; i ++ ) lst[i] = (i - 1) * 2 + 1;
	int start_cnt = n * 2 + 4;
	for (int i = 1; i <= m; i ++ ) {
		char c; int x, y;
		cin >> c;
		if (c == 'U' || c == 'T' || c == 'F') {
			scanf("%d", &x);
			int he1 = start_cnt; start_cnt ++;
			int he2 = start_cnt; start_cnt ++;
			if (c == 'U') p[he1] = n + 1, p[he2] = n + 1;
			else if (c == 'T') p[he1] = n + 2, p[he2] = n + 3;
			else p[he1] = n + 3, p[he2] = n + 2;
			lst[x] = he1;
		}
		else {
			int he1 = start_cnt; start_cnt ++;
			int he2 = start_cnt; start_cnt ++;
			scanf("%d%d", &x, &y);
			an[lst[x]] = he1, an[lst[x] + 1] = he2;	
			if (c == '-') p[he1] = p[lst[y] + 1], p[he2] = p[lst[y]];
			else p[he1] = p[lst[y]], p[he2] = p[lst[y] + 1];
			lst[x] = he1;
		}
	}
	for (int i = 1; i <= n; i ++ ) sz[lst[i]] = sz[lst[i] + 1] = 1;
	for (int i = 1; i <= n; i ++ ) {
		int x = lst[i], y = p[lst[i]];
		int a = find(x), b = find(y);
		if (a != b) {
			sz[a] += sz[b];
			fa[b] = a;
		}
		x = lst[i] + 1, y = p[x];
		a = find(x), b = find(y);
		if (a != b) {
			sz[a] += sz[b];
			fa[b] = a;
		}
	}
	for (int i = 1; i < start_cnt; i ++ ) {
		if (!an[i]) continue;
		int x = i, y = an[i];
		int a = find(x), b = find(y);
		if (a != b) {
			sz[a] += sz[b];
			fa[b] = a;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++ ) {
		int fa1 = find(lst[i]), fa2 = find(lst[i] + 1);
		if (fa1 == fa2) {
			ans ++;
		}
	}
	cout << ans << endl;
	return;
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t -- ) solve();
	return 0;
}

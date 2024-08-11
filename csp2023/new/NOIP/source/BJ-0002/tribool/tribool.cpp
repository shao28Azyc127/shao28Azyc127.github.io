#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 jiajia
struct node {
	bool op;
	int id; bool yy;
	int tq;
} a[100005];
int fa[200005], siz[200005];
bool bj[200005];
int fnd(int x) {if (fa[x] == x) return x; return fa[x] = fnd(fa[x]);}
void merge(int x, int y) {
	x = fnd(x); y = fnd(y);
	if (x == y) return;
	fa[x] = y;
	siz[y] += siz[x];
}
int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int c, t; cin >> c >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n + n; i++) fa[i] = i, siz[i] = 1, bj[i] = 0;
		for (int i = 1; i <= n; i++) {
			a[i].op = 0; a[i].id = i; a[i].yy = 0; a[i].tq = 0;
		}
		for (int i = 1; i <= m; i++) {
			char v; cin >> v;
			int x, y;
			if (v == 'T') {
				cin >> x;
				a[x].op = 1; a[x].tq = 1;
			} else if (v == 'F') {
				cin >> x;
				a[x].op = 1; a[x].tq = 0;
			} else if (v == 'U') {
				cin >> x;
				a[x].op = 1; a[x].tq = 2;
			} else if (v == '+') {
				cin >> x >> y;
				if (a[y].op == 1) {
					a[x].op = 1;
					a[x].tq = a[y].tq;
				} else {
					a[x].op = 0;
					a[x].id = a[y].id;
					a[x].yy = a[y].yy;
				}
			} else {
				cin >> x >> y;
				if (a[y].op == 1) {
					a[x].op = 1;
					if (a[y].tq == 2) a[x].tq = 2;
					else a[x].tq = 1 - a[y].tq;
				} else {
					a[x].op = 0;
					a[x].id = a[y].id;
					a[x].yy = !a[y].yy;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i].op == 0) {
				if (a[i].yy == 1) {
					merge(i, a[i].id + n);
					merge(i + n, a[i].id);
				} else {
					merge(i, a[i].id);
					merge(i + n, a[i].id + n);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (fnd(i) == fnd(i + n)) bj[fnd(i)] = 1;
			if (a[i].op == 1 && a[i].tq == 2) {
				bj[fnd(i)] = 1;
				bj[fnd(i + n)] = 1;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n + n; i++) if (bj[i]) ans += siz[i];
		cout << ans / 2 << '\n';
	}
	return 0;
}
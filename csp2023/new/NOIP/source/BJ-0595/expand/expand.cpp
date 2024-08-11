#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5e5 + 10;

int X [Maxn], Y [Maxn];
int xx[Maxn], yy[Maxn];
int ccc, n, m, q;

bool work (int tx, int ty) {
	if (X[tx] <= Y[ty])
		return false;
	if (tx == n && ty == m)
		return true;
	bool ans = false;
	if (tx + 1 <= n)
		ans |= work (tx + 1, ty);
	if (ty + 1 <= m)
		ans |= work (tx, ty + 1);
	if (tx + 1 <= n && ty + 1 <= m)
		ans |= work (tx + 1, ty + 1);
	return ans;
}

int main () {
	freopen ("expand.in", "r", stdin);
	freopen ("expand.out", "w", stdout);
	scanf ("%d %d %d %d", &ccc, &n, &m, &q);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &X[i]), xx[i] = X[i];
	for (int i = 1; i <= m; i ++)
		scanf("%d", &Y[i]), yy[i] = Y[i];
	for (int tt = 0; tt <= q; tt ++) {
		if (tt) {
			for (int i = 1; i <= n; i ++)
				X[i] = xx[i];
			for (int i = 1; i <= m; i ++)
				Y[i] = yy[i];
			int kx, ky;
			scanf("%d %d", &kx, &ky);
			for (int i = 1; i <= kx; i ++) {
				int p, u;
				scanf("%d %d", &p, &u);
				X[p] = u;
			}
			for (int i = 1; i <= ky; i ++) {
				int p, u;
				scanf("%d %d", &p, &u);
				Y[p] = u;
			}
		}
		if (X[1] < Y[1]) {
			swap(X, Y);
			swap(n, m);
		}
		if (X[1] <= Y[1] || X[n] <= Y[m]) {
			printf ("0");
			continue;
		}
		cout <<work(1, 1);
	}
	return 0;
}


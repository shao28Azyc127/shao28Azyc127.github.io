#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 500010;
int c, n, m, q, f[MAXN], g[MAXN];
int f_[MAXN], g_[MAXN];
int f1, fn, g1, gm;
int supf = -1, inff = 2e9, supg = -1, infg = 2e9;
int c1, c2, c3, c4;
void rollback() {
	memcpy(f, f_, sizeof f);
	memcpy(g, g_, sizeof g);
}
void init() {
	supf = -1, inff = 2e9, supg = -1, infg = 2e9;
	for (int i = 1; i <= n; i++) {
		supf = max(supf, f[i]);
		inff = min(inff, f[i]);
	}
	for (int i = 1; i <= m; i++) {
		supg = max(supg, g[i]);
		infg = min(infg, g[i]);
	}
}
bool check() {
//	cout << supf << " " << inff << " " << supg << " " << infg << endl;
	if (f[1] < g[1] && f[n] < g[m]) {
		return (supf < supg) && (inff < infg);
	} else if (f[1] > g[1] && f[n] > g[m]) {
		return (inff > infg) && (supf > supg);
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin >> c >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> g[i];
	}
	memcpy(f_, f, sizeof f_);
	memcpy(g_, g, sizeof g_);
	init();
	cout << check();
	for (int i = 1; i <= q; i++) {
		rollback();
		int kx, ky, p, v;
		cin >> kx >> ky;
		for (int j = 1; j <= kx; j++) {
			cin >> p >> v;
			f[p] = v;
		}
		for (int j = 1; j <= ky; j++) {
			cin >> p >> v;
			g[p] = v;
		}
		init();
		cout << check();
	}
	cout << endl;
	return 0;
}
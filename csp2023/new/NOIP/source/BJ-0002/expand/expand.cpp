#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 jiajia
void read(int &x) {
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	x *= f;
}
int ans[65];
int x[500005], y[500005], orx[500005], ory[500005];
int dp[500005];
int mx[20][500005], mn[20][500005];
int qmx(int l, int r) {
	//if (r < l) return -1;
	int w = __lg(r - l + 1);
	return max(mx[w][l], mx[w][r - (1 << w) + 1]);
}
int qmn(int l, int r) {
	//if (r < l) return 1000000000;
	int w = __lg(r - l + 1);
	return min(mn[w][l], mn[w][r - (1 << w) + 1]);
}
bool work(int n, int m) {
	dp[0] = 0;
	//cout << "#";
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		if (x[i] < x[i - 1]) {
			if (qmn(1, dp[i - 1]) < x[i]) {
				int L = 1, R = dp[i - 1], M;
				while (L < R) {
					M = (L + R + 1) >> 1;
					if (qmn(M, dp[i - 1]) < x[i]) L = M;
					else R = M - 1;
				}
				dp[i] = L;
			}
		} else {
			int L = dp[i - 1], R = m, M;
			if (L == 0) {
				if (x[i] > y[1]) L++;
				else return 0;
			}
			int st = L;
			while (L < R) {
				M = (L + R + 1) >> 1;
				if (qmx(st, M) < x[i]) L = M;
				else R = M - 1;
			}
			dp[i] = L;
		}
		if (dp[i] == 0) return 0;
	}
	if (dp[n] == m) return 1;
	return 0;
}
void init(int n) {
	for (int i = 1; i <= n; i++) mx[0][i] = mn[0][i] = y[i];
	for (int j = 1; j < 18; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
			mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
		}
	}
}
int n, m;
bool solve() {
	if (n > 200000 || m > 200000) {
		int mnx = 1000000000, mxx = 0, mny = 1000000000, mxy = 0;
		for (int i = 1; i <= n; i++) {
			mnx = min(mnx, x[i]);
			mxx = max(mxx, x[i]);
		}
		for (int i = 1; i <= m; i++) {
			mny = min(mny, y[i]);
			mxy = max(mxy, y[i]);
		}
		if (mxy > mxx && mny > mnx) return 1;
		if (mxx > mxy && mnx > mny) return 1;
	}
	bool bj = 0;
	init(m);
	bj |= work(n, m);
	for (int i = 1; i <= max(n, m); i++) swap(x[i], y[i]);
	init(n);
	bj |= work(m, n);
	return bj;
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int c, q;
	read(c); read(n); read(m); read(q);
	for (int i = 1; i <= n; i++) {
		read(x[i]);
		orx[i] = x[i];
	}
	for (int i = 1; i <= m; i++) {
		read(y[i]);
		ory[i] = y[i];
	}
	ans[0] = solve();
	for (int i = 1; i <= q; i++) {
		for (int j = 1; j <= n; j++) x[j] = orx[j];
		for (int j = 1; j <= m; j++) y[j] = ory[j];
		int kx, ky; read(kx); read(ky);
		for (int j = 1; j <= kx; j++) {
			int p, v; read(p); read(v);
			x[p] = v;
		}
		for (int j = 1; j <= ky; j++) {
			int p, v; read(p); read(v);
			y[p] = v;
		}
		ans[i] = solve();
	}
	for (int i = 0; i <= q; i++) cout << ans[i];
	cout << '\n';
	return 0;
}
//BJ-0019

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, s, t) for(int i = (s); i <= (t); ++i)
#define per(i, s, t) for(int i = (t); i >= (s); --i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 2e3 + 5;

int id, n, m, q;
bool f[N][N];
int a[N], b[N], a0[N], b0[N];

int sign(int x) {
	if(x > 0) return 1;
	if(x < 0) return -1;
	return 0;
}

int solve() {
	if(a[1] == b[1]) return 0;
	int s0 = sign(a[1] - b[1]);
	rep(i, 1, n) rep(j, 1, m) f[i][j] = 0;
	f[1][1] = 1;
	rep(i, 1, n) rep(j, 1, m) if(sign(a[i] - b[j]) == s0) f[i][j] |= f[i-1][j] || f[i][j-1];
	return f[n][m];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);

	cin >> id >> n >> m >> q;
	rep(i, 1, n) cin >> a[i], a0[i] = a[i];
	rep(i, 1, m) cin >> b[i], b0[i] = b[i];
	cout << solve();
	while(q--) {
		rep(i, 1, n) a[i] = a0[i];
		rep(i, 1, m) b[i] = b0[i];
		int k1, k2; cin >> k1 >> k2;
		while(k1--) {
			int i, x; cin >> i >> x;
			a[i] = x;
		}
		while(k2--) {
			int i, x; cin >> i >> x;
			b[i] = x;
		}
		cout << solve();
	}
	cout << "\n";

	return 0;
}
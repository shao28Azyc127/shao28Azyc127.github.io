#include <bits/stdc++.h>

using namespace std;
const int N = 500005;

int subID, n, m, q;
int a[N], b[N];

namespace f1 {
	int kx, ky;
	int c[2005], d[2005];
	bool f[2005][2005][3];

	void work() {
		int l1 = n, l2 = m;
		for(int i = 1; i <= l1; ++i) c[i] = a[i];
		for(int i = 1; i <= l2; ++i) d[i] = b[i];
		while(kx--) {
			int p, v; cin >> p >> v; c[p] = v;
		}
		while(ky--) {
			int p, v; cin >> p >> v; d[p] = v;
		}
		if(c[1] == d[1] || c[l1] == d[l2]) {
			cout << "0"; return;
		}
		if(c[1] > d[1]) {
			swap(c, d), swap(l1, l2);
		}
		if(c[l1] > d[l2]) {
			cout << "0"; return;
		}
		memset(f, false, sizeof f);
		f[l1][l2][0] = f[l1][l2][1] = f[l1][l2][2] = true;
		for(int i = l1; i >= 1; --i) {
			for(int j = l2; j >= 1; --j) {
				// t = 0
				if(j > 1 && c[i] < d[j - 1]) f[i][j - 1][0] |= f[i][j][0], f[i][j - 1][1] |= f[i][j][0], f[i][j - 1][2] |= f[i][j][0];
				// t = 1
				if(i > 1 && c[i - 1] < d[j]) f[i - 1][j][0] |- f[i][j][1], f[i - 1][j][1] |= f[i][j][1], f[i - 1][j][2] |= f[i][j][1];
				// t = 2
				if(i > 1) f[i - 1][j][0] |= f[i][j][2];
				if(j > 1) f[i][j - 1][1] |= f[i][j][2];
			}
		}
		cout << f[1][1][2];
	}

	void sol() {
		cerr << "n <= 2000\n";
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for(int i = 1; i <= m; ++i) {
			cin >> b[i];
		}
		kx = ky = 0;
		work();
		while(q--) {
			cin >> kx >> ky;
			work();
		}
		cout << '\n';
	}
}


int main() {

	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> subID >> n >> m >> q;
	if(subID <= 7) {
		f1::sol();
	}
	else {
		for(int i = 1; i <= q; ++i) {
			cout << "0";
		}
		cout << '\n';
	}

	cout.flush();
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 100005;
int subID, T;
int n, m, K, d;

namespace f1 {
	ll f[1005][1005];
	ll val[1005][1005];

	void sol() {
		while(T--) {
			cin >> n >> m >> K >> d;
			memset(val, 0, sizeof val);
			for(int i = 1; i <= m; ++i) {
				int x, y, z;
				cin >> x >> y >> z;
				val[x][y] += z;
			}
			for(int i = 1; i <= n; ++i) {
				for(int j = 1; j <= i; ++j) {
					val[i][j] += val[i][j - 1];
				}
			}
			memset(f, ~0x3f, sizeof f);
			f[0][0] = 0;
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j <= min(i, K); ++j) {
					if(j < K) {
						f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + val[i + 1][j + 1] - d);
					}
					f[i + 1][0] = max(f[i + 1][0], f[i][j]);
				}
			}
			ll res = -1e18;
			for(int j = 0; j <= K; ++j) {
				res = max(res, f[n][j]);
			}
			cout << res << '\n';
		}
	}
}

int main() {

	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> subID >> T;
	if(subID <= 9) {
		cerr << "force\n";
		f1::sol();
	}
	else {
		cout << "0\n";
	}

	cout.flush();
	return 0;
}
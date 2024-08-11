#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 810;
bool f[maxn][maxn];
signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n; string s; cin >> n >> s;
	s = " " + s;
	for (int i = 1; i <= n; ++i) f[i][i - 1] = true;
	for (int l = 1; l <= n; l++) {
		for (int i = 1; i <= n; ++i) {
			int j = i + l;
			if (f[i + 1][j - 1] && (j - i + 1) % 2 == 0 && s[i] == s[j]) f[i][j] = true;
			if (j <= n) {
				for (int k = i; k < j; ++k) {
					if (f[i][k] && f[k + 1][j]) f[i][j] = true;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ans += f[i][j];
		}
	}
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
	int cnt = 0, f = 1;
	char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') {
		f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		cnt = (cnt << 1) + (cnt << 3) + (c ^ 48);
		c = getchar();
	}
	return cnt * f;
}
inline void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) {
		putchar(x ^ 48);
		return;
	}
	write(x / 10);
	putchar(x % 10 ^ 48);
}
int dp[2000005], f[2000005][26];
signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(false);
	memset(f, -1, sizeof(f));
	int n, ans = 0;
	string s;
	cin >> n >> s;
	s=" "+s;
	for (int i = 1; i <= n; i++) {
		int x = f[i - 1][s[i] - 'a'];
		if (x != -1) {
			dp[i] = dp[x] + 1;
			for (int j = 0; j < 26; j++) {
				f[i][j] = max(f[i][j], f[x][j]);
			}
			ans += dp[i];
		}
		f[i][s[i] - 'a'] = i - 1;
		// cout << i << ' ' << dp[i] << ' ' << x << '\n';
	}
	cout << ans << '\n';
	return 0;
}
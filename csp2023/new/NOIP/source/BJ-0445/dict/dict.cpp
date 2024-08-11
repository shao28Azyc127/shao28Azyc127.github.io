#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3005;
string s[maxn], ordmx[maxn], ordmi[maxn];
int cnt[26];
signed main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		for (int j = 0; j < 26; ++j) cnt[j] = 0;
		for (int j = 0; j < m; ++j) {
			cnt[s[i][j] - 'a']++;
		}
		for (int j = 25; j >= 0; --j) {
			for (int k = 1; k <= cnt[j]; ++k) {
				ordmx[i] += j + 'a';
			}
		}
		for (int j = 0; j <= 25; ++j) {
			for (int k = 1; k <= cnt[j]; ++k) {
				ordmi[i] += j + 'a';
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		bool flag = true;
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			if (ordmi[i] >= ordmx[j]) {
				flag = false;
				break;
			}
		}
		cout << flag;
	}
	return 0;
}
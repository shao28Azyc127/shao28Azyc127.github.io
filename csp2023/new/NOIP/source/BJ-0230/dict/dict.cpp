#include <bits/stdc++.h>
using namespace std;
const int N = 3005, M = 3005;
string mins[N], maxs[N];
signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		mins[i] = s;
		sort(mins[i].begin(), mins[i].end());
		maxs[i] = mins[i];
		reverse(maxs[i].begin(), maxs[i].end());
	}
	for (int i = 1; i <= n; ++i) {
		bool flg = 1;
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			if (mins[i] > maxs[j]) { flg = 0; break; }
		}
		cout << flg;
	}
	cout << '\n';
	return 0;
}
// I LOVE NOIP
/*
PAY ATTENTION:
1. freopen
2. read every word carefully
3. solve the problem step by step
4. testing strategy
5. __int128 no sqrt
6. N and M
7. int, long long and __int128

TRUST YOURSELF, 1= IS TOO EASY FOR YOU
*/

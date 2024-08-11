#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 10;

int n;
string s;

int nxt[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	cin >> n >> s;
	
	for (int i = 0; i < n; ++i) {
		nxt[i] = -2;
		for (int j = i - 1; j >= 0; j = nxt[j]) {
			if (s[j] == s[i]) {
				nxt[i] = j - 1;
				break;
			}
		}
		if (nxt[i] != -2) f[i] = (~nxt[i] ? f[nxt[i]] + 1 : 1);
	}
	
	ll ans = 0;
	for (int i = 0; i < n; ++i) ans += f[i];
	
	cout << ans << endl;

	return 0;
}
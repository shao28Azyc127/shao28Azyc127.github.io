#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 10;

int n, m;
string w[N];
int mn[N], mx[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
		mn[i] = 1e9, mx[i] = 0;
		for (auto &c: w[i]) mn[i] = min(mn[i], (int)c), mx[i] = max(mx[i], (int)c);
		//cerr << mn[i] << " " << mx[i] << "\n";
	}
	
	for (int i = 1; i <= n; ++i) {
		int ans = 1;
		for (int j = 1; j <= n; ++j) if (i != j && mx[j] <= mn[i]) ans = 0;
		cout << ans;
	}
	cout << "\n";
	
	return 0;
}
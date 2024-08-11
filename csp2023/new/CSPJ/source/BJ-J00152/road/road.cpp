#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, a, ans = 0;
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		ans += x;
	}
	cin >> a;
	if (ans % m == 0) cout << (ans / m) * a;
	else cout << (ans / m + 1) * a;
	return 0;
}
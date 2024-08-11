#include <bits/stdc++.h>
using namespace std;
int n;
string a;
long long dp[2000010];
stack<int> s;
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> a;
	for (int i = 1; i < n; i++) {
		int j;
		s.push(a[i]);
		for (j = i - 1; j >= 0 && !s.empty(); j--) {
			if (s.top() == a[j]) {
				s.pop();
			} else {
				s.push(a[j]);
			}
		}
		if (!s.empty()) {
			dp[i] = 0;
			while (!s.empty()) s.pop();
		} else {
			dp[i] = 1 + dp[j];
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) ans += dp[i];
	printf("%lld\n", ans);
	return 0;
}

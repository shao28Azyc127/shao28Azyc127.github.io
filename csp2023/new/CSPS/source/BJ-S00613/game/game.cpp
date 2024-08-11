#include <bits/stdc++.h>
using namespace std;

int a;
string b;
int dp[2000005];
vector<int> dp1[2000005];

int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> a;
	cin >> b;
	long long ans = 0;
	dp[1] = 0;
	for (int i = 1; i < a; i++) {
		if (b[i] == b[i - 1]) {
			dp[i]++;
			dp1[i].push_back(i - 1);
			if (i - 2 > 0) {
				dp[i] += dp[i - 2];
				for (auto k : dp1[i - 2]) {
					dp1[i].push_back(k);
				}
			}
		}
		if (dp[i - 1]) {
			for (auto k : dp1[i - 1]) {
				if (k - 1 >= 0) {
					if (b[k - 1] == b[i]) {
						dp[i]++;
						dp1[i].push_back(k - 1);

						if (k - 2 >= 0) {
							dp[i] += dp[k - 2];
							for (auto k1 : dp1[k - 2]) {
								dp1[i].push_back(k1);
							}
						}
						
					}
				}
			}
		}
	}
	for (int i = 1; i < a; i++) {
		ans += dp[i];
	}
	cout << ans;
	return 0;
}
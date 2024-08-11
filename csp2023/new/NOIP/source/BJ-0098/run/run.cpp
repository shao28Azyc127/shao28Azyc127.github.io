#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int C, T, n, m, K, d, x, y, z, dp[1005][1005], _max, p;
vector<pair<int, int> > nums[1005];
signed main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	scanf("%lld%lld", &C, &T);
	while (T --) {
		scanf("%lld%lld%lld%lld", &n, &m, &K, &d);
		for (int i = 1; i <= n; i ++) {
			nums[i].clear();
		}
		for (int i = 1; i <= m; i ++) {
			scanf("%lld%lld%lld", &x, &y, &z);
			nums[x].emplace_back(y, z);
		}
		for (int i = 1; i <= n; i ++) {
			nums[i].emplace_back(0, 0);
			sort(nums[i].begin(), nums[i].end());
			for (int j = 1; j < nums[i].size(); j ++) {
				nums[i][j].second += nums[i][j - 1].second;
			}
		}
		memset(dp, ~0x3f, sizeof(dp));
		dp[0][0] = 0;
		_max = 0;
		for (int i = 1; i <= n; i ++) {
			dp[i][0] = _max;
			p = 0;
			for (int j = 1; j <= i && j <= K; j ++) {
				dp[i][j] = dp[i - 1][j - 1] - d;
				while (p + 1 < nums[i].size() && nums[i][p + 1].first <= j) {
					p ++;
				}
				dp[i][j] += nums[i][p].second;
				_max = max(_max, dp[i][j]);
			}
		}
		printf("%lld\n", _max);
	}
	return 0;
}

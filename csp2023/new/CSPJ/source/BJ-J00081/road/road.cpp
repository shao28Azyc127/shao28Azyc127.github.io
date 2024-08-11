#include <cstdio>
#include <algorithm>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n, d, v[100005], nums[100005], presum[100005], premin[100005];
inline int ceil_div(int a, int b) {
	if (a % b == 0) {
		return a / b;
	} else {
		return a / b + 1;
	}
}
pair<int, int> f(int current) {
	if (current == 1) {
		return pair<int, int>(0, 0);
	}
	pair<int, int> result = f(premin[current - 1]);
	int temp = ceil_div(max(presum[current] - presum[premin[current - 1]] - result.second, 0LL), d);
	return pair<int, int>(result.first + temp * nums[premin[current - 1]], result.second + (temp * d - (presum[current] - presum[premin[current - 1]])));
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld", &n, &d);
	for (int i = 1; i < n; i ++) {
		scanf("%lld", v + i);
		presum[i + 1] = presum[i] + v[i];
	}
	nums[0] = INF;
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", nums + i);
		if (nums[i] < nums[premin[i - 1]]) {
			premin[i] = i;
		} else {
			premin[i] = premin[i - 1];
		}
	}
	printf("%lld\n", f(n).first);
	return 0;
}

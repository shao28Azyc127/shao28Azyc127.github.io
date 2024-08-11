#include <cstdio>
#define int long long
using namespace std;
int n, nums[10][10], box[10], a, b, _count;
void dfs(int current) {
	if (current > 5) {
		for (int i = 1; i <= n; i ++) {
			a = b = 0;
			for (int j = 1; j <= 5; j ++) {
				if (nums[i][j] != box[j]) {
					if (! a) {
						a = j;
					} else if (! b) {
						b = j;
					} else {
						return;
					}
				}
			}
			if ((a && ! b) || ((a && b) && (a + 1 == b || b + 1 == a) && (nums[i][a] - box[a] + 10) % 10 == (nums[i][b] - box[b] + 10) % 10)) {
				continue;
			} else {
				return;
			}
		}
		_count ++;
		return;
	}
	for (int i = 0; i <= 9; i ++) {
		box[current] = i;
		dfs(current + 1);
	}
}
signed main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= 5; j ++) {
			scanf("%lld", nums[i] + j);
		}
	}
	dfs(1);
	printf("%lld\n", _count);
	return 0;
}

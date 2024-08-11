#include <bits/stdc++.h>
using namespace std;
int t, c;
int n, m, k, d;
int x[100005], y[100005], v[100005];
map<int, bool> mp; // hope it won't be mle
vector<int> head;
int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    // dear reader,
    // the 100pts solution must be O(tm) or O(t(m log m)).
    // so i chose tanxin
    // it may want to check my xianduanshu(FIX O(1), CHECK O(LOG N)),
    // but wo bu hui qwq
    scanf("%d%d", &c, &t);
    while (t--) {
		scanf("%d%d%d%d", &n, &m, &k, &d);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &x[i], &y[i], &v[i]);
			if (y[i] > k) continue;
			for (int j = x[i] - y[i] + 1; j <= x[i]; j++) {
				mp[j] = 1;
			}
			head.push_back(x[i] - y[i] + 1);
		}
		// i dont know how to solve some special situations
		// so these are wa-ed to some pts
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			int tmp = 0;
			for (int j = x[i] - y[i] + 1; j <= x[i]; j++) {
				if (mp[j]) {
					tmp += d;
				}
			}
			if (tmp <= v[i]) {
				ans += v[i] - tmp;
				cout << ans << " ";
				for (int j = x[i] - y[i] + 1; j <= x[i]; j++) {
				    if (mp[j]) {
					    mp[j] = 0;
				    }
			    }
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}

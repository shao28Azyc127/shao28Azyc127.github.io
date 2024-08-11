#include <cstdio>
#include <algorithm>
#include <functional>
#define int long long
using namespace std;
int n, m;
string s[3005], a[3005], b[3005];
signed main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i ++) {
		s[i].resize(m);
		scanf("%s", s[i].begin());
		a[i] = b[i] = s[i];
		sort(a[i].begin(), a[i].end());
		sort(b[i].begin(), b[i].end(), greater<char>());
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (i == j) {
				continue;
			}
			if (a[i] >= b[j]) {
				putchar('0');
				goto _continue;
			}
		}
		putchar('1');
		_continue:;
	}
	putchar('\n');
	return 0;
}

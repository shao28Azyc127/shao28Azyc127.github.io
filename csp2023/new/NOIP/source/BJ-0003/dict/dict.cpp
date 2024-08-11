#include <bits/stdc++.h>
using namespace std;
int maxn[5005], minn[5005];
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		minn[i] = 1e9;
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			maxn[i] = max(maxn[i], c - 'a');
			minn[i] = min(minn[i], c - 'a');
		}
	}
	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (minn[i] >= maxn[j]) flag = false;
		}
		if (flag) putchar('1');
		else putchar('0');
	}
	putchar('\n');
	return 0;
}
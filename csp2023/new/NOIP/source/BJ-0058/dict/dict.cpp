#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
const int base = 131;
const int N = 3005;
int n, m;
char p[N][N], q[N][N];
ull a[N][N], b[N][N];

bool cmp(int x, int y) {
	int l = 1, r = m, mid, ans = 0;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(a[x][mid] == b[y][mid]) {
			l = mid + 1, ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
	return (p[x][ans + 1] < q[y][ans + 1]);
}

int main() {

	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> (p[i] + 1);
		sort(p[i] + 1, p[i] + m + 1);
		for(int j = 1; j <= m; ++j) q[i][m - j + 1] = p[i][j];
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			a[i][j] = a[i][j - 1] * base + p[i][j];
			b[i][j] = b[i][j - 1] * base + q[i][j];
		}
	}
	for(int i = 1; i <= n; ++i) {
		bool flag = true;
		for(int j = 1; j <= n; ++j) {
			if(i == j) continue;
			if(cmp(i, j) == false) {
				flag = false; break;
			}
		}
		cout << flag;
	}
	cout << '\n';

	cout.flush();
	return 0;
}
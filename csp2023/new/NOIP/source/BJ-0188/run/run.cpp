#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
const int M = 1010;

int c, t, n, m, k;
int l[N], r[N], w[N], id[N];

ll ans, d;
ll is[M][M], f[M][M];

void sol1() {
	while(t--) {
		ans = 0;
		cin >> n >> m >> k >> d;
		for(int i = 1; i <= m; i++) {
			int x, y;
			cin >> y >> x >> w[i];
			r[i] = y, l[i] = y - x + 1;
			if(k >= x && x * d < w[i])
				ans += w[i] - x * d;
		}
		cout << ans << "\n";
	}
}

void sol2() {
	while(t--) {
		cin >> n >> m >> k >> d;
		ans = 0;
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				f[i][j] = is[i][j] = 0;
		for(int i = 1; i <= m; i++) {
			cin >> l[i] >> r[i] >> w[i];
			is[l[i]][r[i]] += w[i];
		}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				is[i][j] += is[i][j - 1];
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j <= min(i - 1, k); j++)
				f[i][0] = max(f[i][0], f[i - 1][j]);
			for(int j = 1; j <= min(i, k); j++)
				f[i][j] = f[i - 1][j - 1] + is[i][j] - d;
		}
		for(int i = 0; i <= min(n, k); i++)
			ans = max(ans, f[n][i]);
		cout << ans << '\n';
	}
}

/*void sol3() {
	while(t--) {
		cin >> n >> m >> k >> d;
		for(int i = 1; i <= m; i++)
			cin >> r[i] >> l[i] >> w[i], id[i] = i, l[i] = r[i] - l[i] + 1;
		sort(id + 1, id + m + 1, cmp);
		for(int i = 1; i <= m; i++) {
			
	}*/

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	if(c >= 17 && c <= 18) {
		sol1();
		return 0;
	}
	if(c <= 9) {
		sol2();
		return 0;
	}
	/*if(c >= 15 && c <= 16) {
		sol3();
		return 0;
	}*/
}

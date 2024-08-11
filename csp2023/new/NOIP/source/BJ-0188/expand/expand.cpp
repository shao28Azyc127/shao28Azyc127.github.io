#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 10;

int C, n, m, q;

bool f;
bool g[N][N];

int a[N], b[N], c[N], d[N];

bool check() {
	if(a[1] < b[1]) {
		for(int i = 1; i <= max(n, m); i++)
			swap(a[i], b[i]);
		swap(n, m);
		f ^= 1;
	}
	if(a[1] == b[1])
		return 0;
	if(a[n] < b[m])
		return 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			g[i][j] = 0;
	g[1][1] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i] > b[j])
				g[i][j] |= g[i - 1][j] | g[i][j - 1] | g[i - 1][j - 1];
	return g[n][m];
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> C >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		cin >> a[i], c[i] = a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i], d[i] = b[i];
	cout << check();
	while(q--) {
		int kx, ky;
		cin >> kx >> ky;
		for(int i = 1; i <= n; i++)
			a[i] = c[i];
		for(int i = 1; i <= m; i++)
			b[i] = d[i];
		for(int i = 1; i <= kx; i++) {
			int x, y;
			cin >> x >> y;
			a[x] = y;
		}
		for(int i = 1; i <= ky; i++) {
			int x, y;
			cin >> x >> y;
			b[x] = y;
		}
		cout << check();
		if(f)
			swap(n, m), f = 0;
	}
	return 0;
}

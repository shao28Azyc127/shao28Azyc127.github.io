#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vint;

int read() {
	int a = 0, b = 0; char c = getchar();
	while (c < '0' || c > '9') b ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9') a = a * 10 - 48 + c, c = getchar();
	return b ? -a : a;
}


const int N = 200010;
int a[N], pa[N], iu[N];
int find(int i) { return pa[i] == i ? i : pa[i] = find(pa[i]); }
void merg(int i, int j) { i = find(i), j = find(j), pa[i] = j; }

void sol() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) a[i] = i;
	int R = n + 2;
	int T = n + 1, U = n + 2, F = T + R;
	while (m--) {
		int i;
		char v; cin >> v >> i;
		if (v == '+') {
			int j; cin >> j;
			a[i] = a[j];
		} else if (v == '-') {
			int j; cin >> j;
			a[i] = (a[j] > R ? a[j] - R : a[j] + R);
		} else if (v == 'T') a[i] = T;
		else if (v == 'F') a[i] = F;
		else if (v == 'U') a[i] = U;
	}
	for (int i = 1; i <= R * 2; ++i) pa[i] = i, iu[i] = 0;
	merg(U, U + R);
	for (int i = 1; i <= n; ++i) merg(i, a[i]), merg(i + R, (a[i] > R ? a[i] - R : a[i] + R));
	iu[find(U)] = 1;
	for (int i = 1; i <= n; ++i) if (find(i) == find(i + R)) iu[find(i)] = 1;
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans += iu[find(i)];
	cout << ans << '\n';
	
}


int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(0);
	int T; cin >> T; cin >> T;
	while (T--) sol();
	
	return 0;
}
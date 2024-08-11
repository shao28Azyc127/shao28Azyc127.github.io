#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
LL INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k, d;
vector<LL> f[N];
struct pao{
	int l, r, w;
}a[N];
struct Node{
	int l, r;
	LL mx;
}tr[N * 4];

bool cmp(pao a, pao b) {
	if (a.r != b.r) return a.r < b.r;
	return a.l < b.l;
}

void solve1() {
	scanf("%d%d%d%d", &n, &m, &k, &d);
	for (int i = 1; i <= m; i ++ ) {
		int x, y;
		scanf("%d%d%d", &x, &y, &a[i].w);
		a[i].r = x, a[i].l = x - y + 1;
	}
	sort(a + 1, a + m + 1, cmp);
	for (int i = 0; i <= m; i ++ ) f[i].clear();
	for (int i = 0; i <= k; i ++ ) f[0].push_back((i == 0 ? 0 : -INF));
	LL mx = 0;
	for (int i = 1; i <= m; i ++ ) {
		LL _mx = -INF;
		if (i >= 2) f[i - 2].clear();
		for (int j = 0; j <= k; j ++ ) f[i].push_back(-INF);
		for (int j = 0; j <= k; j ++ ) {
			int ch = a[i].r - a[i - 1].r;
			ch = min(ch, j);
			if (j >= a[i].r - a[i - 1].r) {
				int x = 0;
				if (j >= a[i].r - a[i].l + 1) x = a[i].w;
				f[i][j] = max(f[i][j], f[i - 1][j - (a[i].r - a[i - 1].r)] + x - 1ll * ch * d);
			}
			else{
				int x = 0;
				if (j >= a[i].r - a[i].l + 1) x = a[i].w;
				f[i][j] = max(f[i][j], mx + x - 1ll * ch * d);
			}
			_mx = max(_mx, f[i][j]);
		}
		mx = _mx;
	}
	LL ans = 0;
	for (int i = 0; i <= k; i ++ )
		ans = max(ans, f[m][i]);
	cout << ans << endl;
	return;
}

void solve2() {
	scanf("%d%d%d%d", &n, &m, &k, &d);
	LL ans = 0;
	for (int i = 1; i <= m; i ++ ) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		LL res = w - 1ll * y * d;
		if (res > 0) ans += res;
	}
	cout << ans << endl;
	return;
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	if (c <= 11 || c == 15 || c == 16) {
		while (t -- ) solve1();
	}
	else {
		while (t -- ) solve2();
	}
	return 0;
}

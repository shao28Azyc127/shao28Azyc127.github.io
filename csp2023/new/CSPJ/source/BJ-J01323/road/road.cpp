#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int v[N], a[N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n - 1; i ++ ) cin >> v[i];
	for (int i = 0; i < n; i ++ ) cin >> a[i];
	int mf = 0x3f3f3f3f;
	int rf = 0;
	LL ans = 0;
	for (int i = 0; i < n - 1; i ++ ) {
		int x = max(0, v[i] - rf);
		rf = max(0, rf - v[i]);
		mf = min(mf, a[i]);
		ans += (x + d - 1) / d * mf;
		rf += d - (x % d);
	}
	cout << ans << endl;
	return 0;
}

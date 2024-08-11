#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
const int MAXN = 100010;
long long s[MAXN], v[MAXN], a[MAXN], mina[MAXN], minp[MAXN], n, d, ckp[MAXN];
int main() {
	ios::sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	for (int i = 2; i <= n; i++) {
		cin >> v[i];
		s[i] = s[i - 1] + v[i];
		ckp[i] = (s[i] + d - 1) / d;
	}
	mina[0] = 1e9;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (mina[i - 1] < a[i]) {
			minp[i] = minp[i - 1];
			mina[i] = mina[i - 1];
		} else {
			minp[i] = i;
			mina[i] = a[i];
		}
	}
	ll ans = 0;
	int cur = n;
	while (cur > 1) {
		ans += ((ckp[cur] - ckp[minp[cur - 1]]) * mina[cur - 1]);
		cur = minp[cur - 1];
	}
	cout << ans << endl;
	return 0;
}
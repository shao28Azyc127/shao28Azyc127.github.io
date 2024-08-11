#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
ll v[N], a[N];
ll top(ll x, ll y) {
	return x / y + !!(x % y);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, d;
	scanf("%d%d", &n, &d);
	for (int i = 1; i < n; i++) {
		scanf("%lld", &v[i]);
	}
	ll now = 0;
	ll minx = 1e9;
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		scanf("%lld", &a[i]);
		ll cost = top(max(0ll, v[i] - now), d);
		if (a[i] < minx) {
			minx = a[i];
		}
		ans += cost * minx;
		now = now + cost * d - v[i];
	}
	printf("%lld\n", ans);
	return 0;
}

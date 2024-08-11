#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const long long MAXN = 5010;
int main(){
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	ll t, m;
	ll a[MAXN], b[MAXN], c[MAXN];
	scanf("%lld%lld", &t, &m);
	for(ll i = 1; i <= t; ++i) {
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
	}
	for(ll i = 1; i <= t; ++i) {
		ll delta = b[i] * b[i] - 4 * a[i] * c[i];
		if(delta < 0) {
			printf("NO\n");
		} else {
			ll x = (-1 * b[i] + sqrt(delta))/(2 * a[i]);
			printf("%lld\n", x);
		}
	}
	return 0;
}

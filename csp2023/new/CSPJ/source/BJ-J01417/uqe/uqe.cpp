#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll sq(ll x) {
	ll res = sqrt(x) + 2;
	while (res * res > x) {
		--res;
	}
	return res * res == x ? res : -1;
}
ll gcd(ll a, ll b) {
	return !b ? a : gcd(b, a % b);
}
inline void out(ll x, ll y) {
	if (y < 0)
		y = -y, x = -x;
	if (x % y) {
		ll g = gcd(abs(x), y);
		printf("%lld/%lld", x / g, y / g);
	} else
		printf("%lld", x / y);
}
inline void fj(ll &x, ll &y) {
	y = 1;
	for (ll i = 2; i * i <= x; i++) {
		if (x % (i * i) == 0) {
			while (x % (i * i) == 0) {
				y *= i;
				x /= (i * i);
			}
		}
	}
	//cerr << x << ' ' << y << "!\n";
}
int main() {
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int t, m;
	scanf("%d%d", &t, &m);
	while (t--) {
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		ll res = b * b - 4 * a * c;
		if (res < 0) {
			printf("NO\n");
			continue;
		}
		ll rt = sq(res);
		if (a < 0)
			b = -b, a = -a;
		if (~rt) {
			out(-b + rt, 2 * a);
		} else {
			ll q3 = 2 * a;
			if (b)
				out(-b, q3), printf("+");
			ll q2;
			fj(res, q2);
			if (q2 % q3 == 0) {
				if (q2 == q3)
					printf("sqrt(%lld)", res);
				else
					printf("%lld*sqrt(%lld)", q2 / q3, res);
			} else {
				ll g = gcd(q2, q3);
				q2 /= g;
				q3 /= g;
				if (q2 == 1)
					printf("sqrt(%lld)/%lld", res, q3);
				else
					printf("%lld*sqrt(%lld)/%lld", q2, res, q3);
			}
		}
		printf("\n");
	}
	return 0;
}

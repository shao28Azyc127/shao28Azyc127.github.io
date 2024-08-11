#include <cstdio>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;
int T, m, a, b, c, dt, sqdt, p, q, _gcd, p1, q1, p2, q2, r;
bool flag;
signed main() {
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	scanf("%lld%lld", &T, &m);
	while (T --) {
		scanf("%lld%lld%lld", &a, &b, &c);
		dt = b * b - 4 * a * c;
		if (dt < 0) {
			printf("NO\n");
			continue;
		}
		sqdt = sqrt(dt);
		flag = false;
		for (int i = sqdt - 2; i <= sqdt + 2; i ++) {
			if (i * i == dt) {
				sqdt = i;
				flag = true;
			}
		}
		if (flag) {
			if (a > 0) {
				p = -b + sqdt;
			} else {
				p = -b - sqdt;
			}
			q = 2 * a;
			_gcd = __gcd(p, q);
			p /= _gcd;
			q /= _gcd;
			if (q < 0) {
				p = -p;
				q = -q;
			}
			if (q == 1) {
				printf("%lld\n", p);
			} else {
				printf("%lld/%lld\n", p, q);
			}
		} else {
			p1 = -b;
			q1 = 2 * a;
			_gcd = __gcd(p1, q1);
			p1 /= _gcd;
			q1 /= _gcd;
			if (q1 < 0) {
				p1 = -p1;
				q1 = -q1;
			}
			if (p1 != 0) {
				if (q1 == 1) {
					printf("%lld+", p1);
				} else {
					printf("%lld/%lld+", p1, q1);
				}
			}
			r = dt;
			q2 = abs(2 * a);
			p2 = 1;
			for (int i = 2; i * i <= r; i ++) {
				while (r % (i * i) == 0) {
					p2 *= i;
					r /= i * i;
				}
			}
			_gcd = __gcd(p2, q2);
			p2 /= _gcd;
			q2 /= _gcd;
			if (p2 == 1 && q2 == 1) {
				printf("sqrt(%lld)\n", r);
			} else if (q2 == 1) {
				printf("%lld*sqrt(%lld)\n", p2, r);
			} else if (p2 == 1) {
				printf("sqrt(%lld)/%lld\n", r, q2);
			} else {
				printf("%lld*sqrt(%lld)/%lld\n", p2, r, q2);
			}
		}
	}
	return 0;
}

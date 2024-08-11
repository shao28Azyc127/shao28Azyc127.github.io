#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, a, b, c;
inline void tf(ll& x, ll& y) {
    if (y < 0) x = -x, y = -y;
    ll tmp = abs(__gcd(x, y));
    x /= tmp;
    y /= tmp;
}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    while (n--) {
        scanf("%lld%lld%lld", &a, &b, &c);
        ll pbs = b * b - 4 * a * c;
        if (pbs < 0) {
            printf("NO\n");
            continue;
        }
        ll sq = sqrtl(pbs * 1.0);
        if (sq * sq == pbs) {
            ll x = -b + sq, y = 2 * a;
            if (y < 0) x -= 2 * sq;
            tf(x, y);
            if (y == 1) printf("%lld\n", x);
            else printf("%lld/%lld\n", x, y);
        } else {
            ll q1x = -b, q1y = 2 * a;
            tf(q1x, q1y);
            ll q2x = 1, q2y = 2 * a;
            tf(q2x, q2y);
            if (q2x < 0) q2x = -q2x;
            ll st = sqrtl(pbs);
            for (ll i = 2; i <= st; i++) {
                ll tmp = i * i;
                while (pbs % tmp == 0) {
                    pbs /= tmp;
                    q2x *= i;
                }
            }
            tf(q2x, q2y);
            if (q1x != 0) {
                if (q1y == 1) printf("%lld+", q1x);
                else printf("%lld/%lld+", q1x, q1y);
            }
            ld tmp = (q2x * 1.0) / (q2y * 1.0);
            ld q3 = 1.0 / (tmp);
            if (tmp == ld(1.0)) printf("sqrt(%lld)\n", pbs);
            else if (ld(ll(tmp)) == tmp) printf("%lld*sqrt(%lld)\n", ll(tmp), pbs);
            else if (ld(ll(q3)) == q3) printf("sqrt(%lld)/%lld\n", pbs, ll(q3));
            else {
                if (q2x == 1) printf("sqrt(%lld)/%lld\n", pbs, q2y);
                else printf("%lld*sqrt(%lld)/%lld\n", q2x, pbs, q2y);
            }
        }
    }
    return 0;
}

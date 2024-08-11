#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll delta, T, M, a, b, c;
ll gcd(ll x, ll y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}
ll ms(ll x) {
    for(int i = 2; i * i <= x; i ++)
        while(x % (i * i) == 0)
            x /= (i * i);
    return x;
}
ll md(ll x) {
    ll sum = 1;
    for(int i = 2; i * i <= x; i ++)
        while(x % (i * i) == 0)
            x /= (i * i), sum *= i;
    return sum;
}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%lld%lld", &T, &M);
    while(T --) {
        scanf("%lld%lld%lld", &a, &b, &c);
        delta = b * b - 4 * a * c;
        if(delta < 0) {
            printf("NO\n");
            continue;
        }
        int x = sqrt(delta), n = -b, m = 2 * a;
        if(x * x * 1ll == delta) {
            if(a < 0) n -= x;
            else n += x;
            int g = gcd(abs(n), abs(m));
            n /= g, m /= g;
            if(m < 0) n = -n, m = -m;
            if(n == 0) printf("0\n");
            else if(m == 1) printf("%d\n", n);
            else printf("%d/%d\n", n, m);
        } else {
            int g = gcd(abs(n), abs(m));
            n /= g, m /= g;
            if(m < 0) n = -n, m = -m, delta = -delta;
            if(n == 0) printf("");
            else if(m == 1) printf("%d", n);
            else printf("%d/%d", n, m);
            if(n != 0) {
                if(a > 0) {
                    if(delta > 0) printf("+");
                    else printf("-");
                } else {
                    if(delta > 0) printf("-");
                    else printf("+");
                }
            }
            m = abs(2 * a);
            int o = md(abs(delta)), p = ms(abs(delta));
            g = gcd(o, m);
            o /= g, m /= g;
            if(m != 1 && o != 1) printf("%lld*sqrt(%lld)/%d\n", o, p, m);
            else if(o != 1) printf("%lld*sqrt(%lld)\n", o, p);
            else if(m != 1) printf("sqrt(%lld)/%d\n", p, m);
            else printf("sqrt(%lld)\n", p);
        }
    }
    return 0;
}

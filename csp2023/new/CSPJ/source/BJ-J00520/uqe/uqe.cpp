
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b, c;
ll delta;
ll ansfm, ansfz, insqr, sqrxs, sqrfm; //sqrxs : sqr xishu
ll gcd(ll x, ll y) {
    if (x < 0) {
        x = -x;
    }
    if (y < 0) {
        y = -y;
    }
    if (y > x) {
        swap(x, y);
    }
    if (x % y == 0) {
        return y;
    }
    return gcd(y, x % y);
}
ll wqp(ll x) {
    int ret = 1;
    for (int i = 2; i <= sqrt(x) + 1; i++) {
        if (x % (i * i) == 0) {
            ret *= i;
            x /= i * i;
        }
    }
    return ret;
}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    scanf("%d%d", &t, &m);
    while(t--) {
        scanf("%lld%lld%lld", &a, &b, &c);
    delta = b * b - 4 * a * c;
    if (delta < 0) {
        printf("NO\n");
        return 0;
    }
    if (a < 0) {
        b = -b;
        a = -a;
    }
    sqrxs = wqp(delta);
    cout << (sqrxs - b) / 2 / a;
    }
    return 0;
}


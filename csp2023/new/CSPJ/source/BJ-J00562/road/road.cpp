#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long l;
l v[100005], a[100005], n, r = 0, d, rest = 0, m = 0;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld", &n, &d);
    for (l i = 1; i < n; ++i) {
        scanf("%lld", &v[i]);
    }
    for (l i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    l i = 1;
    for (l j = i + 1; j <= n; ++j) {
        r += v[j - 1];
        if (a[i] > a[j]) {
            if (rest < r) {
                r -= rest;
                l x = (r + d - 1) / d;
                m += x * a[i];
                printf("%lld\n", m);
                rest = x * d - r;
            } else {
                rest -= r;
            }
            i = j;
            r = 0;
        }
    }
    if (rest < r) {
        r -= rest;
        l x = (r + d - 1) / d;
        m += x * a[i];
        rest = x * d - r;
    } else {
        rest -= r;
    }
    printf("%lld\n", m);
    return 0;
}

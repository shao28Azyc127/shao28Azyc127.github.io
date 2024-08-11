#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
typedef long long ll;

int n, d, a[MAXN], v[MAXN];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i = 1; i < n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    ll cur = 0, ans = 0;
    int mn = a[1];
    for (int i = 1; i < n; i++) {
        mn = min(mn, a[i]);
        cur -= v[i - 1];
        ll c = (v[i] - cur + d - 1) / d;
        ans += (ll)c * mn;
        cur += (ll)c * d;
    }
    printf("%lld\n", ans);
    return 0;
}

// g++ road.cpp -o road && ./road
// expected 100pts

// Good Luck.
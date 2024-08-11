#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int n, d;
long long v[N];
long long pls[N];
int a[N];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    long long lst = 0;
    for(int i = 1; i < n; i++) {
        scanf("%lld", &v[i]);
        v[i] += v[i - 1];
        long long tp = 0;
        if(v[i] % d == 0) {
            tp = v[i] / d;
        } else {
            tp = v[i] / d + 1;
        }
        pls[i] = tp - lst;
        lst = tp;
    }
    a[0] = N;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] = min(a[i], a[i - 1]);
        ans += (long long)pls[i] * a[i];
    }
    printf("%lld\n", ans);
    return 0;
}

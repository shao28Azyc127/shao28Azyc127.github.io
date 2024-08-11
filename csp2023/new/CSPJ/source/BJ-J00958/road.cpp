#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
LL r1 = 0, v1 = 0, v2 = 2147483647, v3 = 0, n, d, v[100010], a[100010];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld", &n, &d);
    for (int i = 0; i < n - 1; i ++ ) {
        scanf("%lld", &v[i]);
    }

    for (int i = 0; i < n; i ++ ) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < n - 1; i ++ ) {
        v2 = min(v2, a[i]);
        v3 = v3 + v[i];
        if (v3 > v1) r1 += ((v3 - v1 - 1) / d + 1) * v2;
        if (v3 > v1) v1 += ((v3 - v1 - 1) / d + 1) * d;
    }

    printf("%lld\n", r1);
    return 0;
}

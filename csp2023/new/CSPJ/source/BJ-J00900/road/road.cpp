#include <bits/stdc++.h>
using namespace std;

const int NN = 1e5 + 10;
typedef long long LL;
int n, d, a[NN], p[NN];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] = a[i-1] + a[i];
    }
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    p[n] = 0;
    int i = 1;
    double c = 0;
    LL ans = 0;
    while(i < n) {
        for (int j = i + 1; j <= n; j++) {
            if (p[j] < p[i]) {
                double nc = (a[j] - a[i]) / (d * 1.0);
                int tc = (a[j] - a[i]) / d;
                if (nc - double(tc) - c > 0.001) tc++;
                ans += LL(tc) * LL(p[i]);
                c = double(tc) + c - nc;
                i = j;
                break;
            }
        }
    }

    printf("%lld", ans);
    return 0;
}

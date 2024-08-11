#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 114;
int n, d;
int v[N], a[N], oil[N];

inline int Ceil(double x)
{
    int t = x + 1;
    if (t * 1.0 - x == 1) return x;
    else return t;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i = 1; i < n; i++) scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    double last = 0;
    for (int i = 2; i <= n; i++)
    {
        oil[i] = Ceil(v[i - 1] * 1.0 / d * 1.0 - last);
        last = oil[i] + last - v[i - 1] * 1.0 / d * 1.0;
    }
    int oil_now = a[1];
    long long ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans += oil[i] * oil_now;
        if (a[i] < oil_now) oil_now = a[i];
    }
    printf("%lld", ans);
    return 0;
}

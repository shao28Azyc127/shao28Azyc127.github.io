#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, d, v[100005], a[100005], mina = 2e9;
LL G, ans;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld %lld", &n, &d);
    for(int i = 1; i <= n - 1; i++)
            scanf("%lld", &v[i]);
    for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
    for(int i = 1; i <= n - 1; i++)
    {
        mina = min(mina, a[i]);
        v[i] -= G;
        G = 0;
        if(v[i] < 0)
        {
            G = 0 - v[i];
            v[i] = 0;
            continue;
        }
        G += (v[i] / d + (v[i] % d != 0)) * d;
        G -= v[i];
        ans += (v[i] / d + (v[i] % d != 0)) * mina;
        v[i] = 0;
    }
    printf("%lld\n", ans);
    return 0;
}

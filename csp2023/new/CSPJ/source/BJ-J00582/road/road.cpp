#include <iostream>
#include <cstdio>
#define int long long

using namespace std;

const int N = 1e5 + 5;
int n, d, u[N], a[N], mn, s[N], now, ans;
int min(int x, int y){return x < y ? x : y;}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld %lld", &n, &d);
    for(register int i = 1;i < n;i++)
        scanf("%lld", &u[i]);
    for(register int i = 2;i <= n;i++)
        s[i] = s[i-1] + u[i-1];
    for(register int i = 1;i <= n;i++)
        scanf("%lld", &a[i]);
    mn = a[1];
    for(register int i = 2;i <= n;i++)
    {
        register int x = (s[i] - now) / d;
        if(now >= s[i])
            x = 0;
        if(now + x * d < s[i])
            x++;
        ans += x * mn, now += x * d;
        mn = min(mn, a[i]);
    }
    printf("%lld", ans);
    return 0;
}

#include <bits/stdc++.h>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define lowbit(x) ((x)&-(x))
#define MAXN 200005
using namespace std;
int n, d, v[MAXN], a[MAXN], o[MAXN], sum[MAXN], minn = 1000000000000000ll, ans, hv;
int needoil(int road)
{
    if (road <= 0)
    {
        return 0;
    }
    return (road + d - 1) / d;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for (int i = 1; i < n; i++)
    {
        scanf("%lld",&v[i]);
    }
    for (int i = 1; i < n; i++)
    {
        scanf("%lld",&a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < minn)
        {
            o[++o[0]] = i;
            minn = a[i];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        sum[i] = sum[i - 1] + v[i - 1];
    }
    o[o[0] + 1] = n;
    for (int i = 1; i <= o[0]; i++)
    {
        // cout << o[i] << " ";
        int nowneedroad = sum[o[i + 1]] - sum[o[i]] - hv;
        int nowneedoil = needoil(nowneedroad);
        hv = nowneedoil * d - nowneedroad;
        ans += nowneedoil * a[o[i]];
    }
    // cout << endl;
    cout << ans;
    return 0;
}

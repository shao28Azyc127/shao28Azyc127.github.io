#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn = 1e5 + 10;

ll n, d, cura, cnt, ans;
ll v[maxn], a[maxn], pre[maxn], da[maxn];
double nowa, nd;

ll dis (ll a, ll b)
{

    return (pre[b] - pre[a]);
}

int main ()
{
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 2; i <= n; i ++)
    {
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
    }
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    cura = a[1];
    da[0] = 1;
    da[++ cnt] = 1;
    for (int i = 2; i < n; i ++)
    {
        if (a[i] < cura)
        {
            da[++ cnt] = i;
            cura = a[i];
        }
    }
    da[cnt + 1] = n;
    for (int i = 1; i <= cnt; i ++)
    {
        nowa -= dis (da[i - 1], da[i]) * 1.0 / d;
        nd = dis (da[i], da[i + 1]) * 1.0 / d - nowa;
        //cout << "da[i]:" << da[i] << " nowa:" << nowa << " nd:" << nd << " ans:" << ans << endl;
        nd = ceil (nd);
        nowa += nd;
        ans += nd * a[da[i]];
        //cout << "da[i]:" << da[i] << " nowa:" << nowa << " nd:" << nd << " ans:" << ans << endl;
    }
    cout << ans;
    return 0;
}

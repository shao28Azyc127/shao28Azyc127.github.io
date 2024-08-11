#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[1000005], v[1000005], minn = 0x3f3f3f3f3f3f3f3f;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ll n, d, ans = 0, s = 0;
    cin >> n >> d;
    for(int i = 1; i < n; ++i)
    {
        cin >> v[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] < minn)
        {
            minn = a[i];
        }
        ans += (v[i] - s + d - 1) / d * minn;
        s += (v[i] - s + d - 1) / d * d - v[i];
    }
    cout << ans << endl;
    return 0;
}

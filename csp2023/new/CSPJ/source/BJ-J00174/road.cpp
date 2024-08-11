#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, d, dis[200005], pr[300005], f = 1, pdis[300005];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> dis[i];
        pdis[i] = pdis[i - 1] + dis[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> pr[i];
        pr[n] = 0;
    }
    ll ans = 0, now = 0;
    while(f != n)
    {
        for(int i = f + 1; i <= n; i++)
        {
            if(pr[i] < pr[f])
            {
                ans += ceil((double)(pdis[i - 1] - pdis[f - 1] - now) / d) * pr[f];
                now = now + ceil((double)(pdis[i - 1] - pdis[f - 1] - now) / d) * d - (pdis[i - 1] - pdis[f - 1] - now);
                f = i;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

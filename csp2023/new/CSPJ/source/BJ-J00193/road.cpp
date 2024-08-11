#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int NR = 100010;
long long S[NR], a[NR], n, d, ans;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++)
    {
        long long v;
        cin >> v;
        S[i + 1] = S[i] + v;
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = 0, S[n + 1] = S[n];
    long long s = 1, last = 0;
    while (s <= n)
    {
        int t = s;
        while (a[t] >= a[s]) t++;
        long long dis = max(1ll * 0, S[t] - S[s] - last), val = 0;
        if (dis % d == 0) val = dis / d;
        else val = (dis / d) + 1;
        last = val * d - dis;
        ans += a[s] * val;
        s = t;
    }
    cout << ans << '\n';
    return 0;
}

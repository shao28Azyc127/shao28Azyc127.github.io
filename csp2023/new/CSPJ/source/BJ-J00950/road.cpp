#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, d, v[100010], a[100010], minn = 0;
long long ans = 0;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++)
        cin >> v[i];
    a[0] = 2e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < a[minn] && i < n) minn = i;
    }
    if (minn == 1)
    {
        long long s = 0;
        for (int i = 1; i < n; i++)
            s += v[i];
        cout << 1LL * a[1] * (s + d - 1) / d << endl;
        return 0;
    }
    int last = minn;
    while (minn >= 1)
    {
        int minn2 = minn;
        long long s = 0;
        for (int i = minn2; i < last; i++)
            s += v[i];
        ans += 1LL * a[minn2] * (s + d - 1) / d;
        last = minn;
        minn = 0;
        for (int i = 1; i < minn2; i++)
            if (a[i] < a[minn]) minn = i;
    }
    cout << ans << endl;
    return 0;
}

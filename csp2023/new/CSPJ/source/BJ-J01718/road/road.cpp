#include <bits/stdc++.h>
using namespace std;

const int NR = 1e6 + 10;
long long n, d, v[NR], a[NR], ans = 0;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i < n; i++)
    {
        cin >> v[i];
    }
    a[0] = 2147483647;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = min(a[i], a[i - 1]);
    }
    for(int i = 1; i < n; i++)
    {
        if(v[i] < 0)
        {
            v[i + 1] += v[i];
            continue;
        }
        long long req = v[i] / d;
        long long lft = v[i] % d;
        if(lft)
        {
            req++;
            lft = d - lft;
        }
        v[i + 1] -= lft;
        ans += req * a[i];
    }
    cout << ans << endl;
    return 0;
}
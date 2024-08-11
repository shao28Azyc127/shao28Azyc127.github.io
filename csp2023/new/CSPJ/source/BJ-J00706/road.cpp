#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 5;

int n, d , v[N];
long long ans;

int main()
{
    ifstream cin("road.in");
    ofstream cout("road.out");
    ios::sync_with_stdio(false);

    cin >> n >> d;
    for (int i = 1; i < n; ++i)
    {
        cin >> v[i];
    }

    long long cur = INF;
    long long r = 0;
    long long dist = 0;

    for (int i = 1; i <= n; ++i)
    {
        long long a;
        cin >> a;
        if (a < cur || i == n)
        {
            long long cnt = (dist - min(dist, r) + d - 1) / d;
            if (cnt != (dist + d - 1) / d) r -= min(dist, r);
            r += cnt * d - dist;
            long long price = cnt * cur;
            ans += price;
            cur = a;
            dist = 0;
        }
        dist += v[i];
    }

    cout << ans << endl;
    return 0;
}
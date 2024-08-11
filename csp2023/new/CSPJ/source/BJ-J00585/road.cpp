#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int n, d;
int dist[N];
int gas[N];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d %d", &n, &d);
    for (int i = 1, v; i < n; i++)
    {
        scanf("%d", &v);
        if (i == 0)
        {
            dist[i] = v;
        }
        else
        {
            dist[i] = dist[i - 1] + v;
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &gas[i]);
    }

    int minn = gas[0];
    int ans = dist[1] / d * minn;
    int len = dist[1] / d * d;
    if (dist[1] % d > 0)
    {
        ans += minn;
        len += d;
    }
    for (int i = 1; i < n - 1; i++)
    {
        minn = min(minn, gas[i]);
        ans += (dist[i + 1] - len) / d * minn;
        len += (dist[i + 1] - len) / d * d;
        if ((dist[i + 1] - len) % d > 0)
        {
            ans += minn;
            len += d;
        }
    }
    cout << ans;
    return 0;
}

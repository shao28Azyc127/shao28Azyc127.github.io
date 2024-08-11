#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

long long n, d, ans, sy, dis[100005], mon[100005], minid[100005];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 2; i <= n; i++)
    {
        cin >> dis[i];
        dis[i] += dis[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> mon[i];
    }
    for (int i = 1; i <= n; i++)
    {
        bool flag = false;
        for (int j = i; j <= n; j++)
        {
            if (mon[j] < mon[i])
            {
                ans = ans + ceil(1.0 * (dis[j] - dis[i] - sy) / d) * mon[i];
                sy = ceil(1.0 * (dis[j] - dis[i] - sy) / d) * d - (dis[j] - dis[i] - sy);
                i = j - 1;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            ans = ans + ceil(1.0 * (dis[n] - dis[i]) / d) * mon[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
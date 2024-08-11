#include <bits/stdc++.h>

using namespace std;

long long v[500005], s[500005];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    long long a, i, n, d, ans = 0;
    cin >> n >> d;
    for (i = 2; i <= n; i++)
    {
        cin >> a;
        s[i] = s[i - 1] + a;
    }
    for (i = 1; i <= n; i++)
        cin >> v[i];
    long long tmp = 1, oil = 0;
    while (tmp != n)
    {
        for (i = tmp + 1; i <= n; i++)
        {
            if (v[tmp] > v[i] || i == n)
            {
                oil -= abs(s[i] - s[tmp]);
                if (oil < 0)
                {
                    ans += ceil(1.0 * abs(oil) / d) * v[tmp];
                    oil += ceil(1.0 * abs(oil) / d) * d;
                }
                tmp = i;
                i = n;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

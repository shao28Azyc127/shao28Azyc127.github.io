#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, d, v[100010], a[100010], sum = 0, s[100010], ans = 0;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        s[i + 1] = s[i] + v[i];
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int c = 0;
    for (int i = 2; i <= n; i++)
        if (a[1] > a[i])
        {
            c = 1;
            break;
        }
    if (c == 0)
    {
        if (sum % d == 0) cout << a[1] * (sum / d) << endl;
        else cout << a[1] * (sum / d + 1) << endl;
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
                if (a[j] < a[i])
                {
                    ans += ceil(1.0 * (s[j] - s[i]) / d) * a[i];
                    cout << ans << ' ' << i << endl;
                    i = j - 1;
                    break;
                }
    }
    cout << ans << endl;
    return 0;
}
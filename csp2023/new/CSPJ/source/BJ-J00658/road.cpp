#include <bits/stdc++.h>
using namespace std;
int n, d, x;
int v[100004], a[100005], f[100005], dl[100005];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        v[i] = v[i-1] + x;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    f[1] = 0;
    dl[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        f[i] = 1000000;
        for (int j = 1; j <= i-1; j++)
        {
            int w = f[j] + (v[i] - v[j] - dl[j] + d-1) / d * a[j];
            if (w < f[i])
            {
                f[i] = w;
                dl[i] = dl[j] + (w - f[j]) / a[j] * d - (v[i] - v[j]);
            }
        }
    }
    cout << f[n];
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, d, v[100005], a[100005], cnt, dis, minn = 100005, stdis;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] == 1)
        {
            if (v[i] % d == 0)
            {
                cnt += a[i] * (v[i] / d);
                dis += v[i];
            }
            else
            {
                cnt += a[i] * (v[i] / d + 1);
                dis += d * (v[i] / d + 1);
            }
            minn = a[i];
        }
        else if (a[i] < minn)
        {
            if ((v[i] - (dis - stdis)) % d == 0)
            {
                cnt += a[i] * ((v[i] - (dis - stdis)) / d);
                dis += v[i] - (dis - stdis);
            }
            else
            {
                cnt += a[i] * ((v[i] - (dis - stdis)) / d + 1);
                dis += d * ((v[i] - (dis - stdis)) / d + 1);
            }
            minn = a[i];
        }
        else
        {
            if ((v[i] - (dis - stdis)) % d == 0)
            {
                cnt += minn * ((v[i] - (dis - stdis)) / d);
                dis += v[i] - (dis - stdis);
            }
            else
            {
                cnt += minn * ((v[i] - (dis - stdis)) / d + 1);
                dis += d * ((v[i] - (dis - stdis)) / d + 1);
            }
        }
        stdis += v[i];
    }
    cout << cnt;
    return 0;
}
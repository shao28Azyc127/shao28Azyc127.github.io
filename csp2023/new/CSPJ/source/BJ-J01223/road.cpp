#include <bits/stdc++.h>
using namespace std;

int v[100010], a[100010];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    bool f1 = true, f2 = true;
    cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        if (v[i] % d != 0)
        {
            f1 = false;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < a[1])
        {
            f2 = false;
        }
    }
    if (f2)
    {
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            cnt += v[i];
        }
        if (cnt % d != 0)
        {
            cnt /= d;
            cnt++;
        }
        else
        {
            cnt /= d;
        }
        cout << cnt * a[1] << endl;
        return 0;
    }
    if (f1)
    {
        int cnt = 0, l = 1;
        while (l <= n)
        {
            int sum = 0;
            for (int i = l + 1; i <= n; i++)
            {
                if (a[i] < a[l])
                {
                    sum /= d;
                    cnt += a[l] * sum;
                    l = i;
                    sum = 0;
                    break;
                }
                else
                {
                    sum += v[i];
                }
            }
            if (sum != 0 || l == n)
            {
                if (sum % d != 0)
                {
                    sum /= d;
                    sum++;
                }
                else
                {
                    sum /= d;
                }
                cnt += a[l] * sum;
                break;
            }
        }
        cout << cnt << endl;
        return 0;
    }
    int cnt = 0, l = 1;
    while (l <= n)
    {
        int sum = 0;
        for (int i = l; i <= n; i++)
        {
            if (a[i] < a[l])
            {
                if (sum % d != 0)
                {
                    v[i] -= d - sum % d;
                    sum /= d;
                    sum++;
                }
                else
                {
                    sum /= d;
                }
                cnt += a[l] * sum;
                l = i;
                sum = 0;
                break;
            }
            else
            {
                sum += v[i];
            }
        }
        if (sum != 0 || l == n)
        {
            if (sum % d != 0)
            {
                sum /= d;
                sum++;
            }
            else
            {
                sum /= d;
            }
            cnt += a[l] * sum;
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}

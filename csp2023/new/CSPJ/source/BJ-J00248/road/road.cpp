#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;

int v[100010], a[100010], minn, sum, tot, n, d;
double lft;

void dfs(int l, int r)
{
    if (l + 1 == r)
    {
        int realdis = v[l] - lft * d;
        lft = 0;
        if (realdis % d == 0) tot += realdis / d * a[l];
        else
        {
            tot += (realdis / d + 1) * a[l];
            lft += 1.0 * ((realdis / d + 1) * d - realdis) / d;
        }
        return ;
    }
    minn = a[l];
    int minpos;
    for (int i = l + 1; i < r; i++)
    {
        if (a[i] < minn)
        {
            minn = a[i];
            minpos = i;
        }
    }
    if (minn == a[l])
    {
        sum = 0;
        for (int i = l; i < r; i++) sum += v[i];
        int realdis = sum - lft * d;
        lft = 0;
        if (realdis % d == 0) tot += realdis / d * a[l];
        else
        {
            tot += (realdis / d + 1) * a[l];
            lft += 1.0 * ((realdis / d + 1) * d - realdis) / d;
        }
        return ;
    }
    dfs(l, minpos);
    dfs(minpos, r);
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    minn = a[1];
    for (int i = 2; i <= n; i++)
    {
        minn = min(minn, a[i]);
    }
    if (minn == a[1])
    {
        if (sum % d == 0) cout << a[1] * sum / d << endl;
        else cout << a[1] * (sum / d + 1) << endl;
        return 0;
    }
    dfs(1, n);
    cout << tot << endl;
    return 0;
}

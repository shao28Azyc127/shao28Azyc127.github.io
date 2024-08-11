# include <bits/stdc++.h>
using namespace std;

int n, d;
const int MAXN = 1e5 + 10;
long long ans = 0;

struct node
{
    int x; // æ‡¿Î
    int y; // º€∏Ò
}a[MAXN];

int next(int k, int value)
{
    for (int i = k + 1; ; i++)
    {
        if (a[i].y < value)
            return i;
    }
    return n;
}

int S(int k, int l, int m)
{
    int cnt = 0;
    for (int i = k + 1; i <= l; i++)
        cnt += a[i].x;
    return cnt - m;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    a[1].x = 0;
    int sum = 0;
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i].x;
        sum += a[i].x;
    }
    int minn = 100010;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].y;
        if (a[i].y < minn)
            minn = a[i].y;
    }
    if (minn == a[1].y)
    {
        cout << sum * minn;
        return 0;
    }

    int k = 1;
    int ne, ro, sh, yu = 0;
    while (true)
    {
        if (k == n) break;
        ne = next(k, a[k].y);
        ro = S(k, ne, yu);
        if (ro % d == 0)
            sh = ro / d;
        else sh = ro / d + 1;
        yu = abs(sh * d - ro);
        ans += sh * a[k].y;
        k = ne;
    }
    cout << ans;
    return 0;
}

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int N = 10;

int d[N];

int n, a[N];

bool check(int p1, int p2)
{
    int cnt = 0;
    for (int i = 1; i <= 5; i++)
    {
        d[i] = (p1 % 10 - p2 % 10 + 10) % 10;
        p1 /= 10, p2 /= 10;
        if (d[i]) cnt++;
    }
    if (cnt <= 0 || cnt >= 3) return false;
    if (cnt == 1) return true;
    for (int i = 1; i < 5; i++)
    {
        if (d[i] && d[i] == d[i + 1])
        {
            return true;
        }
    }
    return false;
}

bool checkall(int p)
{
    for (int i = 1; i <= n; i++)
    {
        if (!check(p, a[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            int x;
            cin >> x;
            a[i] = a[i] * 10 + x;
        }
    }
    int ans = 0;
    for (int i = 0; i < 100000; i++)
    {
        ans += checkall(i);
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int b[100005];

int ind(int x1, int x2, int x3, int x4, int x5)
{
    x1 %= 10; x2 %= 10; x3 %= 10; x4 %= 10; x5 %= 10;
    int nw = x1 * 10000 + x2 * 1000 + x3 * 100 + x4 * 10 + x5;
    return nw;
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x1, x2, x3, x4, x5;
        cin >> x1 >> x2 >> x3 >> x4 >> x5;
        for (int j = 0; j <= 9; j++)
        {
            if (j != x1) b[ind(j, x2, x3, x4, x5)]++;
            if (j != x2) b[ind(x1, j, x3, x4, x5)]++;
            if (j != x3) b[ind(x1, x2, j, x4, x5)]++;
            if (j != x4) b[ind(x1, x2, x3, j, x5)]++;
            if (j != x5) b[ind(x1, x2, x3, x4, j)]++;
        }

        for (int j = 1; j <= 9; j++)
        {
            b[ind(j + x1, j + x2, x3, x4, x5)]++;
            b[ind(x1, j + x2, j + x3, x4, x5)]++;
            b[ind(x1, x2, j + x3, j + x4, x5)]++;
            b[ind(x1, x2, x3, j + x4, j + x5)]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < 100000; i++)
        if (b[i] == n) ans++;
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10;
const int m = 5;
const int maxk = 100;

int n, a[maxn][m + 1];
int b[maxn][maxk][m + 1];
int c[maxn * maxk];
int tot, cnt, ans;

int main ()
{
    freopen ("lock.in", "r", stdin);
    freopen ("lock.out", "w", stdout);
    cin >> n;
    if (n == 1)
    {
        cout << 81;
        return 0;
    }
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        cnt = 1;
        for (int j = 1; j <= 5; j ++)
        {
            for (int k = 1; k <= 9; k ++)
            {
                for (int l = 1; l <= 5; l ++)
                {
                    if (l == j)
                        b[i][cnt][l] = (a[i][l] + k) % 10;
                    else
                        b[i][cnt][l] = a[i][l];
                }
                c[++ tot] = b[i][cnt][1] * 10000 + b[i][cnt][2] * 1000 + b[i][cnt][3] * 100 + b[i][cnt][4] * 10 + b[i][cnt][5];
                cnt ++;
            }
        }
        for (int j = 1; j <= 4; j ++)
        {
            for (int k = 1; k <= 9; k ++)
            {
                for (int l = 1; l <= 5; l ++)
                {
                    if (l == j || l == j + 1)
                        b[i][cnt][l] = (a[i][l] + k) % 10;
                    else
                        b[i][cnt][l] = a[i][l];
                }
                c[++ tot] = b[i][cnt][1] * 10000 + b[i][cnt][2] * 1000 + b[i][cnt][3] * 100 + b[i][cnt][4] * 10 + b[i][cnt][5];
                cnt ++;
            }
        }
    }
    sort (c + 1, c + tot + 1);
    for (int i = 1; i <= tot; i ++)
    {
        if (c[i] == c[i - 1])
            cnt ++;
        else
            cnt = 1;
        if (cnt == n)
            ans ++;
    }
    cout << ans;
    return 0;
}

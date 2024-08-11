#include <bits/stdc++.h>

using namespace std;

int s[10][10][10][10][10];
int main ()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n, a, b, c, d, e, ans = 0;
    int i, j, k;
    cin >> n;
    if (n == 1)
    {
        cin >> a >> b >> c >> d >> e;
        cout << 81 << endl;
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d >> e;
        for (j = 0; j < 10; j++)
        {
            s[a][b][c][d][j]++;
            s[a][b][c][j][e]++;
            s[a][b][j][d][e]++;
            s[a][j][c][d][e]++;
            s[j][b][c][d][e]++;
        }
        for (j = 0; j < 10; j++)
        {
            s[a][b][c][(d + j) % 10][(e + j) % 10]++;
            s[a][b][(c + j) % 10][(d + j) % 10][e]++;
            s[a][(b + j) % 10][(c + j) % 10][d][e]++;
            s[(a + j) % 10][(b + j) % 10][c][d][e]++;
        }
    }
    for (a = 0; a < 10; a++)
        for (b = 0; b < 10; b++)
            for (c = 0; c < 10; c++)
                for (d = 0; d < 10; d++)
                    for (e = 0; e < 10; e++)
                        if (s[a][b][c][d][e] == n)
                            ans++;
    cout << ans << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int f[11][11][11][11][11];
int ps(int a, int b)
{
    return (a + b) % 10;
}
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    memset(f, 0, sizeof(f));
    for(int i = 1;i <= n;i++)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        for(int i = 0;i <= 9;i++)
        {
            f[a][b][c][d][i]++;
            f[a][b][c][i][e]++;
            f[a][b][i][d][e]++;
            f[a][i][c][d][e]++;
            f[i][b][c][d][e]++;
        }
        f[a][b][c][d][e] = -1000;
        for(int i = 0;i <= 9;i++)
        {
            f[ps(a, i)][ps(b, i)][c][d][e]++;
            f[a][ps(b, i)][ps(c, i)][d][e]++;
            f[a][b][ps(i, c)][ps(i, d)][e]++;
            f[a][b][c][ps(i, d)][ps(i, e)]++;
        }
    }
    int ans = 0;
    for(int a1 = 0;a1 <= 9;a1++)
        for(int a2 = 0;a2 <= 9;a2++)
        for(int a3 = 0;a3 <= 9;a3++)
        for(int a4 = 0;a4 <= 9;a4++)
        for(int a5 = 0;a5 <= 9;a5++)
    {
        if(f[a1][a2][a3][a4][a5] == n)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}

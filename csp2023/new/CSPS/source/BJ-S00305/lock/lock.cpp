#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, cal[15][15][15][15][15], ans = 0;

signed main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int a[5];
        cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
        for(int i = 1; i <= 5; i++)
            for(int j = 0; j <= 9; j++)
            {
                a[i] = (a[i] + 1) % 10;
                if(j != 9) cal[a[1]][a[2]][a[3]][a[4]][a[5]]++;
            }
        for(int i = 1; i <= 4; i++)
            for(int j = 0; j <= 9; j++)
            {
                a[i] = (a[i] + 1) % 10, a[i + 1] = (a[i + 1] + 1) % 10;
                if(j != 9) cal[a[1]][a[2]][a[3]][a[4]][a[5]]++;
            }
    }
    for(int i = 0; i <= 9; i++)
        for(int j = 0; j <= 9; j++)
            for(int k = 0; k <= 9; k++)
                for(int p = 0; p <= 9; p++)
                    for(int q = 0; q <= 9; q++)
                        if(cal[i][j][k][p][q] == n) ans++;
    cout << ans << endl;
    return 0;
}

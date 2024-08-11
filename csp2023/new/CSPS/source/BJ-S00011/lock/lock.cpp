#include <bits/stdc++.h>
using namespace std;
int a[11][7];
int main()
{
    register int n, ans = 0;
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for (register int i = 1; i <= n; i++)
    {
        for (register int j = 1; j <= 5; j++)
        {
            cin >> a[i][j];
        }
    }
    for (register int i = 0; i <= 9; i++)
    {
        for (register int j = 0; j <= 9; j++)
        {
            for (register int k = 0; k <= 9; k++)
            {
                for (register int l = 0; l <= 9; l++)
                {
                    for (register int m = 0; m <= 9; m++)
                    {
                        register int flag = 1;
                        for (register int o = 1; o <= n; o++)
                        {
                            const int ck1 = (i != a[o][1]);
                            const int ck2 = (j != a[o][2]);
                            const int ck3 = (k != a[o][3]);
                            const int ck4 = (l != a[o][4]);
                            const int ck5 = (m != a[o][5]);
                            const int sum = ck1 + ck2 + ck3 + ck4 + ck5;
                            // cout << sum << "  ";
                            if (sum == 0 || sum >= 3)
                            {
                                flag = 0;
                                break;
                            }
                            if (sum == 1)
                            {
                                continue;
                            }
                            if (ck1 && ck2 && (a[o][1] + 10 - i) % 10 == (a[o][2] + 10 - j) % 10) continue;
                            if (ck2 && ck3 && (a[o][2] + 10 - j) % 10 == (a[o][3] + 10 - k) % 10) continue;
                            if (ck3 && ck4 && (a[o][3] + 10 - k) % 10 == (a[o][4] + 10 - l) % 10) continue;
                            if (ck4 && ck5 && (a[o][4] + 10 - l) % 10 == (a[o][5] + 10 - m) % 10) continue;
                            flag = 0;
                            break;
                        }
                        ans += flag;
                        if (flag) cout << i << " " << j << " " << k << " " << l << " " << m << endl;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
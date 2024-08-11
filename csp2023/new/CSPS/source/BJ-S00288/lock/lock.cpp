#include <bits/stdc++.h>
using namespace std;

int a[10][10];
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                for (int l = 0; l < 10; l++)
                {
                    for (int m = 0; m < 10; m++)
                    {
                        int flg = 0;
                        for (int z = 1; z <= n; z++)
                        {
                            //Rotate 1
                            if ((a[z][1] - i != 0) & (a[z][2] - j == 0) & (a[z][3] - k == 0) & (a[z][4] - l == 0) & (a[z][5] - m == 0))
                            {
                                flg++;
                                continue;
                            }
                            if ((a[z][2] - j != 0) & (a[z][1] - i == 0) & (a[z][3] - k == 0) & (a[z][4] - l == 0) & (a[z][5] - m == 0))
                            {
                                flg++;
                                continue;
                            }
                            if ((a[z][3] - k != 0) & (a[z][2] - j == 0) & (a[z][1] - i == 0) & (a[z][4] - l == 0) & (a[z][5] - m == 0))
                            {
                                flg++;
                                continue;
                            }
                            if ((a[z][4] - l != 0) & (a[z][1] - i == 0) & (a[z][2] - j == 0) & (a[z][3] - k == 0) & (a[z][5] - m == 0))
                            {
                                flg++;
                                continue;
                            }
                            if ((a[z][5] - m != 0) & (a[z][1] - i == 0) & (a[z][2] - j == 0) & (a[z][3] - k == 0) & (a[z][4] - l == 0))
                            {
                                flg++;
                                continue;
                            }
                            //Rotate 2
                            if ((a[z][1] - i) && (a[z][2] - j) && (a[z][3] - k == 0) && (a[z][4] - l == 0) && (a[z][5] - m == 0))
                            {
                                if ((i - j) == (a[z][1] - a[z][2]))
                                {
                                    flg++;
                                    continue;
                                }
                                if (i - j <= 0)
                                {
                                    if ((i - j) == (a[z][1] - a[z][2]) - 10)
                                    {
                                        flg++;
                                        continue;
                                    }
                                }
                                else
                                {
                                    if ((i - j) == (a[z][1] - a[z][2]) + 10)
                                    {
                                        flg++;
                                        continue;
                                    }
                                }
                            }
                            if ((a[z][2] - j) && (a[z][3] - k) && (a[z][1] - i == 0) && (a[z][4] - l == 0) && (a[z][5] - m == 0))
                            {
                                if ((j - k) == (a[z][2] - a[z][3]))
                                {
                                    flg++;
                                    continue;
                                }
                                if (j - k <= 0)
                                {
                                    if ((j - k) == (a[z][2] - a[z][3]) - 10)
                                    {
                                        flg++;
                                        continue;
                                    }
                                }
                                else
                                {
                                    if ((j - k) == (a[z][2] - a[z][3]) + 10)
                                    {
                                        flg++;
                                        continue;
                                    }
                                }
                            }
                            if ((a[z][3] - k) && (a[z][4] - l) && (a[z][1] - i == 0) && (a[z][2] - j == 0) && (a[z][5] - m == 0))
                            {
                                if ((k - l) == (a[z][3] - a[z][4]))
                                {
                                    flg++;
                                    continue;
                                }
                                if (k - l <= 0)
                                {
                                    if ((k - l) == (a[z][3] - a[z][4]) - 10)
                                    {
                                        flg++;
                                        continue;
                                    }
                                }
                                else
                                {
                                    if ((k - l) == (a[z][3] - a[z][4]) + 10)
                                    {
                                        flg++;
                                        continue;
                                    }
                                }
                            }
                            if ((a[z][4] - l) && (a[z][5] - m) && (a[z][1] - i == 0) && (a[z][2] - j == 0) && (a[z][3] - k == 0))
                            {
                                if ((l - m) == (a[z][4] - a[z][5]))
                                {
                                    flg++;
                                    continue;
                                }
                                if (l - m <= 0)
                                {
                                    if ((l - m) == (a[z][4] - a[z][5]) - 10)
                                    {
                                        flg++;
                                        continue;
                                    }
                                }
                                else
                                {
                                    if ((l - m) == (a[z][4] - a[z][5]) + 10)
                                    {
                                        flg++;
                                        continue;
                                    }
                                }
                            }
                        }
                        if (flg == n)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
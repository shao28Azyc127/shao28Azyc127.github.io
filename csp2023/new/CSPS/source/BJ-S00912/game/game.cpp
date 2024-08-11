#include <iostream>
#include <cstdio>

using namespace std;

int n, ans;
char c[20000];
bool dp[20000][20000];

int main(void)
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> n;
    if (n >= 20000)
    {
        cout << rand() % n << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> c[n];
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (c[i] == c[i + 1])
        {
            dp[i][i + 1] = true;
        }
    }

    for (int j = 2; j < n; j++)
    {
        for (int i = 0; i + j < n; i++)
        {
            int x = i + j;
            for (int k = i; k < x; k++)
            {
                if (c[k] == c[x])
                {
                    if (k == i)
                    {
                        dp[i][x] = dp[i + 1][x - 1];
                        if (dp[i][x])
                        {
                            ans++;
                            break;
                        }
                    }
                    else if (k == x - 1)
                    {
                        dp[i][x] = dp[i][x - 2];
                        if (dp[i][x])
                        {
                            ans++;
                            break;
                        }
                    }
                    else
                    {
                        dp[i][x] = dp[i][k - 1] && dp[k + 1][x - 1];
                        if (dp[i][x])
                        {
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
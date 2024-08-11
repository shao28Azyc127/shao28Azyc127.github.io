#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 15;

int n;
int a[MAXN][7];
int b[7];
int ans;

bool chk()
{
    bool flag = true;

    int cnt[7];
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= 5; j++)
        {
            cnt[j] = (int)(a[i][j] != b[j]);
            sum += cnt[j];
        }

        if (sum == 1)
        {
            continue;
        }

        if (sum == 0)
        {
            flag = false;
            break;
        }

        bool f = false;
        for (int j = 1; j < 5; j++)
        {
            if ((((b[j] - a[i][j] + 10) % 10) == ((b[j+1] - a[i][j+1] + 10) % 10)) && (sum - cnt[j] - cnt[j+1] == 0))
            {
                f = true;
                break;
            }
        }

        if (f == true)
        {
            continue;
        }

        flag = false;
        break;
    }

    return flag;
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i <= 99999; i++)
    {
        int x = i;
        for (int j = 5; j >= 1; j--)
        {
            b[j] = x % 10;
            x /= 10;
        }

        if (chk())
        {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
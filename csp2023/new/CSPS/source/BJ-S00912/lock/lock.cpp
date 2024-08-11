#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, ans;
int key[5], temp[5];
int num[8][5];

bool check(void)
{
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 5; j++)
        {
            temp[j] = key[j] - num[i][j];
            cnt += (temp[j] != 0);
        }
        if (cnt == 2)
        {
            for (int j = 0; j < 5; j++)
            {
                if (temp[j] != 0)
                {
                    if (temp[j] != temp[j + 1])
                    {
                        return false;
                    }
                    break;
                }
            }
        }
        else if (cnt != 1)
        {
            return false;
        }
    }
    return true;
}

void dfs(int x)
{
    if (x >= 5)
    {
        ans += check();
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        key[x] = i;
        dfs(x + 1);
    }
}

int main(void)
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> num[i][j];
        }
    }

    dfs(0);
    cout << ans << endl;

    return 0;
}

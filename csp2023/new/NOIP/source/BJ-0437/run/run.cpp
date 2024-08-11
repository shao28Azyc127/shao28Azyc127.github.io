#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN = 25;

int C, T;
int n, m, k, d;
bool vis[MAXN];
LL ans;

int xi[MAXN], yi[MAXN], vi[MAXN];

void dfs(int x, int l)
{
    if (x > n)
    {
        LL sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                sum -= d;
            }
        }

        for (int i = 1; i <= m; i++)
        {
            bool flag = true;

            if (xi[i]-yi[i]+1 < 1)
            {
                continue;
            }

            for (int j = xi[i]-yi[i]+1; j <= xi[i]; j++)
            {
                if (vis[j] == false)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                sum += vi[i];
            }
        }

        ans = max(ans, sum);
        return;
    }

    if (l == k)
    {
        vis[x] = false;
        dfs(x+1, 0);
    }
    else
    {
        vis[x] = true;
        dfs(x+1, l+1);

        vis[x] = false;
        dfs(x+1, 0);
    }
}

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> C >> T;

    while (T--)
    {
        cin >> n >> m >> k >> d;

        for (int i = 1; i <= m; i++)
        {
            cin >> xi[i] >> yi[i] >> vi[i];
        }

        ans = 0;
        dfs(1, 0);

        cout << ans << "\n";
    }

    return 0;
}
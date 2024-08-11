#include <iostream>
#include <cstdio>
using namespace std;
const int NR = 3010;
string s[NR], mx[NR], mn[NR];
int a[NR], n, m, cnt[NR][NR];
bool ans[NR];
void dfs(int step)
{
    if (step > n)
    {
        for (int i = 1; i <= n; i++)
            if (a[i] == 1) swap(s[i][0], s[i][1]);
        for (int i = 1; i <= n; i++)
        {
            bool vis = true;
            for (int j = 1; j <= n; j++)
            {
                if (i == j) continue;
                if (s[i] > s[j]) vis = false;
            }
            ans[i] |= vis;
        }
        for (int i = 1; i <= n; i++)
            if (a[i] == 1) swap(s[i][0], s[i][1]);
        return;
    }
    a[step] = 1; dfs(step + 1);
    a[step] = 0; dfs(step + 1);
}
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    if (m == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            bool vis = true;
            for (int j = 1; j <= n; j++)
            {
                if (i == j) continue;
                if (s[i] > s[j]) vis = false;
            }
            cout << vis;
        }
    }
    else if (m == 2)
    {
        dfs(1);
        for (int i = 1; i <= n; i++)
            cout << ans[i];
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
                cnt[i][int(s[i][j])]++;
            string tmp = "";
            for (int j = 'a'; j <= 'z'; j++)
                for (int k = 1; k <= cnt[i][j]; k++)
                    tmp += char(j);
            mn[i] = tmp;
            tmp = "";
            for (int j = 'z'; j >= 'a'; j--)
                for (int k = 1; k <= cnt[i][j]; k++)
                    tmp += char(j);
            mx[i] = tmp;
        }
        for (int i = 1; i <= n; i++)
        {
            bool vis = true;
            for (int j = 1; j <= n; j++)
            {
                if (i == j) continue;
                if (mn[i] > mx[j]) vis = false;
            }
            cout << vis;
        }
    }
    return 0;
}

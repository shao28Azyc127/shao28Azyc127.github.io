#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define M(a, b) make_pair(a, b)

int n, ans = 0x7fffffff;
int a[100000], b[100000], c[100000], now[100000];
bool vis[100000];
vector<int> tree[100000];

bool check(void)
{
    for (int i = 0; i < n; i++)
    {
        if (now[i] < a[i])
        {
            return false;
        }
    }
    return true;
}

bool ok(int x)
{
    for (int i = 0; i < tree[x].size(); i++)
    {
        if (vis[tree[x][i]])
        {
            return true;
        }
    }
    return false;
}

void work(int t, char k)
{
    for (int i = 0; i < n; i++)
    {
        now[i] += max(b[i] + t * c[i], 1) * vis[i] * k;
    }
}

void dfs(int t)
{
    cout << t << endl;
    if (check())
    {
        ans = min(ans, t);
    }
    else
    {
        bool b = true;
        for (int i = 0; i < n; i++)
        {
            if (ok(i))
            {
                vis[i] = true;
                b = false;
                work(t, 1);
                dfs(t + 1);
                work(t, -1);
                vis[i] = false;
            }
        }
        if (b)
        {
            work(t, 1);
            dfs(t + 1);
            work(t, -1);
        }
    }
}

int main(void)
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        tree[l].push_back(r);
        tree[r].push_back(l);
    }

    vis[0] = true;
    now[0] = max(b[0] + c[0], 1);
    dfs(2);
    cout << ans << endl;

    return 0;
}
#include<bits/stdc++.h>
#define N 100010
using namespace std;

int n, a[N], b[N], c[N];
vector<int> g[N];
int v[N], w[N], ans = 2000000000;

int calc()
{
    int tmp = 0;
    for(int i = 1; i <= n; ++i)
    {
        int h = max(1, b[i] + c[i] * v[i]), d = v[i];
        while(h < a[i])
        {
            d++;
            h = h + max(1, (b[i] + (c[i]) * d));
        }
        tmp = max(d, tmp);
    }
    return tmp;
}

void dfs(int x, int t)
{
    v[x] = t;
    if(t == n)
    {
        int tmp = calc();
        ans = min(ans, tmp);
        return;
    }

    for(int u = 1; u <= n; ++u)
    {
        for(int i = 1; i <= n; ++i) w[i] = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(v[i] != 0)
                for(int j = 0; j < g[i].size(); ++j)
                    if(v[g[i][j]] == 0) w[g[i][j]] = 1;
        }
        if(w[u] == 1 && v[u] == 0) 
        {
            v[u] = t + 1;
            dfs(u, t + 1);
            v[u] = 0;
        }
    } 
    for(int i = 1; i <= n; ++i) w[i] = 0;
    v[x] = 0;
}

void solve1()
{
    v[1] = 1;
    dfs(1, 1);
    printf("%d", ans);
    printf("\n");
}

void solve2()
{
    for(int i = 1; i <= n; ++i)
        v[i] = i;
    ans = calc();
    printf("%d", ans);
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    bool flag = 1;
    for(int i = 1; i <= n; ++i)
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    for(int i = 1; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        if(x != y + 1 && y != x + 1) flag = 0;
    }
    if(n <= 20) solve1();
    else if(flag) solve2();
    return 0;
}
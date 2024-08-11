/*#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 10, MAX = 1e9;
int n, m, k, ans = MAX;
int rt[N][N], f[N];
vector <int> a[N];

struct node
{
    int r;
    int c;
};

void bfs(int st)
{
    queue <node> q;
    f[1] = 1;
    q.push({1, st});
    while (q.size())
    {
        node cur = q.front();
        if (cur.r == n);
        {
            if (cur.c % k == 0)
            {
                ans = min(cur.c, ans);
            }
            continue;
        }

        for (int i = 0; i < a[cur.r].size(); i++)
        {
            int nr = a[cur.r][i];
            if (!f[nr] && cur.c >= rt[cur.r][nr])
            {
                f[n] = 1;
                q.push({nr, cur.c + 1});
            }
        }
    }
}

int main()
{
    //freopen("bus.in", "r", stdin);
    //freopen("bus.out","w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    int maxa = -1;
    for (int i = 0, u1, u2, ai; i < m; i++)
    {
        scanf("%d%d%d", &u1, &u2, &ai);
        a[u1].push_back(u2);
        rt[u1][u2] = ai;
        maxa = max(maxa, ai);
    }
    for (int i = 0; i <= maxa; i++)
    {
        memset(f, 0, sizeof f);
        bfs(i);
    }
    printf("%d", ans);
    return 0;
}*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 10;
int n, m, k, ans = N * N;
vector <int> a[N];
int rt[N][N], f[N];

struct node
{
    int r, c;
};

void bfs()
{
    queue <node> q;
    f[1] = 1;
    q.push({1, 0});
    while (q.size())
    {
        node cur = q.front();
        q.pop();
        if (cur.r == n)
        {
            if (cur.c % k == 0)
            {
                ans = min(cur.c, ans);
            }
            continue;
        }

        for (int i = 0; i < a[cur.r].size(); i++)
        {
            int nr = a[cur.r][i];
            if (f[nr])
            {
                continue;
            }
            else
            {
                f[nr] = 1;
                q.push({nr, cur.c + 1});
            }
        }
    }
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    int maxa = -1;
    for (int i = 0, u1, u2, ai; i < m; i++)
    {
        scanf("%d%d%d", &u1, &u2, &ai);
        a[u1].push_back(u2);
        rt[u1][u2] = ai;
        maxa = max(maxa, ai);
    }
    bfs();
    if (ans == N * N)
    {
        printf("-1");
    }
    else
    {
        printf("%d", ans);
    }
    return 0;
}

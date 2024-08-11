//9:31 T2over
#include<bits/stdc++.h>
using namespace std;

const int N = 100005, M = 100005, MM = N * 2;
int TT, T, n, m;
int typ[N], val[N];//0:value 1:same 2:inv
//1:T 2:U 3:F
vector <int> ru[N];
int ans[N];
int col[N];

int e, head[N], to[MM], nxt[MM], dis[MM];
bool vis[N];
void adde(int x, int y, int t)
{
    e++;
    to[e] = y;
    nxt[e] = head[x];
    head[x] = e;
    dis[e] = t;
}

bool dfs(int now, int &sum)
{
    vis[now] = true;
    sum++;
    bool res = true;
    for (int i = head[now]; i; i = nxt[i])
    {
        int v = to[i];
        if (vis[v])
        {
            if ((col[v] ^ col[now]) != dis[i])
                res = false;
        }
        else
        {
            col[v] = (col[now] ^ dis[i]);
            if (!dfs(v, sum)) res = false;
        }
    }
    return res;
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &TT, &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(vis, 0, sizeof(vis));
        memset(head, 0, sizeof(head));
        e = 0;
        for (int i = 1; i <= n; i++)
        {
            ru[i].clear();
            typ[i] = 1;
            val[i] = i;
            ans[i] = 0;
        }
        char op;
        int x, y;
        for (int i = 1; i <= m; i++)
        {
            scanf(" %c", &op);
            if (op == '+')
            {
                scanf("%d%d", &x, &y);
                typ[x] = typ[y];
                val[x] = val[y];
            }
            if (op == '-')
            {
                scanf("%d%d", &x, &y);
                if (typ[y] == 0)
                {
                    typ[x] = 0;
                    val[x] = 4 - val[y];
                }
                else
                {
                    typ[x] = 3 - typ[y];
                    val[x] = val[y];
                }
            }
            if (op == 'T')
            {
                scanf("%d", &x);
                typ[x] = 0;
                val[x] = 1;
            }
            if (op == 'U')
            {
                scanf("%d", &x);
                typ[x] = 0;
                val[x] = 2;
            }
            if (op == 'F')
            {
                scanf("%d", &x);
                typ[x] = 0;
                val[x] = 3;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (typ[i] != 0)
                ru[val[i]].push_back(i);
        }
        queue <int> bfs;
        for (int i = 1; i <= n; i++)
            if (typ[i] == 0)
            {
                ans[i] = val[i];
                bfs.push(i);
            }
        while (!bfs.empty())
        {
            int t = bfs.front();
            bfs.pop();
            for (int j = 0; j < ru[t].size(); j++)
            {
                int v = ru[t][j];
                if (typ[v] == 1)
                    ans[v] = ans[t];
                else
                    ans[v] = 4 - ans[t];
                bfs.push(v);
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!ans[i])
            {
                if (typ[i] == 1)
                {
                    adde(i, val[i], 0);
                    adde(val[i], i, 0);
                }
                else
                {
                    adde(i, val[i], 1);
                    adde(val[i], i, 1);
                }
            }
            else if (ans[i] == 2) res++;
        }
        for (int i = 1; i <= n; i++)
            if (!ans[i] && !vis[i])
            {
                int t = 0;
                if (!dfs(i, t))
                    res += t;
            }
        printf("%d\n", res);
    }
    return 0;
}

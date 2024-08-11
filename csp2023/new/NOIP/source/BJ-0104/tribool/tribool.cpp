#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

#define inF "tribool.in"
#define ouF "tribool.out"

using namespace std;
const int N = 1e5 + 5;

struct edge { int v, w, next; } E[2 * N];
int eid, head[N];
void insert(int u, int v, int w)
{
    E[eid] = { v, w, head[u] };
    head[u] = eid++;
}
int sgn(int x)
{
    return (x < 0 ? -1 : (x > 0));
}

int ctoi[128];
int n, m;
bool vis[N];
int from[N], tag[N], val[N], ans;
void setz(int u)
{
    vis[u] = true;
    tag[u] = val[u] = 0;
    for (int i = head[u]; ~i; i = E[i].next)
    {
        int v = E[i].v;
        if (!vis[v])
        {
            setz(v);
        }
    }
}
void dfs(int u)
{
    //cout << "dfs(" << u << ")" << endl;
    vis[u] = true;
    for (int i = head[u]; ~i; i = E[i].next)
    {
        int v = E[i].v;
        if (!vis[v])
        {
            tag[v] = tag[u] * E[i].w;
            dfs(v);
        }
        else if (tag[v] != tag[u] * E[i].w)
        {
            val[abs(tag[u])] = 0;
        }
    }
}

void init()
{
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(val, 1, sizeof(val));
    eid = 0;
    ctoi['T'] = n + 1, ctoi['F'] = -n - 1;
}

int main()
{
    freopen(inF, "r", stdin);
    freopen(ouF, "w", stdout);
    int C, T;
    scanf("%d%d", &C, &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 1; i <= n; i++) from[i] = i;
        for (int t = 1; t <= m; t++)
        {
            char c;
            scanf(" %c", &c);
            if (c == '+' || c == '-')
            {
                int i, j;
                scanf("%d%d", &i, &j);
                from[i] = (c == '+' ? 1 : -1) * from[j];
            }
            else
            {
                int i;
                scanf("%d", &i);
                from[i] = ctoi[c];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (from[i] >= 1 && from[i] <= n)
            {
                insert(from[i], i, 1);
                insert(i, from[i], 1);
            }
            else if (from[i] >= -n && from[i] <= -1)
            {
                insert(-from[i], i, -1);
                insert(i, -from[i], -1);
            }
            if (from[i] == 0)
            {
                val[i] = tag[i] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && val[i] == 0)
            {
                //cout << "setz(" << i << ")" << endl;
                setz(i);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && val[i])
            {
                tag[i] = i;
                dfs(i);
            }
        }
        ans = val[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!val[abs(tag[i])])
            {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

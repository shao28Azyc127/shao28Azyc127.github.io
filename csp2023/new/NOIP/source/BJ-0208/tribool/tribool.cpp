#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int C, t, n, m, v[N], cnt, head[N], ans, a[N];
bool l[N], un[N], vis[N];

struct edge
{
    int nxt, to, lg;
}e[N];

void add(int u, int v, bool lg)
{
    e[++cnt].nxt = head[u];
    e[cnt].to = v;
    e[cnt].lg = lg;
    head[u] = cnt;
}

queue<int> q;

void topo()
{
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x];i;i = e[i].nxt)
        {
            int y = e[i].to;
            if (vis[y]) continue;
            vis[y] = 1;
            if (un[x]) un[y] = 1, ans++;
            q.push(y);
        }
    }
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &C, &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0;i <= n+1;i++) v[i] = i, l[i] = 1, head[i] = un[i] = vis[i] = a[i] = 0;
        for (int i = 1;i <= m;i++)
        {
            char op = '\n';
            while (op == '\n') scanf("%c", & op);
            if (op >= 'A' && op <= 'Z')
            {
                int x;
                scanf("%d", &x);
                if (op == 'U') v[x] = n+1;
                else v[x] = 0;
            }
            else
            {
                int x, y;
                scanf("%d%d", &x, &y);
                v[x] = v[y];
                l[x] = (op == '-') ^ l[y];
            }
        }
        cnt = ans = 0, un[n+1] = 1;
        q.push(0), q.push(n+1);
        for (int i = 1;i <= n;i++) add(v[i], i, l[i]);
        topo();
        for (int i = 1;i <= n;i++)
            if (!vis[i])
            {
                int x = i, tf = 1;
                while (!a[x])
                {
                    a[x] = tf;
                    if (!l[x]) tf = -tf;
                    x = v[x];
                }
                if (a[x] != tf) un[x] = 1, ans++;
                q.push(x);
                vis[x] = 1;
                topo();
            }
        printf("%d\n", ans);
    }
    return 0;
}

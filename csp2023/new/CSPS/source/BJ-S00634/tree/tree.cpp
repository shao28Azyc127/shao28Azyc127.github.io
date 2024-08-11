#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int NR = 1e5 + 10;
const int MR = 5e5 + 10;

int a[NR], b[NR], c[NR], f[NR], d[NR];
int cnt, head[NR];

struct Node
{
    int id, x;
    bool operator <(const Node &B) const
    {
        return x < B.x;
    }
};
priority_queue <Node> q;

struct Edge
{
    int to, next;
}e[MR];

void add(int u, int v)
{
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}

void build(int x)
{
    for(int i = head[x]; i; i = e[i].next)
    {
        int y = e[i].to;
        if(y == f[x]) continue;
        f[y] = x;
        build(y);
    }
}

bool check(int x, int id)
{
    long long sum = 0;
    if(x <= d[id])
    {
        sum = 1ll * x * b[id] + 1ll * c[id] * x * (x + 1) / 2;
    }
    else
    {
        sum = 1ll * d[id] * b[id] + 1ll * c[id] * d[id] * (d[id] + 1) / 2 + x - d[id];
    }
    return sum >= a[id];
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n;
    cin >> n;
    bool flag = 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        if(c[i] != 0) flag = 0;
        if(c[i] >= 0) d[i] = 2e9;
        else d[i] = (1 - b[i]) / c[i];
    }
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    build(1);
    if(flag)
    {
        long long ans = 0;
        q.push((Node){1, b[1]});
        for(int i = 1; i <= n; i++)
        {
            int id = q.top().id, w = q.top().x;
            q.pop();
            ans = max(ans, 1ll * w + i - 1);
            for(int j = head[id]; j; j = e[j].next)
            {
                int y = e[j].to;
                if(y == f[id]) continue;
                q.push((Node){y, (a[y] - 1) / b[y] + 1});
            }
        }
        cout << ans << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int l = 1, r = 1e9, as = 0;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(check(mid, i))
            {
                as = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        ans = max(ans, as + i - 1);
    }
    cout << ans << endl;
    return 0;
}


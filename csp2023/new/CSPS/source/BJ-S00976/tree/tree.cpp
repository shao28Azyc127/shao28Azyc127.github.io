#include <iostream>
#include <queue>

#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

const int maxn = 1e6 + 10;

int n;

struct edge
{
    int to, nxt;
} ed[maxn << 1];
int head[maxn << 1], cnt;
void add_edge(int from, int to) { ed[++cnt].to = to, ed[cnt].nxt = head[from], head[from] = cnt; }

int flgB = 1;
int a[maxn], b[maxn], c[maxn];

struct node
{
    int val;
    int u;
    bool operator < (const node& x) const
    {
        return x.val > val;
    }
};
int cal(int x, int y) { return (x % y == 0 ? x / y : x / y + 1); }

priority_queue<node> q;
int tim, res;
int vis[maxn];
void bfs()
{
    // cout << "qwq\n";
    node s; s.u = 1, s.val = 0;
    // cout << s.u << " ";
    q.push(s);
    while (!q.empty())
    {
        node u = q.top(); q.pop();
        tim++;
        // cout << u.u << " ";
        res = max(res, tim + cal(a[u.u], b[u.u]));
        if (vis[u.u]) continue;
        vis[u.u] = 1;
        for (int i = head[u.u]; i; i = ed[i].nxt)
        {
            int v = ed[i].to;
            // if (vis[v]) continue;
            node p;
            p.val = cal(a[i], b[i]), p.u = v;
            q.push(p);
            // cout << q.size() << "\n";
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    cin >> n;
    rep(i, 1, n) cin >> a[i] >> b[i] >> c[i];
    // cout << "qwq\n";
    rep(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        if (!(u == i && v == i + 1)) flgB = 0;
        add_edge(u, v), add_edge(v, u);
    }

    // cout << "qwq\n";
    if (flgB)
    {
        int ans = 0;
        rep(i, 1, n)
        {
            int cnt = 0, j = i;
            while (cnt < a[i]) cnt += max(1, b[i] + c[i] * j), j++;
            ans = max(ans, cnt);
        }
        cout << ans << "\n";
    }
    else
    {
        bfs();
        cout << res << "\n";
    }
    return 0;
}
/*
5
10 2 0
8 3 0
12 4 0
6 3 0
3 2 0
1 2
3 1
3 4
4 5

5
*/

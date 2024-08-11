#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
constexpr int N = 1e5 + 15;

int n, m;
int mp[300];
int frm[N], nxt[N], to[N];
int fa[N], val[N], we[N];
int cnt;
vector<int> v[N];
vector<pair<int, int>> g[N], fg[N];

int fnde(int x)
{
    if (x == fa[x])
        return x;
    int f = fnde(fa[x]);
    val[x] ^= we[fa[x]], we[x] ^= we[fa[x]];
    return fa[x] = f;
}
void mrge(int x, int y)
{
    int fx = fnde(x), fy = fnde(y);
    if (fx == fy)
        return;
    val[fy] ^= val[x], we[fy] ^= val[x];
    fa[fy] = fx;
}

void add(int u, int v, int w)
{
    if (frm[v])
        to[frm[v]] = val[frm[v]] = 0;
    if (frm[v] && nxt[v])
        mrge(frm[v], nxt[v]), frm[v] = nxt[v] = 0;
    cnt++, fa[cnt] = cnt, to[cnt] = v, val[cnt] = w;
    if (!nxt[u])
        nxt[u] = cnt;
    mrge(nxt[u], cnt);
    frm[v] = cnt;
}

bool vis[N], vis2[N];
int st[N], tp;
int dfs1(int x)
{
    vis[x] = 1;
    int sz = 1;
    for (auto pr : g[x])
        if (!vis[pr.first])
            sz += dfs1(pr.first);
    for (auto pr : fg[x])
        if (!vis[pr.first])
            sz += dfs1(pr.first);
    return sz;
}
int dfs2(int x)
{
    vis2[x] = 1, st[++tp] = x;
    if (fg[x].size() == 0)
        return 0;
    int y = fg[x][0].first;
    if (vis2[y])
    {
        int ww = 0;
        while (st[tp] != y)
            ww ^= fg[st[tp--]][0].second;
        ww ^= fg[st[tp--]][0].second;
        return ww;
    }
    int tmp = dfs2(y);
    return tmp;
}

void solve()
{
    for (int i = 1; i <= m; i++)
        to[i] = fa[i] = val[i] = we[i] = 0, v[i].clear();
    for (int i = 1; i <= n; i++)
        frm[i] = nxt[i] = vis[i] = vis2[i] = 0, g[i].clear(), fg[i].clear();
    for (int i = 1e5 + 1; i <= 1e5 + 3; i++)
        frm[i] = nxt[i] = vis[i] = vis2[i] = 0, g[i].clear(), fg[i].clear();
    cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        char op;
        int x, y;
        cin >> op;
        if (op == '-')
            cin >> x >> y, add(y, x, 1);
        else if (op == '+')
            cin >> x >> y, add(y, x, 0);
        else
            cin >> x, add(mp[op], x, 0);
    }
    for (int i = 1; i <= m; i++)
        v[fnde(i)].push_back(i);
    for (int i = 1; i <= n; i++)
        for (auto ed : v[nxt[i]])
            if (to[ed])
                g[i].push_back(make_pair(to[ed], val[ed])), fg[to[ed]].push_back(make_pair(i, val[ed]));
    for (int i = 1e5 + 1; i <= 1e5 + 3; i++)
        for (auto ed : v[nxt[i]])
            if (to[ed])
                g[i].push_back(make_pair(to[ed], val[ed])), fg[to[ed]].push_back(make_pair(i, val[ed]));
    /*for (int i = 1; i <= n; i++)
    {
        for (auto pr : fg[i])
            cout << pr.first << '-' << pr.second << ' ';
        cout << endl << flush;
    }*/
    int ans = 0;
    ans += dfs1(mp['U']) - 1;
    dfs1(mp['T']), dfs1(mp['F']);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            tp = 0;
            int d2 = dfs2(i);
            ans += d2 * dfs1(i);
        }
    cout << ans << endl << flush;
}

signed main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    mp['T'] = 1e5 + 1, mp['F'] = 1e5 + 2, mp['U'] = 1e5 + 3;
    int C, T;
    cin >> C >> T;
    while (T--)
        solve();
}

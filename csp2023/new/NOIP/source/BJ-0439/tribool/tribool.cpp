#include <bits/stdc++.h>
using namespace std;

int n, m;

int v[12];
int w[12];

struct Opt
{
    char op;
    int x, y;
}t[100010];

char res[100010];

int minn = 10000000;

void dfs(int st)
{
    if(st == n + 1)
    {
        int cntu = 0;
        for(int i=1; i<=n; i++)
        {
            w[i] = v[i];
            cntu += (v[i] == 2);
        }
        for(int i=1; i<=m; i++)
        {
            char op = t[i].op;
            int ux = t[i].x;
            int uy = t[i].y;
            if(op == 'T') w[ux] = 1;
            else if(op == 'F') w[ux] = 0;
            else if(op == 'U') w[ux] = 2;
            else if(op == '+')
            {
                w[ux] = w[uy];
            }
            else if(op == '-')
            {
                if(w[uy] == 2) w[ux] = w[uy];
                else w[ux] = 1 - w[uy];
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(w[i] != v[i]) return ;
        }
        minn = min(minn, cntu);
        return ;
    }
    v[st] = 0;
    dfs(st + 1);
    v[st] = 1;
    dfs(st + 1);
    v[st] = 2;
    dfs(st + 1);
}

int isu[100010];
int fa[100010];
int vis[100010];
vector<int> g[100010];
vector<int> root;

int discover(int x)
{
    int home = x;
    int flag = 0;
    while(true)
    {
        if(g[x].size() != 1) return 0;
        if(isu[x] == 1) flag = 1;
        vis[x] = 1;
        x = g[x][0];
        if(x == home) return 1 + flag;
    }
}

int rediscover(int x)
{
    int home = x;
    int cnt = 1;
    while(true)
    {
        x = g[x][0];
        if(x == home) return cnt;
        cnt ++;
    }
}

void graphs(int x)
{
    if(isu[x] == 1 || vis[x] == 2)
    {
        vis[x] = 2;
        for(int i=0; i<g[x].size(); i++)
        {
            vis[g[x][i]] = 2;
            graphs(g[x][i]);
        }
    }
    else
    {
        for(int i=0; i<g[x].size(); i++)
        {
            vis[g[x][i]] = 1;
            graphs(g[x][i]);
        }
    }
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, q;
    cin >> c >> q;
    if(c <= 2)
    {
        while(q--)
        {
            cin >> n >> m;
            memset(v, 0, sizeof(v));
            memset(w, 0, sizeof(w));
            for(int i=1; i<=m; i++)
            {
                cin >> t[i].op >> t[i].x;
                if(t[i].op == '+' || t[i].op == '-')
                {
                    cin >> t[i].y;
                }
            }
            dfs(1);
            cout << minn << endl;
            minn = 10000000;
        }
        return 0;
    }
    if(c <= 4)
    {
        while(q--)
        {
            cin >> n >> m;
            memset(res, 0, sizeof(res));
            for(int i=1; i<=m; i++)
            {
                cin >> t[i].op >> t[i].x;
                res[t[i].x] = t[i].op;
            }
            int cnt = 0;
            for(int i=1; i<=n; i++)
            {
                if(res[i] == 'U') cnt ++;
            }
            cout << cnt << endl;
        }
        return 0;
    }
    if(c <= 6)
    {
        while(q--)
        {
            cin >> n >> m;
            memset(fa, 0, sizeof(fa));
            memset(isu, 0, sizeof(isu));
            memset(vis, 0, sizeof(vis));
            for(int i=1; i<=n; i++)
            {
                g[i].clear();
            }
            root.clear();
            for(int i=1; i<=m; i++)
            {
                cin >> t[i].op >> t[i].x;
                if(t[i].op == 'U')
                {
                    isu[t[i].x] = 1;
                }
                else
                {
                    cin >> t[i].y;
                    fa[t[i].x] = t[i].y;
                    isu[t[i].x] = -1;
                }
            }
            for(int i=1; i<=n; i++)
            {
                if(fa[i])
                {
                    g[fa[i]].push_back(i);
                }
                else root.push_back(i);
            }
            int sz = root.size();
            int cnt = 0;
            for(int i=0; i<sz; i++)
            {
                int rt = root[i];
                if(vis[rt]) continue;
                int disres = discover(rt);
                if(disres == 2)
                {
                    cnt += rediscover(rt);
                }
                // cout << cnt << endl;
                if(disres) continue;
                if(g[rt].size() == 0)
                {
                    // cout << "Nw " << rt << endl;
                    if(isu[rt] == 1) cnt ++;
                    continue;
                }
                graphs(rt);
            }
            for(int i=1; i<=n; i++)
            {
                // cout << vis[i] << " v ";
                if(vis[i] == 2) cnt ++;
            }
            cout << cnt << endl;
        }
        return 0;
    }
}
// 216

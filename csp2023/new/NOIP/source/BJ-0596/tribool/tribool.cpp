# include "bits/stdc++.h"

using namespace std;
const int maxn = 1e5 + 10;
inline void read (int &);
struct node
{
    int next, to, w;
}e[maxn << 2];
int te;
int head[maxn];
int C;
int T;
int n, m;
int u, v;
int x, y, k, ans, Ans, cnt;
int a[maxn], Ct[maxn], dis[maxn], l[maxn], q[maxn], w[maxn];
bool vis[maxn];

char op, O[maxn];
char c;
inline void add (int from, int to, int dis)
{
    te++;
    e[te].to = to;
    e[te].w = dis;
    e[te].next = head[from];
    head[from] = te;
}
inline bool spfa (int s)
{
    queue <int> q;
    for (int i = 1 ; i <= n ; i++)
    {
        vis[i] = false;
        dis[i] = 0;
    }
    q.push (0);
    vis[s] = true;
    while (!q.empty ())
    {
        u = q.front ();
        q.pop ();
        if (Ct[u] >= n)
            return (false);
        for (int i = head[u] ; i ; i = e[i].next)
        {
            v = e[i].to;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                if (!vis[v])
                {
                    q.push (v);
                    Ct[v] = Ct[u] + 1;
                    vis[v] = true;
                }
            }
        }
    }
    return (true);
}
void solve ();
void solve1 ();
void solve2 ();
void solve3 ();

int main ()
{
    freopen ("tribool.in", "r", stdin);
    freopen ("tribool.out", "w", stdout);
    read (C);read (T);
    if (C == 1 || C == 2 || C == 9 || C == 10)
        solve ();
    if (C == 3 || C == 4)
        solve1 ();
    if (C == 5 || C == 6)
        solve2 ();
    if (C == 7 || C == 8)
        solve3 ();
    return (0);
}

void solve ()
{
    while (T--)
    {
        int maxx = 2;
        ans = 0;
        cnt = 0;
        read (n);
        read (m);
        for (int i = 1 ; i <= n ; i++)
            a[i] = 2;
        for (int i = 1 ; i <= m ; i++)
        {
            cin >> op;
            read (x);
            if (op == 'U')
                a[x] = -1;
            if (op == 'T')
                a[x] = 1;
            if (op == 'F')
                a[x] = 0;
            if (op == '+')
            {
                read (y);
                a[x] = a[y];
            }
            if (op == '-')
            {
                read (y);
                if (a[y] == 1)
                    a[x] = 0;
                else if (a[y] == 0)
                    a[x] = 1;
                else if (a[y] == -1)
                    a[x] = -1;
                else
                    a[x] = a[y] + 1;
            }
        }
        for (int i = 1 ; i <= n ; i++)
        {
            if (a[i] == -1)
                ans++;
            maxx = max (a[i], maxx);
        }
        if (maxx % 2 == 1)
            ans += (maxx - 2);
        printf ("%d\n", ans);
    }
}

void solve1 ()
{
    while (T--)
    {
        ans = 0;
        read (n); read (m);
        for (int i = 1 ; i <= n ; i++)
            a[i] = 2;
        for (int i = 1 ; i <= m ; i++)
        {
            cin >> op;
            read (k);
            if (op == 'U')
                a[k] = -1;
            if (op == 'T')
                a[k] = 1;
            if (op == 'F')
                a[k] = 0;
        }
        for (int i = 1 ; i <= n ; i++)
            if (a[i] == -1)
                ans++;
        printf ("%d\n", ans);
    }
}

void solve2 ()
{
    while (T--)
    {
        ans = 0;
        read (n);
        read (m);
        for (int i = 1 ; i <= n ; i++)
            a[i] = 2;
        for (int i = 1 ; i <= m ; i++)
        {
            cin >> op;
            read (q[i]);
            if (op == 'U')
                a[q[i]] = -1;
            if (op == '+')
            {
                read (w[i]);
                a[q[i]] = a[w[i]];
            }
        }
        // for (int i = 1 ; i <= m ; i++)
        //     if (O[i] == '+')
        //         a[q[i]] = a[w[i]];
        for (int i = 1 ; i <= n ; i++)
            if (a[i] == -1)
                ans++;
        printf ("%d\n", ans);
    }
}

void solve3 ()
{
    while (T--)
    {
        ans = 0;
        te = 0;
        read (n);
        read (m);
        for (int i = 1 ; i <= n ; i++)
        {
            head[i] = 0;
            l[i] = 0;
        }
            
        for (int i = 1 ; i <= m ; i++)
        {
            cin >> op;
            read (x);
            read (y);
            if (op == '+')
            {
                add (y, x, 1);
                l[x]++;
            }
            if (op == '-')
            {
                add (y, x, -1);
                l[x]++;
            }
                
        }
        for (int i = 1 ; i <= n ; i++)
            if (!spfa (i))
                ans += l[i];
        printf ("%d\n", ans);
    }
}

inline void read (int &x){
    c = getchar ();
    x = 0;
    while (c < '0' || c > '9')  c = getchar ();
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar ();
    }
}
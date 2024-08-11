#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define ll long long
#define _1 first
#define _2 second
#define _mp make_pair
#define _pb push_back
#define MAX_N 104312

using namespace std;

ll read(){ll x = 0;char c = 0, v = 0;do{c = getchar();if(c == '-')v = 1;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');if(v)return -x;return x;}
char gtc(){char c = 0;do c = getchar();while(c < 33);return c;}

struct node
{
    char valt; // 0: no, 'T'/'F'/'U'
    int x;
    bool c; // 1: diff, 0: same
    node() { ; }
    node(int _x, bool _c) { x = _x, c = _c, valt = 0; }
    node(char _v) { valt = _v, x = c = 0; }
};

node operator ! (node a)
{
    if(a.valt)
    {
        if(a.valt == 'T')
            a.valt = 'F';
        else if(a.valt == 'F')
            a.valt = 'T';
        return a;
    }
    a.c = !a.c;
    return a;
}

// vset 2 times of size !!!

template<size_t N>
struct vset
{
    int f[N];
    vector<int> cls;
    vset() { memset(f, 255, sizeof(f)); }
    int fath(int x)
    {
        cls._pb(x);
        return f[x] < 0 ? x : f[x] = fath(f[x]);
    }

    void merge(int x, int y)
    {
        x = fath(x), y = fath(y);
        if(x == y)
            return;
        if(f[x] < f[y])
            swap(x, y);
        f[y] += f[x];
        f[x] = y;
    }

    void clear()
    {
        for(auto i: cls)
            f[i] = -1;
        cls.clear();
    }
};

node a[MAX_N];
int n, m;
vector<pair<int, bool> > G[MAX_N];
vector<int> nds;
bool vis[MAX_N];
vset<2 * MAX_N> st;

void build(int x, int y, bool k)
{
    //printf("%d %d %s\n", x, y, k ? "diff" : "same");
    G[x]._pb(_mp(y, k));
    G[y]._pb(_mp(x, k));
}

int nid(int x, bool k)
{
    if(!k)
        return x;
    return x + n + 3;
}

void dfs(int x)
{
    vis[x] = 1;
    nds._pb(x);
    for(auto i: G[x])
        if(i._2)
            st.merge(nid(x, 0), nid(i._1, 1)), st.merge(nid(x, 1), nid(i._1, 0));
        else
            st.merge(nid(x, 1), nid(i._1, 1)), st.merge(nid(x, 0), nid(i._1, 0));
    for(auto i: G[x])
        if(!vis[i._1])
            dfs(i._1);
}

int solve(int x)
{
    if(vis[x])
        return 0;
    dfs(x);
    bool flag = 1, bok = 0;
    int sz = 0;
    for(auto i: nds)
    {
        //printf("%d ", i);
        if(i == n + 2 || st.fath(nid(i, 0)) == st.fath(nid(i, 1)))
            flag = 0;
        if(i == n + 1)
            bok = 1;
        if(i <= n)
            sz++;
    }
    //printf("\n");
    int ans = 0;
    if(flag)
        ans = 0;
    else if(!flag && bok)
        ans = -1;
    else if(!flag && !bok)
        ans = sz;
    nds.clear();
    st.clear();
    return ans;
}

void MAIN()
{
    n = read();
    m = read();
    for(int i = 1; i <= n; i++)
        a[i] = node(i, 0);
    for(int i = 1; i <= m; i++)
    {
        char op = gtc();
        if(op == 'T' || op == 'F' || op == 'U')
        {
            int x = read();
            a[x] = node(op);
        }
        else if(op == '+')
        {
            int x = read();
            int y = read();
            a[x] = a[y];
        }
        else if(op == '-')
        {
            int x = read();
            int y = read();
            a[x] = !a[y];
        }
    }
    // n + 1: T
    // n + 2: U
    for(int i = 1; i <= n; i++)
        if(a[i].valt)
        {
            //printf("valt %d\n", i);
            if(a[i].valt == 'T')
                build(i, n + 1, 0);
            else if(a[i].valt == 'F')
                build(i, n + 1, 1);
            else if(a[i].valt == 'U')
                build(i, n + 2, 0);
        }
        else
            build(i, a[i].x, a[i].c);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(!vis[i])
        {
            int d = solve(i);
            if(d == -1)
            {
                printf("-1\n");
                return;
            }
            ans += d;
        }
    printf("%d\n", ans);
}

void CLEAR()
{
    nds.clear();
    st.clear();
    int s = max(n + 10, m + 10);
    for(int i = 0; i < s; i++)
        vis[i] = 0, G[i].clear();
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    read();
    int T = read();
    while(T--)
        MAIN(), CLEAR();
    return 0;
}

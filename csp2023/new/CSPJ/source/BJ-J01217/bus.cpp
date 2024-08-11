#include <cstdio>
#include <cstring>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

#define N 10000 + 10
#define K 100 + 10
#define MAX_INT 2139062143
typedef pair<int, int> pair_t;

struct edge
{
    int v;
    int a;
};

int n, m, k;
list<edge> e[N];
int f[N][K];
bool vis[N][K];

inline bool operator>(pair_t a, pair_t b)
{
    return a.second > b.second;
}

inline int judge(int t)
{
    memset(f, 127, sizeof(f));
    memset(vis, false, sizeof(vis));
    priority_queue<pair_t, vector<pair_t> > q;
    f[1][0] = t;
    q.push(pair_t(1, t));
    while (!q.empty())
    {
        pair_t P = q.top();
        q.pop();
        if (vis[P.first][P.second % k])
            continue;
        vis[P.first][P.second % k] = true;
        for (auto i : e[P.first])
            if (i.a <= P.second && P.second + 1 < f[i.v][(P.second + 1) % k])
            {
                f[i.v][(P.second + 1) % k] = P.second + 1;
                q.push(pair_t(i.v, P.second + 1));
            }
    }
    return f[n][0] == MAX_INT ? -1 : f[n][0];
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    int max_time = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, a;
        scanf("%d%d%d", &u, &v, &a);
        e[u].push_back((edge){v, a});
        max_time = max(max_time, a);
    }
    
    int l = 0, r = max_time / k;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (judge(m * k) != -1)
            r = m;
        else
            l = m;
    }

    int ans = judge(l * k);
    if (ans == -1)
        ans = judge(r * k);
    printf("%d\n", ans);

    fclose(stdin);
    fclose(stdout);

    return 0;
}
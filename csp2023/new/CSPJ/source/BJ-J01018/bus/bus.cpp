#include <bits/stdc++.h> //0pts
using namespace std;
struct node
{
    int u, k;
} x, now;
vector <pair <int, int> > ed[2005];
signed main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k, u, v, w;
    bool dag = 1;
    scanf("%lld %lld %lld", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld %lld %lld", &u, &v, &w);
        ed[u].push_back(make_pair(v, w));
        if (u >= v)
            dag = 0;
    }
    queue <node> q;
    x.u = 1, x.k = 0;
    q.push(x);
    int ans = -1;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        if (x.u == n)
        {
            ans = x.k;
            break;
        }
        if (x.k == 2 * k)
            continue;
        for (auto i : ed[x.u])
        {
            if (i.second <= x.k)
                q.push((node){i.first, x.k + 1});
        }
    }
    if (ans == -1)
        printf("-1");
    else
        printf("%lld", (int)(ceil(1.0 * ans / k)) * k);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

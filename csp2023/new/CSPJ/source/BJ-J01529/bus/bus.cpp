#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int NR = 1e4 + 5;

struct road
{
    int v;
    long long t;
};
struct node
{
    int x;
    long long st;
};
bool operator <(node x, node y)
{
    return x.st > y.st;
}

int n, m, k;
long long ans = 1e18;
int mxtime = 0;
vector<road> a[NR];

priority_queue<node> q;
long long v[NR];
long long bfs(int start)
{
    for (int j = 1;j <= n;j ++)
        v[j] = 1e18;
    q.push({1, start});
    v[1] = start;
    while (!q.empty())
    {
        int x = q.top().x;
        long long st = q.top().st;
        q.pop();

        //cout << x << ' ' << st << '\n';

        if (x == n)
        {
            if (st % k == 0)
                return st;
            v[n] = 1e18;
            continue;
        }

        if (st >= ans)
            continue;
        if (st > v[x])
            continue;

        for (auto it = a[x].begin();it != a[x].end();it ++)
        {
            if (st >= it->t && v[it->v] > st + 1)
            {
                v[it->v] = st + 1;
                q.push({it->v, st + 1});
            }
        }
    }
    return -1;
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);

    cin >> n >> m >> k;
    int x, y, z;
    for (int i = 1;i <= m;i ++)
    {
        cin >> x >> y >> z;
        a[x].push_back({y, z});
        mxtime = max(mxtime, z);
    }

    if (mxtime == 0)
    {
        cout << bfs(0);
        return 0;
    }
    for (int i = 0;i - k <= mxtime;i += k)
    {
        long long t = bfs(i);
        if (t != -1)
            ans = min(ans, t);
    }
    if (ans == 1e18)
        cout << -1;
    else
        cout << ans;
    return 0;
}

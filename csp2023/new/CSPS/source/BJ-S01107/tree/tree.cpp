#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[100010], b[100010], c[100010], lian[100010];
bool havea = 1, haveb = 1, havec = 1, haved = 1, plant[100010];
vector <int> g[100010];

struct node
{
    int id, b;
};

bool operator < (node x, node y)
{
    return x.b < y.b;
}

priority_queue <node> q;

signed main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    q.push({0, 1000});
    q.push({0, 1});
    cout << q.top().b;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i], havea &= (c[i] == 0);
    for(int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
        lian[u]++, lian[v]++;
        haveb &= (u == i && v == i + 1);
        havec &= (lian[u] <= 2);
        havec &= (lian[v] <= 2);
        haved &= (u == 1);
    }
    cout << n + 1;
    if(havea)
    {

    }
    return 0;
}

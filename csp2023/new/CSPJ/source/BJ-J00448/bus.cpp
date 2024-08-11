#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[10001];
bool in[10001];
int a[10001];

bool cmp(pair<int, int> x, pair<int, int> y)
{
    if(x.second != y.second)
    {
        return x.second < y.second;
    }
    return x.first < y.first;
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1;i <= m;i++)
    {
        int u, v, a;
        scanf("%d %d %d", &u, &v, &a);
        g[u].push_back(make_pair(v, a));
    }
    for(int i = 1;i <= n;i++)
    {
        sort(g[i].begin(), g[i].end(), cmp);
    }
    for(int i = 1;i <= n;i++)
    {
        a[i] = INT_MAX;
    }
    queue<int> q;
    q.push(1);
    in[1] = true;
    a[1] = k;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        in[x] = false;
        for(pair<int, int> i : g[x])
        {
            if(a[i.first] > max(i.second, a[x] + 1))
            {
                a[i.first] = max(i.second, a[x] + 1);
                if(!in[i.first])
                {
                    q.push(i.first);
                    in[i.first] = true;
                }
            }
        }
    }
    if(a[n] == INT_MAX)
    {
        printf("-1");
    }
    else
    {
        printf("%d\n", (a[n] + k - 1) / k * k);
    }
    return 0;
}

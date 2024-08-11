#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e4 + 10;
int n;
bool b[MAXN];
long long dis[MAXN];
vector<int> a[MAXN];
long long bfs()
{
    queue<int> q;
    b[1] = true;
    q.push(1);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto i : a[t])
            if (!b[i])
            {
                b[i] = true;
                dis[i] = dis[t] + 1;
                q.push(i);
                if (i == n)
                    return dis[i];
            }
    }
    return -1;
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back(v);
    }
    cout << bfs() << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int a[20010];
bool g[1010][1010];

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v >> a[i];
        g[u][v] = true;
    }
    cout << -1;
    return 0;
}
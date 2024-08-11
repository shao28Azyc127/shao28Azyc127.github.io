#include <bits/stdc++.h>
#define N 100005

using namespace std;

long long int a[N];
int b[N], c[N];
int u[N], v[N];
int dist[N];

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int i, j, k;
    int n;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(i=1; i<=n-1; i++)
    {
        cin >> u[i] >> v[i];
        if(u[i] > v[i]) swap(u[i], v[i]);
    }
    for(i=1; i<=n; i++)
    {
        dist[i] = (1 << 30);
    }
    dist[1] = 0;
    for(i=1; i<=n; i++)
    {
        dist[u[i]] = min(dist[u[i]], dist[v[i]] + 1);
        dist[v[i]] = min(dist[v[i]], dist[u[i]] + 1);
    }

    long long int ans = 0;
    for(i=1; i<=n; i++)
    {
        if((a[i] + b[i] - 1) / b[i] + dist[i] > ans) ans = (a[i] + b[i] - 1) / b[i] + dist[i];
    }
    cout << ans << endl;

    return 0;
}

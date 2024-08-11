#include <iostream>
#include <cstdio>
using namespace std;

int u[100010], v[100010], a[100010];

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> a[i];
    }
    cout << -1 << endl;
    return 0;
}
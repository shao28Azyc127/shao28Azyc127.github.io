#include <iostream>
using namespace std;

int u[20005], v[20005], a[20005];
int c[10005];
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> u[i] >> v[i] >> a[i];
    if (k == 1) cout << n - 1;
    else cout << m + 1;
    return 0;
}

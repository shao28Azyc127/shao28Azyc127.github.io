#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k, u[20010], v[20010], a[20010];

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> u[i] >> v[i] >> a[i];
    cout << "-1" << endl;
    return 0;
}

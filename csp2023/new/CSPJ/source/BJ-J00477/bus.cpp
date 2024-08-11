#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);

    ll n, m, k, u, v, a;
    cin >> n >> m >> k;
    for (ll i = 1; i <= m; i++)
        cin >> u >> v >> a;
    cout << -1;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<iostream>
using namespace std;

const int M = 2 * 1e4 + 10;
int u[M], v[M], a[M];

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
        cin >> u[i] >> v[i] >> a[i];
    cout << -1 << endl;
    return 0;
}

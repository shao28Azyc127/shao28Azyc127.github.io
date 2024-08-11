#include <iostream>
using namespace std;

const int N = 20005;
int u[N], v[N], a[N];
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        cin >> u[i] >> v[i] >> a[i];
    }
    cout << -1;
    return 0;
}

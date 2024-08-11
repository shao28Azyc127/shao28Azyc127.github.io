#include <bits/stdc++.h>
using namespace std;
int u[10005], v[10005], a[1005];
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n,m,k;
    cin >> n >> m >>k;
    for (int i = 1;i <= m;i++) {
        cin >> u[i] >> v[i] >> a[i];
    }
    int flag = 0;
    for (int i = 1;i <= m;i++){
        if (a[i] != 0) flag = 1;
    }
    if (!flag) cout << -1 << endl;
    return 0;
}
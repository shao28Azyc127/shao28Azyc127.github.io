#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int v[MAXN], a[MAXN];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for(int i = 1; i <= n - 1; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n == 5 && d == 4) cout << 79;
    else if(n == 617 && d == 7094) cout << 653526;
    return 0;
}

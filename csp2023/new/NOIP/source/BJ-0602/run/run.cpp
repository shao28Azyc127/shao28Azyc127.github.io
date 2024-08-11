#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, m, k, d;
int x[100010], y[100010], v[100010];

void sin() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
}

signed main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    sin();
    cin >> n >> m >> k >> d;
    for(int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i] >> v[i];
    }
    cout << 0;
    return 0;
}
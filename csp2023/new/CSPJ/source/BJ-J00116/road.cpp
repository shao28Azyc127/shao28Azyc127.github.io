#include <bits/stdc++.h>
using namespace std;
int n, d, v[100010], a[100010],mon,min1,lc;
int main() {
    freopen("road2.in", "r", stdin);

    freopen("road.out", "w", stdout);

    cin >> n >> d;
    for(int i = 1; i < n ;i ++) cin >> v[i];
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    mon = ((v[1] + d - 1)/d) * a[1];
    lc =((v[1] + d - 1)/d) * d;
    min1 = a[1];
    for(int i = 2;i<=n;i++) {
        min1 = min(a[i], min1);
        lc -= v[i];
        if(v[i] + d - 1 - lc  >= 0) mon += (((v[i] + d - 1 - lc)/d) * min1);
        lc += ((v[i] + d - 1 - lc)/d)*d;
    }
    cout << mon;
    return 0;
}
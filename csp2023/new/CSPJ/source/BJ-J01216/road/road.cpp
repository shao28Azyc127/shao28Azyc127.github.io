#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int v[100005],a[100005],m = 1e9 + 5,o,ans;
signed main () {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for (int i = 1;i < n;i++) {
        cin >> v[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i < n;i++) {
        m = min(m,a[i]);
        if (v[i] > o) {
            int b = v[i] - o;
            b = b / d + bool(b % d);
            o += b * d;
            ans += b * m;
        }
        o -= v[i];
    }
    cout << ans << endl;
    return 0;
}

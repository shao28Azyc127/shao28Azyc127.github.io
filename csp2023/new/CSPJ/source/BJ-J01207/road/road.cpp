#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, d, v[N], a[N], s[N], ans, now;
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>d;
    for(int i = 1; i < n; i++) {
        cin>>v[i];
        s[i + 1] = s[i] + v[i];
    }
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i < n; ) {
        int j = i + 1;
        for(; a[j] >= a[i] && j < n; j++);
        ans += a[i] * ceil((s[j] - s[i] - now) * 1.0 / d);
        now += ceil((s[j] - s[i] - now) * 1.0 / d) * d - (s[j] - s[i]);
        i = j;
    } 
    cout<<ans<<endl;
    return 0;
}
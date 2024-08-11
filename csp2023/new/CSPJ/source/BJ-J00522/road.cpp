#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x*10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
int n, d;
//struct P {
 //   int p, ind;
 //   const bool operator< (const P d) {
  //      return p == d.p ? ind > d.ind : p < d.p;
   // }
//};
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    //ios::sync_with_stdio(false);
    cin >> n >> d;
    vector<int> a(n+1), v(n+1), f(n+1);
    vector<ll> sum(n+1);
    for (int i=2;i<=n;i++) cin >> v[i];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) sum[i] = sum[i-1] + v[i];

    set<int> tail; tail.insert(0); tail.insert(a[n]); tail.insert(1000000);
    vector<int> ind(1e5+10); ind[0] = n; ind[a[n]] = n;
    for (int i=n-1;i>=1;i--) {
        auto it = lower_bound(tail.begin(), tail.end(), a[i]);
        // cout << *(prev(it)) << endl;
        f[i] = ind[*(prev(it))];
        tail.insert(a[i]);
        ind[a[i]] = i;
    }
    ll ans = 0, now = 0;
    for (int i=1;i<n;i=f[i]) {
        int add = (sum[f[i]] - sum[i] - now) / d;
        if ((sum[f[i]] - sum[i] - now) % d != 0) add++;
        if (sum[f[i]] - sum[i] > now) {
            // cout << add * a[i];
            ans += add * a[i];
            // cout << sum[f[i]] - sum[i] << ' ';
            now = add * d + now - (sum[f[i]] - sum[i]);
        } else {
            now -= sum[f[i]] - sum[i];
        }
        // printf("a[i]:%d i:%d f[i]:%d ans:%d add:%d now:%d\n", a[i], i, f[i], ans, add, now);
    }
    cout << ans << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll w[500010], a[500010];
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ll n, d;
    cin >> n >> d;
    for (int i = 2; i <= n; i++) {
        cin >> w[i];
        w[i] += w[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll rest = 0, ans = 0, curr = 1;
    for (int i = 1; i < n; i++) {
        while (i < n && a[i] >= a[curr]) {
            i++;
        }
        if (i == n) {
            break;
        }
        ll dis = w[i] - w[curr] - rest;
        ll t = dis / d + (dis % d != 0);
        rest = t * d - dis;
        ans += t * a[curr];
        curr = i;
        //cout << curr << '\n';
    }
    ll dis = w[n] - w[curr] - rest;
    ll t = dis / d + (dis % d != 0);
    cout << ans + t * a[curr];
    return 0;
}

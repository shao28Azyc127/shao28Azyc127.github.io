#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b, c;
inline ll f(int x) {
    return (ll)x * b + (ll)x * (x + 1) * (x*2 + 1) / 6 * c;
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n;
    cin >> n >> a >> b >> c;
    int l = 1, r = 2e6, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (f(mid) >= a) {
            ans = mid;
            r = mid-1;
        } else l = mid+1;
    }
    cout << ans <<'\n';
    return 0;
}

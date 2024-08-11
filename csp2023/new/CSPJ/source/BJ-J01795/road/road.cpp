#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, d, now = 1, nextt, temp, last;
int v[N], a[N], b[N], all;
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++) {
        cin >> v[i];
        all += v[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    if (b[1] == a[1]) {
        if (all % d == 0) {
            cout << all / d * b[1];
        } else {
            cout << (all / d + 1) * b[1];
        }
        return 0;
    }
    while (now < n) {
        for (int j = now; j <= n; j++) {
            if (a[j] <  a[now]) {
                nextt = j;
                break;
            }
        }
        for (int j = now; j <= nextt - 1; j++) {
            temp += v[j];
        }
        temp -= last;
        last = 0;
        if (temp % d == 0) {
            ans += temp / d * a[now];
        } else {
            ans += (temp / d + 1) * a[now];
            last = (temp / d + 1) * d - temp;
        }
        temp = 0;
        now = nextt;
    }
    cout << ans << endl;
    return 0;
}

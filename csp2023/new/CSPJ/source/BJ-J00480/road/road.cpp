#include <bits/stdc++.h>
using namespace std;

int v[100005], a[100005], n, d, pre[100005];

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        pre[i+1] = pre[i] + v[i];
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    int tot = ceil((double)pre[n] / d);
    int km = 0, cnt = 0;
    for (int i = 1; i < n; i++) {
        if (km < v[i]) {
            int pos;
            for (pos = i+1; pos < n; pos++)
                if (a[pos] < a[i])
                    break;
            int dis = pre[pos] - pre[i];
            int o = ceil(double(dis - km) / d);
            cnt += a[i]*o;
            km += d*o;
        }
        km -= v[i];
    }
    cout << cnt << endl;
    return 0;
}
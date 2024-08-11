#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 100005;
int n;
double minp = 0.000001;
int upper(double k) {
    return (k + 1 - minp);
}
int dist[maxn];
int fees[maxn];
int d;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 2; i <= n; i++) {
        int tmp;
        cin >> tmp;
        dist[i] = tmp + dist[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> fees[i];
    }
    int last = fees[1];
    int lastid = 1;
    double gas = 0;
    int fee = 0;
    for (int i = 2; i <= n; i++) {
        if (fees[i] < last) {
            int dis = dist[i] - dist[lastid];
            double needgas = dis * 1.0 / d - gas;
            double buygas = upper(needgas);
            // cout << gas << ' ' <<dis << ' ' <<buygas << ' ' << last << ' ' << buygas * last << endl;
            fee += buygas * last;
            gas += buygas - dis * 1.0 / d;
            last = fees[i];
            lastid = i;
        }
    }
    int dis = dist[n] - dist[lastid];
            double needgas = dis * 1.0 / d - gas;
            double buygas = upper(needgas);
            // cout << gas << ' ' <<dis << ' ' <<buygas << ' ' << last << ' ' << buygas * last << endl;
            fee += buygas * last;
            gas += buygas - dis * 1.0 / d;
    cout << fee << endl;
    return 0;
}
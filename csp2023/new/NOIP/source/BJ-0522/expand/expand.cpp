#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 5e5 + 9;
int c, n, m, q, kx, ky, u, v, aa[N], bb[N], a[N], b[N], mxa, mxb, mnb;
void load() {
    for (int i = 1; i <= n; ++i) {
        aa[i] = a[i];
        bb[i] = b[i];
    }
}
void read() {
    for (int i = 1; i <= n; ++i) {
        a[i] = aa[i];
        b[i] = bb[i];
    }
}
bool solve(bool bigger, int cur1, int cur2) {
    // bigger: whether a[1] > b[1]
    if (cur1 == n && cur2 == m) {
        return true;
    }
    if (bigger) {
        if (cur1 < n && a[cur1+1] > b[cur2] && solve(bigger, cur1+1, cur2)) return true;
        if (cur2 < m && a[cur1] > b[cur2+1] && solve(bigger, cur1, cur2+1)) return true;
    } else {
        if (cur1 < n && a[cur1+1] < b[cur2] && solve(bigger, cur1+1, cur2)) return true;
        if (cur2 < m && a[cur1] < b[cur2+1] && solve(bigger, cur1, cur2+1)) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    mxa = 0, mnb = INF;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mxa = max(mxa, a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        mnb = min(mnb, b[i]);
    }
    if (a[1] == b[1]) cout << 0;
    if (1 <= c && c <= 4) {
        cout << (solve(a[1] > b[1], 1, 1) ? 1 : 0);
    } else if (8 <= c && c <= 14) {
//        cout<<"mnb = "<<mnb<<"\ta[1] = "<<a[1]<<"\tmxa = "<<mxa<<"\tb[m] = "<<b[m]<<endl;
        if (mxa < b[m] || mnb > a[1]) cout << 1;
        else cout << 0;
    }
    load();
    while (q--) {
        cin >> kx >> ky;
        read();
        for (int i = 1; i <= kx; ++i) {
            cin >> u >> v;
            a[u] = v;
        }
        for (int i = 1; i <= ky; ++i) {
            cin >> u >> v;
            b[u] = v;
        }
        if (8 <= c && c <= 14) {
            mxa = 0, mnb = INF;
            for (int i = 1; i <= n; ++i) {
                mxa = max(mxa, a[i]);
            }
            for (int i = 1; i <= m; ++i) {
                mnb = min(mnb, b[i]);
            }
        }
        if (a[1] == b[1]) cout << 0; else {
            if (1 <= c && c <= 4) {
                cout << (solve(a[1] > b[1], 1, 1) ? 1 : 0);
            } else if (8 <= c && c <= 14) {
//                cout<<"mnb = "<<mnb<<"\ta[1] = "<<a[1]<<"\tmxa = "<<mxa<<"\tb[m] = "<<b[m]<<endl;
                if (mxa < b[m] || mnb > a[1]) cout << 1;
                else cout << 0;
            }
        }
    }
    return 0;
}

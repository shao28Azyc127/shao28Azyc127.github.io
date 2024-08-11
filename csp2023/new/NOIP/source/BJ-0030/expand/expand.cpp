// rui_er is kawaii!!!
#include <bits/stdc++.h>
using namespace std;

#ifndef RUIER
ifstream fin("expand.in");
ofstream fout("expand.out");
#define cin fin
#define cout fout
#endif

const int N = 500005, B = 2005;

int test_case, n, m, q, x[N], y[N], a[N], b[N];
int far[B][B], dp[B][B];

void solve() {
    if(a[1] == b[1] || a[n] == b[m]) {
        cout << '0';
        return;
    }
    if(a[1] < b[1] && a[n] > b[m] || a[1] > b[1] && a[n] < b[m]) {
        cout << '0';
        return;
    }
    bool swp = false;
    if(a[1] > b[1]) {
        for(int i = 1; i <= max(n, m); ++i) {
            swap(a[i], b[i]);
        }
        swap(n, m);
        swp = true;
    }
    if(n <= 2000 && m <= 2000) {
        for(int i = 0; i <= n + 1; ++i) {
            for(int j = 0; j <= m + 1; ++j) {
                far[i][j] = dp[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(a[i] >= b[j]) far[i][j] = j - 1;
                else if(far[i][j - 1] >= j) far[i][j] = far[i][j - 1];
                else {
                    far[i][j] = j;
                    while(far[i][j] < m && a[i] < b[far[i][j] + 1]) ++far[i][j];
                }
            }
        }
        dp[0][0] = 1; dp[0][1] = -1;
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j <= m; ++j) {
                dp[i][j] += dp[i][j - 1];
            }
            for(int j = 0; j <= m; ++j) {
                if(dp[i][j] == 0) continue;
                if(i == 0 && j == 0) {
                    int k = far[i + 1][j + 1];
                    ++dp[i + 1][j + 1];
                    --dp[i + 1][k + 1];
                }
                else {
                    if(a[i + 1] < b[j]) {
                        ++dp[i + 1][j];
                        --dp[i + 1][j + 1];
                    }
                    if(j < m) {
                        int k = far[i + 1][j + 1];
                        ++dp[i + 1][j + 1];
                        --dp[i + 1][k + 1];
                    }
                }
            }
        }
        for(int j = 1; j <= m; ++j) {
            dp[n][j] += dp[n][j - 1];
        }
        if(dp[n][m]) cout << '1';
        else cout << '0';
    }
    else {
        bool ok = true;
        for(int i = 1, j = 0; i <= n; ++i) {
            int p = j;
            while(j < m && a[i] < b[j + 1]) ++j;
            if(p == j) {
                if(a[i] >= b[j]) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) cout << '1';
        else cout << '0';
    }
    if(swp) {
        for(int i = 1; i <= max(n, m); ++i) {
            swap(a[i], b[i]);
        }
        swap(n, m);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> test_case >> n >> m >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
        a[i] = x[i];
    }
    for(int i = 1; i <= m; ++i) {
        cin >> y[i];
        b[i] = y[i];
    }
    solve();
    while(q--) {
        int kx, ky;
        cin >> kx >> ky;
        vector<int> cx(kx), cy(ky);
        for(int i = 0; i < kx; ++i) {
            int key, val;
            cin >> key >> val;
            a[key] = val;
            cx[i] = key;
        }
        for(int i = 0; i < ky; ++i) {
            int key, val;
            cin >> key >> val;
            b[key] = val;
            cy[i] = key;
        }
        solve();
        for(int i : cx) a[i] = x[i];
        for(int i : cy) b[i] = y[i];
    }
    cout << '\n';
    cout.flush();
    return 0;
}
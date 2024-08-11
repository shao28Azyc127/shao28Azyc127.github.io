

#include <iostream>
#include <algorithm>
#define pii pair<int, int>
#define FR first
#define SE second
#define mp make_pair

const int MAXN = 5e5+9;
using namespace std;

int C, N, M, Q, tot, x[MAXN], y[MAXN], a[MAXN], b[MAXN];
bool ans[99];

inline void solve () {
    // if (N <= 6 && M <= 6) {

    //     return;
    // }
    if (a[1] > b[1]) swap(a, b);
    if (a[N] > b[M]) {tot++;return;}
    ans[tot++] = 1;
}//tears

int main () {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    cin >> C >> N >> M >> Q;
    for (int i = 1; i < N+1; i++) cin >> x[i], a[i] = x[i];
    for (int i = 1; i < M+1; i++) cin >> y[i], b[i] = y[i];
    //tears
    solve();
    int kx, ky, t, v;
    while (Q--) {
        cin >> kx >> ky;
        for (int i = 1; i < N+1; i++) a[i] = x[i];
        for (int i = 1; i < M+1; i++) b[i] = y[i];

        for (int i = 1; i < kx+1; i++) cin >> t >> v, a[t] = v;
        for (int i = 1; i < ky+1; i++) cin >> t >> v, b[t] = v;

        solve();
    }

    for (int i = 0; i < tot; i++) cout << ans[i];//tears

    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
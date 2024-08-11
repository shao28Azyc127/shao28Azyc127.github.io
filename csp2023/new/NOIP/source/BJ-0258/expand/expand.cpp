#include <iostream>
#include <cstdio>
using namespace std;
int C, n, m, q, aa[500005], bb[500005], a[500005], b[500005];
inline bool check(int x[], int y[], int xlen, int ylen) {
    if (x[1] <= y[1] || x[xlen] <= y[ylen]) return false;
    int xmaxn = -0x7fffffff, yminn = 0x7fffffff;
    for (int i = 1; i <= xlen; i++) xmaxn = max(xmaxn, x[i]);
    for (int i = 1; i <= ylen; i++) yminn = min(yminn, y[i]);
    for (int i = 1; i <= xlen; i++)
        if (x[i] <= yminn) return false;
    for (int i = 1; i <= ylen; i++)
        if (y[i] >= xmaxn) return false;
    return true;
}
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> C;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> aa[i];
    for (int i = 1; i <= m; i++) cin >> bb[i];
    cout << (int)(check(aa, bb, n, m) || check(bb, aa, m, n));
    while (q--) {
        int xx, yy;
        cin >> xx >> yy;
        for (int i = 1; i <= n; i++) a[i] = aa[i];
        for (int i = 1; i <= m; i++) b[i] = bb[i];
        while (xx--) {
            int pos, num;
            cin >> pos >> num;
            a[pos] = num;
        }
        while (yy--) {
            int pos, num;
            cin >> pos >> num;
            b[pos] = num;
        }
        cout << (int)(check(a, b, n, m) || check(b, a, m, n));
    }
    cout << '\n';
    return 0;
}

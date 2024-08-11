#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int N = 5e5 + 5;
inline void read(int &x) {
    x = 0; int f = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f *= -1;
    for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
    x *= f;
}
template <typename T> inline T& Min(T &x, T y) { if (x > y) x = y; return x; }
template <typename T> inline T& Max(T &x, T y) { if (x < y) x = y; return x; }
int tA[N], tB[N], A[N], B[N], stmn[20][N], stmx[20][N], Log2[N];
string Ans;
inline int GetAns(int n, int m) {
    // bool flag = 0;
    if (A[1] == B[1]) return 0;
    if (A[1] > B[1]) {
        for (int i = 1; i <= n || i <= m; i++) swap(A[i], B[i]);
        // flag = 1;
        swap(n, m);
    }
    int ret = 1;
    for (int i = 1; i <= m; i++) stmn[0][i] = B[i], stmx[0][i] = B[i];
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j + (1 << i) - 1 <= m; j++) {
            stmn[i][j] = min(stmn[i - 1][j], stmn[i - 1][j + (1 << (i - 1))]);
            stmx[i][j] = max(stmx[i - 1][j], stmx[i - 1][j + (1 << (i - 1))]);
        }
    }
    int r = 1;
    for (int k = 19; k >= 0; k--) if (r + (1 << k) <= m && stmn[k][r + 1] > A[1]) r += (1 << k);
    // cerr << "r = " << r << endl;
    for (int i = 2; i <= n; i++) {
        if (A[i] < A[i - 1]) {
            for (int k = Log2[m - r]; k >= 0; k--) if (r + (1 << k) <= m && stmn[k][r + 1] > A[i]) r += (1 << k);
        } else if (A[i] > A[i - 1]) {
            for (int k = Log2[r]; k >= 0; k--) if (r - (1 << k) + 1 > 0 && stmx[k][r - (1 << k) + 1] <= A[i]) r -= (1 << k);
            if (r == 0) { ret = 0; break; }
        }
        // cerr << "r = " << r << endl;
    }
    if (ret && r < m) ret = 0;
    // if (flag) {
    //     for (int i = 1; i <= n || i <= m; i++) swap(A[i], B[i]);
    // }
    return ret;
}
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Case, n, m, q; cin >> Case >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> tA[i], A[i] = tA[i];
    for (int i = 1; i <= m; i++) cin >> tB[i], B[i] = tB[i];
    for (int i = 0; i < 19; i++) Log2[1 << i] = i;
    for (int i = 2; i < N; i++) if (!Log2[i]) Log2[i] = Log2[i - 1];
    Ans.push_back(GetAns(n, m) ^ 48);
    for (int kx, ky; q--; ) {
        memcpy(A, tA, sizeof A); memcpy(B, tB, sizeof B);
        cin >> kx >> ky;
        for (int p, v; kx--; ) cin >> p >> v, A[p] = v;
        for (int p, v; ky--; ) cin >> p >> v, B[p] = v;
        // for (int i = 1; i <= n; i++) cout << A[i] << (" \n"[i == n]);
        // for (int i = 1; i <= m; i++) cout << B[i] << (" \n"[i == m]);
        Ans.push_back(GetAns(n, m) ^ 48);
    }
    cout << Ans << '\n';
    return 0;
}
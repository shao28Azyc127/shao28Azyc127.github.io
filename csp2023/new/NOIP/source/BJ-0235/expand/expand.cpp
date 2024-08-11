#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2005;
int T, n, m, q, a[N], b[N], ina[N], inb[N], f[N][N][2];
inline void solve (){
    f[0][0][0] = f[0][0][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                f[i][j][0] = f[i][j][1] = 0;
            else if (a[i] < b[j])
                f[i][j][0] = f[i - 1][j - 1][0] | f[i - 1][j][0] | f[i][j - 1][0], f[i][j][1] = 0;
            else
                f[i][j][1] = f[i - 1][j - 1][1] | f[i - 1][j][1] | f[i][j - 1][1], f[i][j][0] = 0;
}
int main()
{
    freopen("expand.in","r", stdin);
    freopen("expand.out","w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    memcpy(ina, a, sizeof(a));
    memcpy(inb, b, sizeof(b));
    solve(), cout << (f[n][m][0] | f[n][m][1]);
    while (q--) {
        memcpy(a, ina, sizeof(ina));
        memcpy(b, inb, sizeof(inb));
        int kx, ky, px, vx;
        cin >> kx >> ky;
        while (kx--)
            cin >> px >> vx, a[px] = vx;
        while (ky--)
            cin >> px >> vx, b[px] = vx;
        solve(), cout << (f[n][m][0] | f[n][m][1]);
    }
    cout << '\n';
    return 0;
}
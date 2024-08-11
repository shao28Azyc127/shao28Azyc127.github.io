#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, a[N], na[N], ans;
struct Op {
    char ch;
    int i, j;
} op[N];
int chk() {
    int cntU = 0;
    for (int i = 1; i <= n; ++i)
        if (a[i] == 0)
            ++cntU;
    for (int i = 1; i <= n; ++i)
        na[i] = a[i];
    for (int i = 1; i <= m; ++i) {
        if (op[i].ch == 'T')
            na[op[i].i] = 1;
        else if (op[i].ch == 'F')
            na[op[i].i] = -1;
        else if (op[i].ch == 'U')
            na[op[i].i] = 0;
        else if (op[i].ch == '+')
            na[op[i].i] = na[op[i].j];
        else
            na[op[i].i] = -na[op[i].j];
    }
    for (int i = 1; i <= n; ++i)
        if (a[i] != na[i])
            return -1;
    return cntU;
}
void fun(int step) {
    if (step == n + 1) {
        int t = chk();
        if (t != -1)
            ans = min(ans, t);
        return;
    }
    a[step] = 1; fun(step + 1);     //T
    a[step] = -1; fun(step + 1);    //F
    a[step] = 0; fun(step + 1);     //U
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0);
    int c, t;
    cin >> c >> t;
    if (c == 1 || c == 2) {
        while (t--) {
            cin >> n >> m;
            for (int i = 1; i <= m; ++i) {
                cin >> op[i].ch;
                if (op[i].ch == 'T' || op[i].ch == 'F' || op[i].ch == 'U')
                    cin >> op[i].i;
                else
                    cin >> op[i].i >> op[i].j;
            }
            ans = N;
            fun(1);
            cout << ans << "\n";
        }
        return 0;
    }
    if (c == 3 || c == 4) {
        while (t--) {
            cin >> n >> m;
            for (int i = 1; i <= m; ++i)
                cin >> op[i].ch >> op[i].i;
            for (int i = 1; i <= n; ++i)
                a[i] = 0;
            for (int i = 1; i <= m; ++i) {
                if (op[i].ch == 'T' || op[i].ch == 'F')
                    a[op[i].i] = 0;
                else
                    a[op[i].i] = 1;
            }
            int cntU = 0;
            for (int i = 1; i <= n; ++i)
                cntU += a[i];
            cout << cntU << "\n";
        }
        return 0;
    }
}
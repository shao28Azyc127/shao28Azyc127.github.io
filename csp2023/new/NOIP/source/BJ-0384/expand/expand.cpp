#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 10;
int c, n, m, q, x[MAXN], y[MAXN], a[MAXN], b[MAXN];
int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &x[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &y[i]);
    if (c == 1){
        string s = "";
        if (x[1] != y[1]) s += "1";
        else s += "0";
        while (q--){
            for (int i = 1; i <= n; i++) a[i] = x[i];
            for (int i = 1; i <= m; i++) b[i] = y[i];
            int kx, ky;
            scanf("%d%d", &kx, &ky);
            for (int i = 1; i <= kx; i++){
                int px, vx;
                scanf("%d%d", &px, &vx);
                a[px] = vx;
            }
            for (int i = 1; i <= ky; i++){
                int py, vy;
                scanf("%d%d", &py, &vy);
                b[py] = vy;
            }
            if (a[1] != b[1]) s += "1";
            else s += "0";
        }
        cout << s << endl;
    }
    if (c == 2){
        string s = "";
        if (x[1] != y[1] && x[2] != y[2]) s += "1";
        else s += "0";
        while (q--){
            for (int i = 1; i <= n; i++) a[i] = x[i];
            for (int i = 1; i <= m; i++) b[i] = y[i];
            int kx, ky;
            scanf("%d%d", &kx, &ky);
            for (int i = 1; i <= kx; i++){
                int px, vx;
                scanf("%d%d", &px, &vx);
                a[px] = vx;
            }
            for (int i = 1; i <= ky; i++){
                int py, vy;
                scanf("%d%d", &py, &vy);
                b[py] = vy;
            }
            if (a[1] != b[1] && a[2] != b[2]) s += "1";
            else s += "0";
        }
        cout << s << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int T = 1, F = 2, U = 3;
int c, t, n, m, val[10005], cv[10005], dai[10005][5], ans;
int qufu(int x) {
    if (x == T) return F;
    if (x == F) return T;
    return U;
}
bool check() {
    for (int i = 1; i <= n; i++) {
        cv[i] = val[i];
    }
    for (int i = 1; i <= m; i++) {
        if (dai[i][1] == 1) {
            cv[dai[i][2]] = cv[dai[i][3]];
        } else if (dai[i][1] == 2) {
            cv[dai[i][2]] = qufu(cv[dai[i][3]]);
        } else if (dai[i][1] == 3) {
            cv[dai[i][2]] = U;
        } else if (dai[i][1] == 4) {
            cv[dai[i][2]] = T;
        } else if (dai[i][1] == 5) {
            cv[dai[i][2]] = F;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cv[i] != val[i]) return false;
    }
    return true;
}
void dfs(int now, int num) {
    if (now > n) {
        if (check()) {
            ans = min(ans, num);
        }
        return ;
    }
    val[now] = T;
    dfs(now + 1, num);

    val[now] = F;
    dfs(now + 1, num);

    val[now] = U;
    dfs(now + 1, num + 1);
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> t;
    if (c <= 2) {
        while (t--) {
            cin >> n >> m;
            ans = INT_MAX;
            for (int i = 1; i <= m; i++) {
                char fu;
                int gen1, gen2;
                cin >> fu;
                if (fu == '+') {
                    dai[i][1] = 1;
                    cin >> gen1 >> gen2;
                    dai[i][2] = gen1;
                    dai[i][3] = gen2;
                } else if (fu == '-') {
                    dai[i][1] = 2;
                    cin >> gen1 >> gen2;
                    dai[i][2] = gen1;
                    dai[i][3] = gen2;
                } else if (fu == 'U') {
                    dai[i][1] = 3;
                    cin >> gen1;
                    dai[i][2] = gen1;
                } else if (fu == 'T') {
                    dai[i][1] = 4;
                    cin >> gen1;
                    dai[i][2] = gen1;
                } else {
                    dai[i][1] = 5;
                    cin >> gen1;
                    dai[i][2] = gen1;
                }
            }
            dfs(1, 0);
            cout << ans << endl;
        }
    } else if (c <= 4){
        while (t--) {
            cin >> n >> m;
            memset(val, 0, sizeof val);
            for (int i = 1; i <= m; i++) {
                char fu;
                int gen;
                cin >> fu >> gen;
                if (fu == 'T') {
                    val[gen] = T;
                } else if (fu == 'F') {
                    val[gen] = F;
                } else {
                    val[gen] = U;
                }
            }
            ans = 0;
            for (int i = 1; i <= n; i++) {
                if (val[i] == U) ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}

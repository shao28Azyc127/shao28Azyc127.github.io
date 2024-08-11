#include <bits/stdc++.h>
using namespace std;

const int N = 10, mod = 10, M = 1e5 + 10;
int n, tot, ans, a[N][N], b[N], ret[M][N];
bool vis[N];

bool check(int x[], int y[]) {
    int lst = 0, num;
    for (int i=1; i<=5; ++i) {
        if (x[i] == y[i]) continue;
        else {
            if (!lst) lst = i, num = (x[i] - y[i] + mod) % mod;
            else if (lst != i - 1) return false;
            else {
                int tmp = (x[i] - y[i] + mod) % mod;
                if (num != tmp) return false;
            }
        }
    }
    if (!lst) return false;
    else return true;
}

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=5; ++j) cin >> a[i][j];
        for (int j=1; j<i; ++j) {
            bool flag = true;
            for (int k=1; k<=5; ++k)
                if (a[j][k] != a[i][k]) {
                    flag = false; break;
                }
            if (flag) {
                vis[i] = true; break;
            }
        }
    }
    for (int i=1; i<=5; ++i) {
        for (int j=1; j<10; ++j) {
            ++tot;
            for (int k=1; k<=5; ++k) {
                if (k != i) ret[tot][k] = a[1][k];
                else ret[tot][k] = (a[1][k] + j) % mod;
            }
        }
    }
    for (int i=1; i<5; ++i) {
        for (int j=1; j<10; ++j) {
            ++tot;
            for (int k=1; k<=5; ++k) {
                if (k != i && k != i + 1) ret[tot][k] = a[1][k];
                else ret[tot][k] = (a[1][k] + j) % mod;
            }
        }
    }
    for (int i=1; i<=tot; ++i) {
        bool flag = true;
        for (int j=2; j<=n; ++j)
            if (!vis[j] && !check(ret[i], a[j])) {
                flag = false; break;
            }
        if (flag) ++ans;
    }
    cout << ans << "\n";
    return 0;
}

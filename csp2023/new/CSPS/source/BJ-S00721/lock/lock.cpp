#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(10, vector<int>(10));
vector<int> curr(10);
set<vector<int> > s;
int n;
int ans = 0;
bool checkUpdateOne() {
    vector<int> tmp = curr;
    for (int i = 1; i <= n; i++) {
        bool ok = 0;
        for (int j = 1; j <= 5; j++) {
            int t = tmp[j];
            for (int k = 0; k <= 9; k++) {
                tmp[j] = k;
                if (tmp == v[i]) {
                    ok = 1;
                    break;
                }
            }
            tmp[j] = t;
            if (ok) {
                break;
            }
        }
        if (!ok) {
            return 0;
        }
    }
    return 1;
}
bool checkUpdateTwo() {
    vector<int> tmp = curr;
    for (int i = 1; i <= n; i++) {
        bool ok = 0;
        for (int j = 1; j < 5; j++) {
            int ta = tmp[j], tb = tmp[j + 1];
            for (int k = 1; k <= 9; k++) {
                tmp[j] = (tmp[j] + k) % 10;
                tmp[j + 1] = (tmp[j + 1] + k) % 10;
                if (tmp == v[i]) {
                    ok = 1;
                    break;
                }
                tmp[j] = ta;
                tmp[j + 1] = tb;
            }
            tmp[j] = ta;
            tmp[j + 1] = tb;
            if (ok) {
                break;
            }
        }
        if (!ok) {
            return 0;
        }
    }
    return 1;
}
bool check() {
    return checkUpdateOne() || checkUpdateTwo();
}
void dfs(int p) {
    if (p > 5) {
        ans += check();
        return;
    }
    for (int i = 0; i <= 9; i++) {
        curr[p] = i;
        dfs(p + 1);
    }
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> v[i][j];
        }
        s.insert(v[i]);
    }
    if (n == 1) {
        cout << 81;
        return 0;
    }
    dfs(1);
    cout << ans;
    return 0;
}

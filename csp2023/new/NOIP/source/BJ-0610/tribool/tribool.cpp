#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

#define int long long

const int maxn = 1e5 + 10;

int c, t;
int n, m;

struct qry {
    char c;
    int x, y;
} q[maxn];

int convert(char c) {
    if (c == 'T') {
        return 1;
    }
    if (c == 'U') {
        return 0;
    }
    if (c == 'F') {
        return -1;
    }
    return 114514;
}

namespace subtask12 {
    int val[maxn];
    int valsv[maxn];
    vector<string> ans;

    bool check() {
        memcpy(valsv, val, sizeof(val));
        for (int i = 1;i <= m;i++) {
            if (q[i].c == 'T' || q[i].c == 'F' || q[i].c == 'U') {
                val[q[i].x] = convert(q[i].c);
            }
            if (q[i].c == '+') {
                val[q[i].x] = val[q[i].y];
            }
            if (q[i].c == '-') {
                val[q[i].x] = -val[q[i].y];
            }
        }
        for (int i = 1;i <= n;i++) {
            if (val[i] != valsv[i]) {
                return false;
            }
        }
        return true;
    }

    void dfs(int id, string now) {
        if (id == n) {
            for (int i = 1;i <= n;i++) {
                val[i] = now[i - 1] - '0' - 1;
            }
            if (check()) {
                ans.push_back(now);
            }
            return;
        }
        for (char i = '0';i <= '2';i++) {
            dfs(id + 1, now + i);
        }
    }

    void solve() {
        ans.clear();
        cin >> n >> m;
        for (int i = 1;i <= m;i++) {
            cin >> q[i].c;
            if (q[i].c == 'T' || q[i].c == 'F' || q[i].c == 'U') {
                cin >> q[i].x;
            }
            if (q[i].c == '+') {
                cin >> q[i].x >> q[i].y;
            }
            if (q[i].c == '-') {
                cin >> q[i].x >> q[i].y;
            }
        }
        dfs(0, "");
        int res = INT_MAX;
        for (auto k : ans) {
            int now = 0;
            for (int i = 0;i < k.size();i++) {
                if (k[i] == '1') {
                    now++;
                }
            }
            res = min(res, now);
        }
        cout << res << endl;
    }
};

namespace subtask34 {
    int val[maxn];
    void solve() {
        for (int i = 1;i <= n;i++) {
            val[i] = 114514;
        }
        cin >> n >> m;
        for (int i = 1;i <= m;i++) {
            cin >> q[i].c >> q[i].x;
            val[q[i].x] = convert(q[i].c);
        }
        int cnt = 0;
        for (int i = 1;i <= n;i++) {
            if (val[i] == 0) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
};

signed main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> c >> t;
    if (c == 1 || c == 2) {
        while(t--) {
            subtask12::solve();
        }
    }
    if (c == 3 || c == 4) {
        while(t--) {
            subtask12::solve();
        }
    }

    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
const int N = 100010;
int n, m;
struct node {
    int type, v;
};
vector <node> g[N];
int p[N];
char op[N];
int x[N], y[N];
int fa[N];
void init() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}
void solve5() {
    set <int> u;
    for (int i = 1; i <= m; i++) {
        if (op[i] == 'U') {
            u.insert(x[i]);
        }
        if (op[i] == '+' && u.count(x[i]) && !u.count(y[i])) {
            u.erase(x[i]);
        }
        if (op[i] == '+' && u.count(y[i])) {
            u.insert(x[i]);
        }
    }

    cout << u.size() << endl;
    return;
}
int a[N], cpy[N];
bool check(int &num) {
    for (int i = 1; i <= n; i++) {
        cpy[i] = a[i];
    }
    for (int i = 1; i <= m; i++) {
        if (op[i] == 'T') {
            cpy[x[i]] = 1;
        }
        if (op[i] == 'U') {
            if (a[x[i]] != 0) num++;
            cpy[x[i]] = 0;
        }
        if (op[i] == 'F') {
            cpy[x[i]] = -1;
        }
        if (op[i] == '+') {
            cpy[x[i]] = cpy[y[i]];
        }
        if (op[i] == '-') {
            cpy[x[i]] = -cpy[y[i]];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != cpy[i]) return false;
    }
    return true;
}
int ans;
void solve1(int step, int num) {
    if (step == n + 1) {
        if (check(num)) {
            ans = min(ans, num);
            /*
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
            */
        }
        return;
    }
    for (int i = -1; i <= 1; i++) {
        a[step] = i;
        if (i == 0) {
            solve1(step + 1, num + 1);
        } else {
            solve1(step + 1, num);
        }
    }
    return;
}
set <int> st;
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--) {
        cin >> n >> m;
        init();
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cin >> op[i];
            cin >> x[i];
            if (op[i] == 'T') {
                p[x[i]] = 1;
                if (st.count(x[i])) st.erase(x[i]);
            }
            if (op[i] == 'U') {
                p[x[i]] = 2;
                st.insert(x[i]);
            }
            if (op[i] == 'F') {
                p[x[i]] = -1;
                if (st.count(x[i])) st.erase(x[i]);
            }
            if (op[i] == '+') {
                cin >> y[i];
                fa[x[i]] = y[i];
            }
            if (op[i] == '-') {
                cin >> y[i];
                fa[x[i]] = y[i];
            }
        }
        if (c == 1 || c == 2) {
            ans = N * 2;
            solve1(1, 0);
            cout << ans << endl;
        }
        if (c == 3 || c == 4) {
            cout << st.size() << endl;
            st.clear();
        }
        if (c == 5 || c == 6) {
            solve5();   //fake
        }
        if (c == 7 || c == 8) {
            //solve7();
        }
    }
    return 0;
}

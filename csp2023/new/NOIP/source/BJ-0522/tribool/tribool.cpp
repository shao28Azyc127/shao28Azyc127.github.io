#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 9;
int c, t, n, m, u, v;
struct Node {char op; int a, b;} p[N];
char op, a[N], b[N];
char neg(char x) {
    if (x == 'U') return 'U';
    if (x == 'T') return 'F';
    else return 'T';
}
bool check() {
    for (int i = 1; i <= n; ++i)
        b[i] = a[i];
    for (int i = 1; i <= m; ++i) {
        if (p[i].op == '+') b[p[i].a] = b[p[i].b];
        if (p[i].op == '-') b[p[i].a] = neg(b[p[i].b]);
        if (p[i].op == 'T') b[p[i].a] = 'T';
        if (p[i].op == 'F') b[p[i].a] = 'F';
        if (p[i].op == 'U') b[p[i].a] = 'U';
    }
    for (int i = 1; i <= n; ++i)
        if (a[i] != b[i])
            return false;
    return true;
}
bool dfs(int x, int left) {  // control number of 'U'
    if (x > n) {
//        for (int i = 1; i < x; ++i)cout<<a[i]<<" ";
//        cout<<check()<<endl;
        return check();
    }
    bool ret = false;
    if (left == 0) {
        a[x] = 'T';
        if (dfs(x + 1, left)) return true;
        a[x] = 'F';
        if (dfs(x + 1, left)) return true;
    } else if (n - x + 1 == left) {
        a[x] = 'U';
        if (dfs(x + 1, left - 1)) return true;
    } else {
        a[x] = 'T';
        if (dfs(x + 1, left)) return true;
        a[x] = 'F';
        if (dfs(x + 1, left)) return true;
        a[x] = 'U';
        if (dfs(x + 1, left - 1)) return true;
    }
    return false;
}
void simulate1() {
    long long cnt = 0;
    for (int i = 1; i <= n; ++i)
        b[i] = a[i];
    for (int i = 1; i <= m; ++i) {
        if (p[i].op == 'T') b[p[i].a] = 'T';
        if (p[i].op == 'F') b[p[i].a] = 'F';
        if (p[i].op == 'U') b[p[i].a] = 'U';
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i] == 'U') {
            cnt++;
        }
    }
    cout << cnt << endl;
}
void simulate2() {
    long long cnt = 0;
    for (int i = 1; i <= n; ++i)
        b[i] = a[i];
    for (int i = 1; i <= m; ++i) {
        if (p[i].op == 'U') b[p[i].a] = 'U';
        if (p[i].op == '+') b[p[i].a] = b[p[i].b];
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i] == 'U') {
            cnt++;
        }
    }
    cout << cnt << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            cin >> op;
            if (op == '+' || op == '-') {
                cin >> u >> v;
                p[i] = {op, u, v};
            } else {
                cin >> u;
                p[i] = {op, u, u};
            }
        }
        if (c == 1 || c == 2) {
            for (int i = 0; i <= n; ++i) {
                if (dfs(1, i)) {
                    cout << i << endl;
                    break;
                }
            }
        } else if (c == 3 || c == 4) {
            simulate1();
        } else if (c == 5 || c == 6) {
            simulate2();
        }
    }
    return 0;
}

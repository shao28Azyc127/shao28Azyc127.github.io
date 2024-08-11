// rui_er is kawaii!!!
#include <bits/stdc++.h>
using namespace std;

#ifndef RUIER
ifstream fin("tribool.in");
ofstream fout("tribool.out");
#define cin fin
#define cout fout
#endif

const int N = 300005;

enum Tribool {
    False = 0, 
    True = 1, 
    Unknown = 2, 
};

int test_case, T;
int n, m, val[N];

struct Dsu {
    int fa[N];
    void init(int n) {
        for(int i = 1; i <= n; ++i) {
            fa[i] = i;
        }
    }
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return false;
        fa[x] = y;
        return true;
    }
}dsu;

inline int getId(int x) {
    return x >= 0 ? x : (n + 1) - x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> test_case >> T; T; --T) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) {
            val[i] = i + 1;
        }
        for(int i = 1; i <= m; ++i) {
            char op;
            cin >> op;
            if(op == 'F') {
                int x;
                cin >> x;
                val[x] = -1;
            }
            else if(op == 'T') {
                int x;
                cin >> x;
                val[x] = +1;
            }
            else if(op == 'U') {
                int x;
                cin >> x;
                val[x] = 0;
            }
            else if(op == '+') {
                int x, y;
                cin >> x >> y;
                val[x] = +val[y];
            }
            else {
                int x, y;
                cin >> x >> y;
                val[x] = -val[y];
            }
        }
        dsu.init((n + 1) * 2);
        for(int i = 1; i <= n; ++i) {
            if(val[i] == 0) {
                dsu.merge(getId(i + 1), getId(-(i + 1)));
            }
            else if(val[i] == +1 || val[i] == -1) {
                ;
            }
            else {
                dsu.merge(getId(i + 1), getId(val[i]));
                dsu.merge(getId(-(i + 1)), getId(-val[i]));
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(dsu.find(getId(i + 1)) == dsu.find(getId(-(i + 1)))) {
                ++ans;
            }
        }
        cout << ans << '\n';
    }
    cout.flush();
    return 0;
}
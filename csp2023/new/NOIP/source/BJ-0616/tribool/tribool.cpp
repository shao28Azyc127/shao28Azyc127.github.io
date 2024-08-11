#include <iostream>
#include <set>
using namespace std;

set <int> vis;

const int T = 999999, F = -999999, U = 0, NC = 345678;

int ans = 0;
int c, t, n, m;
int eq[100005];
struct Statement {
    char op;
    int sub;
    int obj;
};
Statement states[100005];

int find(int x, int cur_line) {
    //cout << x << " " << cur_line << endl;
    for(int i = cur_line; i >= 0; i--) {
        //cout << states[i].op << endl;
        if(states[i].sub != x) continue;
        if(states[i].op == 'T') return T;
        if(states[i].op == 'F') return F;
        if(states[i].op == 'U') return U;
        if(states[i].op == '+') return find(states[i].obj, i - 1);
        if(states[i].op == '-') return -find(states[i].obj, i - 1);
        break;
    }
    return x;
}

int get(int x, int neg) {
    //cout << x << " " << neg << endl;
    vis.insert(x * neg);
    if(x < 0) return -get(-x, -neg);
    if(vis.find(neg * eq[x]) != vis.end()) return T;
    if(vis.find(- neg * eq[x]) != vis.end()) return U;
    if(eq[x] == U || eq[x] == T || eq[x] == F) {
        return eq[x];
    }

    return get(eq[x], neg);
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    cin >> c >> t;
    for(int i = 0; i < t; i++) {
        ans = 0;
        cin >> n >> m;
        char op;
        int sub, obj;
        for(int j = 0; j < m; j++) {
            cin >> op;
            if(op == 'T' || op == 'F' || op == 'U') {
                cin >> sub;
                states[j].op = op;
                states[j].sub = sub;
                states[j].obj = 0;
            }
            else {
                cin >> sub >> obj;
                states[j].op = op;
                states[j].sub = sub;
                states[j].obj = obj;
            }
        }
        for(int i = 1; i <= n; i++) {
            eq[i] = find(i, m - 1);
            //cout << i << " = " << eq[i] << endl;
        }
        for(int i = 1; i <= n; i++) {
            vis.clear();
            int out = get(i, 1);
            //cout << out << endl;
            if(out == 0) ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}

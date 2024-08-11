#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9;
int type, t, n, m, x[N], bak[N], ans = inf;
struct cmd { char op; int i, j; } c[N];
void dfs(int step) {
    if(step == n + 1) {
        for(int i = 1; i <= n; i++) bak[i] = x[i];
        for(int i = 1; i <= m; i++) {
            char op = c[i].op;
            if(op == 'T') bak[c[i].i] = 1;
            else if(op == 'F') bak[c[i].i] = 0;
            else if(op == 'U') bak[c[i].i] = 2;
            else if(op == '+') bak[c[i].i] = bak[c[i].j];
            else {
                int y = bak[c[i].j];
                if(y == 0) bak[c[i].i] = 1;
                else if(y == 1) bak[c[i].i] = 0;
                else bak[c[i].i] = 2;
            }
        }
        for(int i = 1; i <= n; i++)
            if(x[i] != bak[i]) return ;
        int cnt = 0;
        for(int i = 1; i <= n; i++) if(x[i] == 2) cnt++;
        ans = min(ans, cnt);
        return ;
    }
    x[step] = 0; dfs(step + 1);
    x[step] = 1; dfs(step + 1);
    x[step] = 2; dfs(step + 1);
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> type >> t;
    if(type == 3 || type == 4) {
        while(t--) {
            memset(x, 0, sizeof(x));
            cin >> n >> m;
            while(m--) {
                char op; int i; cin >> op >> i;
                if(op == 'T') x[i] = 1;
                else if(op == 'F') x[i] = 0;
                else x[i] = 2;
            }
            int cnt = 0;
            for(int i = 1; i <= n; i++)
                if(x[i] == 2) cnt++;
            printf("%d\n", cnt);
        }
    }
    else if(type == 1 || type == 2) {
        while(t--) {
            ans = inf;
            cin >> n >> m;
            for(int i = 1; i <= m; i++) {
                char op; cin >> op; c[i].op = op;
                if(op == 'T' || op == 'F' || op == 'U') cin >> c[i].i;
                else cin >> c[i].i >> c[i].j;
            }
            dfs(1);
            printf("%d\n", ans);
        }
    }
    return 0;
}
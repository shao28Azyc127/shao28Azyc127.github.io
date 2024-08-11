#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct Ask{
    char op[3];
    int x, y;
}ask[N];
int tid, n, m, a[N], nw[N];
// T = 1, F = -1, U = 0

namespace Subtask1{
    int ans;

    void dfs(int now, int nu){
        if (nu >= ans) return;
        if (now > n){
            //printf("solving now:\na: ");
            //for (int i=1; i<=n; i++) printf("%d ", a[i]); printf("\n");
            for (int i=1; i<=n; i++) nw[i] = a[i];
            for (int i=1; i<=m; i++){
                if (ask[i].op[0] == '+'){
                    nw[ask[i].x] = nw[ask[i].y];
                }
                else if (ask[i].op[0] == '-'){
                    nw[ask[i].x] = -1 * nw[ask[i].y];
                }
                else{
                    if (ask[i].op[0] == 'T') nw[ask[i].x] = 1;
                    else if (ask[i].op[0] == 'F') nw[ask[i].x] = -1;
                    else nw[ask[i].x] = 0;
                }
                //for (int i=1; i<=n; i++) printf("%d ", nw[i]);
                //printf("\n");
            }
            /*
            for (int i=1; i<=n; i++) printf("%d ", a[i]);
            printf("\nafter: ");
            for (int i=1; i<=n; i++) printf("%d ", nw[i]);
            printf("\n");
            */
            int num = 0;
            bool flg = 1;
            for (int i=1; i<=n&&flg; i++) flg &= (nw[i] == a[i]), num += (nw[i] == 0);
            if (flg) ans = min(ans, num);
            return;
        }
        a[now] = 1;
        dfs(now + 1, nu);
        a[now] = -1;
        dfs(now + 1, nu);
        a[now] = 0;
        dfs(now + 1, nu + 1);
    }

    inline void solve(){
        ans = 2e9; dfs(1, 0);
        printf("%d\n", ans);
    }
}

namespace Subtask2{
    inline void solve(){
        for (int i=1; i<=n; i++) a[i] = 2;
        for (int i=1; i<=m; i++){
            if (ask[i].op[0] == 'T') a[ask[i].x] = 1;
            else if (ask[i].op[0] == 'F') a[ask[i].x] = -1;
            else a[ask[i].x] = 0;
        }
        int ans = 0;
        for (int i=1; i<=n; i++) if (a[i] == 0) ans++;
        printf("%d\n", ans);
    }
}

namespace Subtask3{
    inline void solve(){
        for (int i=1; i<=n; i++) a[i] = 2;
        int last = 0, ans;
        for (int i=1; i<=m; i++){
            if (ask[i].op[0] == 'U') a[ask[i].x] = 0;
            else a[ask[i].x] = a[ask[i].y];
        }
        ans = 0;
        for (int i=1; i<=n; i++) if (a[i] == 0) ans++;
        if (!ans){printf("%d\n", ans); return;}
        while (ans != last){
            last = ans;
            for (int i=1; i<=m; i++){
                if (ask[i].op[0] == 'U') a[ask[i].x] = 0;
                else a[ask[i].x] = a[ask[i].y];
            }
            ans = 0;
            for (int i=1; i<=n; i++) ans += (a[i] == 0);
        }
        printf("%d\n", ans);
    }
}

inline void solve(){
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++){
        scanf("%s%d", ask[i].op, &ask[i].x);
        if (ask[i].op[0] == '+' || ask[i].op[0] == '-') scanf("%d", &ask[i].y);
    }
    if (tid == 1 || tid == 2){
        Subtask1::solve();
        return;
    }
    else if (tid == 3 || tid == 4){
        Subtask2::solve();
        return;
    }
    else if (tid == 5 || tid == 6){
        Subtask3::solve();
        return;
    }
}


int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int t;
    scanf("%d%d", &tid, &t);
    while (t--){
        solve();
    }
}

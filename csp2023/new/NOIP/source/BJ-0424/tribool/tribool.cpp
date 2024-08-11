#include <bits/stdc++.h>
using namespace std;
///T=1 U=0 F=-1
int c, t, n, m, x, y, sure[100010], ans, xx[100010], yy[100010], from[100010];
char v, u[100010];

int check(){
    int p[100010];
    for(int i = 1; i <= n; i++) p[i] = sure[i];
    for(int i = 1; i <= m; i++){
        if(u[i] == '+') p[xx[i]] = p[yy[i]];
        else if(u[i] == '-') p[xx[i]] = -p[yy[i]];
        else if(u[i] == 'T') p[xx[i]] = 1;
        else if(u[i] == 'F') p[xx[i]] = -1;
        else p[xx[i]] = 0;
    }
    for(int i = 1; i <= n; i++){
        if(p[i] != sure[i])
            return 0;
    }
    return 1;
}

void dfs(int i, int cnt){
    if(cnt >= ans) return;
    if(i == n + 1){
        if(check()){
            ans = min(ans, cnt);
        }
        return;
    }
    sure[i] = 1;
    dfs(i + 1, cnt);
    sure[i] = -1;
    dfs(i + 1, cnt);
    sure[i] = 0;
    dfs(i + 1, cnt + 1);
}

int main(){
//    freopen("a.in", "r", stdin);
//    freopen(".out", "w", stdout);
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> t;
    if(c >= 3 && c <= 4){
        while(t--){
            ans = 0;
            cin >> n >> m;
            while(m--){
                cin >> v >> x;
                if(v == 'U') ans++;
            }
            cout << ans << '\n';
        }
        return 0;
    }
    while(t--){
        ans = INT_MAX;
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            cin >> u[i];
            if(u[i] == '+' || u[i] == '-') cin >> xx[i] >> yy[i];
            else cin >> xx[i];
        }
        dfs(1, 0);
        cout << ans << '\n';
    }
    return 0;
}

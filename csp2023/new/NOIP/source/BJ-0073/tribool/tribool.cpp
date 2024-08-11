#include<bits/stdc++.h>
using namespace std;
int st[60005][20];
int w[60005][20];
int cnt[20];
int tot = 0;
int n, m;
int val[1005];
void dfs(int num){
    if(num == n + 1){
        ++tot;
        for(int i = 1; i <= n; i++){
            w[tot][i] = st[tot][i] = cnt[i];
        }
        return;
    }
    cnt[num] = 0;
    dfs(num + 1);
    cnt[num] = -1;
    dfs(num + 1);
    cnt[num] = 1;
    dfs(num + 1);
}
int tt[100005];
int ft[100005];
struct In{
    char v;
    int a, b;
} q[100005];
signed main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, T;
    cin >> c >> T;
    while(T--){
        cin>> n >> m;
        val['F'] = -1;
        val['T'] = 1;
        val['U'] = 0;
        if(c <= 2){
                tot = 0;
            dfs(1);
            for(int i = 1; i <= m; i++){
                char v;
                cin >> v;
                if(v == 'T' || v == 'F' || v == 'U'){
                    int t;
                    cin >> t;
                    for(int j = 1; j <= tot; j++) w[j][t] = val[v];
                }
                if(v == '+'){
                    int a, b;
                    cin >> a >> b;
                    int tv = 1;
                    for(int j = 1; j <= tot; j++) w[j][a] = tv * w[j][b];
                }
                if(v == '-'){
                    int a, b;
                    cin >> a >> b;
                    int tv = -1;
                    for(int j = 1; j <= tot; j++) w[j][a] = tv * w[j][b];
                }
            }
            int ans = 1e9;
            for(int i = 1; i <= tot; i++){
                int ok = 1;
                int rec = 0;
            /*    for(int j = 1; j <= n; j++){
                    cout << st[i][j] << " ";
                }
                cout << "end as";
                for(int j = 1; j <= n; j++){
                    cout << w[i][j] << " ";
                }
                cout << endl;*/
                for(int j = 1; j <= n; j++){
                    if(w[i][j] != st[i][j]){
                        ok = 0;
                        break;
                    }
                    if(st[i][j] == 0) rec++;
                }
                if(!ok) continue;
                ans = min(ans, rec);
                if(ans == 0) break;
            }
            cout << ans << '\n';
        } else if(c == 3 || c == 4){
            for(int i = 1; i <= n; i++) tt[i] = 1;
            for(int i = 1; i <= m; i++){
                char v;
                cin >> v;
                if(v == 'T' || v == 'F' || v == 'U'){
                    int t;
                    cin >> t;
                    tt[t] = val[v];
                  //  cout << t << "=" << val[v] << endl;
                }
            }
            int ans = 0;
            for(int i = 1; i <= n; i++) if(tt[i] == 0) ans++;
            cout << ans << '\n';
        } else if(c == 5){
            for(int i = 1; i <= n; i++) tt[i] = 1;
            for(int i = 1; i <= m; i++){
                char v;
                cin >> v;
                q[i].v = v;
                if(v == 'T' || v == 'F' || v == 'U'){
                    int t;
                    cin >> t;
                    q[i].a = t;
                    tt[t] = val[v];
                  //  cout << t << "=" << val[v] << endl;
                } else {
                    int a, b;
                    cin >> a >> b;
                    q[i].a = a, q[i].b = b;
                    tt[a] = tt[b];
                }
            }
       //     int ans = 0;
            while(1){
                for(int i = 1; i <= n; i++){
                    ft[i] = tt[i];
                }
                for(int i = 1; i <= m; i++){
                    char v;
                    v = q[i].v;
                    if(v == 'T' || v == 'F' || v == 'U'){
                        int t;
                        t = q[i].a;
                        ft[t] = val[v];
                      //  cout << t << "=" << val[v] << endl;
                    } else {
                        int a, b;
                        a = q[i].a, b = q[i].b;
                        ft[a] = ft[b];
                    }
                }
                int flag = 1;
                for(int i = 1; i <= n; i++){
                    if(ft[i] != tt[i]){
                        flag = 0;
                    }
                    tt[i] = ft[i];
                }
                if(flag) break;
            }
            int ans = 0;
            for(int i = 1; i <= n; i++){
                if(ft[i] == 0){
                    ans++;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}

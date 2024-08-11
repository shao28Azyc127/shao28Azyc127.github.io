#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int c, t, n, m, x[300005], y[300005], ans = inf, a[15], b[15], now[300005];
char v[300005];
bool vis[300005];
vector<int> e[300005];
inline int no(int x){
    if(x == 0){
        return 1;
    }
    if(x == 1){
        return 0;
    }
    return 2;
}
inline int fun(char x){
    if(x == 'T'){
        return 1;
    }
    if(x == 'F'){
        return 0;
    }
    return 2;
}
inline int chk(){
    memcpy(b, a, sizeof(b));
    for(int i = 1;i <= m;i++){
        if(v[i] == '+'){
            b[x[i]] = b[y[i]];
        }
        else if(v[i] == '-'){
            b[x[i]] = no(b[y[i]]);
        }
        else{
            b[x[i]] = fun(v[i]);
        }
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] != b[i]){
            return inf;
        }
        if(a[i] == 2){
            cnt++;
        }
    }
    return cnt;
}
void dfs(int t){
    if(t > n){
        ans = min(ans, chk());
        return;
    }
    a[t] = 0;
    dfs(t + 1);
    a[t] = 1;
    dfs(t + 1);
    a[t] = 2;
    dfs(t + 1);
}
void dfs2(int t){
    vis[t] = 1;
    for(int i = 0;i < (int)e[t].size();i++){
        if(!vis[e[t][i]]){
            now[e[t][i]] = 2 * n + 3;
            dfs2(e[t][i]);
        }
    }
}
signed main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> c >> t;
    while(t--){
        ans = inf;
        cin >> n >> m;
        for(int i = 1;i <= m;i++){
            cin >> v[i];
            if(v[i] == '+' || v[i] == '-'){
                cin >> x[i] >> y[i];
            }
            else{
                cin >> x[i];
            }
        }
        if(c == 1 || c == 2){
            dfs(1);
            cout << ans << "\n";
            continue;
        }
        if(c == 3 || c == 4){
            memset(now, 0x3f, sizeof(now));
            for(int i = 1;i <= m;i++){
                now[x[i]] = fun(v[i]);
            }
            ans = 0;
            for(int i = 1;i <= n;i++){
                if(now[i] == 2){
                    ans++;
                }
            }
            cout << ans << "\n";
            continue;
        }
        if(c == 5){
            memset(now, 0, sizeof(now));
            for(int j = 1;j <= n;j++){
                for(int i = 1;i <= m;i++){
                    if(v[i] == '+'){
                        now[x[i]] = now[y[i]];
                    }
                    else{
                        now[x[i]] = 2 * n + 3;
                    }
                }
            }
            ans = 0;
            for(int i = 1;i <= n;i++){
                if(now[i] == 2 * n + 3){
                    ans++;
                }
            }
            cout << ans << "\n";
            continue;
        }
        if(c == 6){
            for(int i = 1;i <= n;i++){
                now[i] = i;
            }
            for(int i = 1;i <= m;i++){
                if(v[i] == '+'){
                    now[x[i]] = now[y[i]];
                }
                else{
                    now[x[i]] = 2 * n + 3;
                }
            }
            for(int i = 1;i <= n;i++){
                e[now[i]].push_back(i);
            }
            dfs2(2 * n + 3);
            ans = 0;
            for(int i = 1;i <= n;i++){
                if(now[i] == 2 * n + 3){
                    ans++;
                }
            }
            cout << ans << "\n";
            for(int i = 1;i <= n;i++){
                while(e[i].size()){
                    e[i].pop_back();
                }
            }
            while(e[2 * n + 3].size()){
                e[2 * n + 3].pop_back();
            }
            continue;
        }
    }
	return 0;
}

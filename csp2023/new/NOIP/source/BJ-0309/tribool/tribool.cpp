#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 5;
int c, t, n, m, ans, cnt, v[maxn], a[maxn], b[maxn], x[maxn], y[maxn];
char op;
void dfs(int st){
    if(st == n + 1){
        for(int i = 1; i <= n; ++i) y[i] = x[i];
        for(int i = 1; i <= m; ++i)
            if(v[i] <= 3) y[a[i]] = v[i];
            else if(v[i] == 4) y[a[i]] = y[b[i]];
            else y[a[i]] = (y[b[i]] == 3) ? 3 : 3 - y[b[i]];
        cnt = 0;
        for(int i = 1; i <= n; ++i){
            if(x[i] != y[i]) return;
            cnt += (x[i] == 3);
        }
        ans = min(ans, cnt);
        return;
    }
    x[st] = 1;
    dfs(st + 1);
    x[st] = 2;
    dfs(st + 1);
    x[st] = 3;
    dfs(st + 1);
    return;
}
int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while(t--){
        ans = maxn;
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        cin >> n >> m;
        for(int i = 1; i <= m; ++i){
            cin >> op;
            if(op == 'T') v[i] = 1, cin >> a[i];
            else if(op == 'F') v[i] = 2, cin >> a[i];
            else if(op == 'U') v[i] = 3, cin >> a[i];
            else if(op == '+') v[i] = 4, cin >> a[i] >>  b[i];
            else v[i] = 5, cin >> a[i] >> b[i];
        }
        if(c == 1 || c == 2) dfs(1), cout << ans << endl;
        else cout << '0' << endl;
    }
    return 0;
}
//hope:40pts
//O(t * 3^n) when n <= 10
//O(t) when n > 10
//bu ke yi, zong si ling!

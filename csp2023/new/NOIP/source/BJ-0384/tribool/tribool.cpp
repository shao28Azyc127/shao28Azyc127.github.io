#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 10;
int to[MAXN], n, m, res[MAXN];
int lower_bit(int i){
    return (i < 2 ? 1 - i : i);
}
void get(int u){
    if (res[u] > -1) return;
    if (to[u] == u){
        res[u] = 0;
        return;
    }
    if (to[u] == u + n){
        res[u] = 2;
        return;
    }
    int v = (to[u] > n ? to[u] - n : to[u]);
    get(v);
    res[u] = (to[u] > n ? lower_bit(res[v]) : res[v]);
}
void Work7and8(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        to[i] = i, res[i] = -1;
    while (m--){
        char op; int i, j;
        cin >> op >> i >> j;
        if (op == '+') to[i] = to[j];
        else if (op == '-'){
            if (to[j] > n) to[i] = to[j] - n;
            else to[i] = to[j] + n;
        }
    }
    for (int i = 1; i <= n; i++)
        if (res[i] == -1){
            get(i);
        }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += (int)(res[i] == 2);
    cout << cnt << endl;
}
char a[MAXN];
void Work3and4(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = '#';
    while (m--){
        char op; int i;
        cin >> op >> i;
        a[i] = op;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == 'U') cnt++;
    cout << cnt << endl;
}
char b[MAXN], temp[MAXN];
struct Node{
    char op;
    int i, j;
}p[MAXN];
char fan(char ch){
    if (ch == 'T') return 'F';
    if (ch == 'F') return 'T';
    return 'U';
}
bool check(){
    for (int i = 1; i <= n; i++) temp[i] = b[i];
    for (int i = 1; i <= m; i++){
        if (p[i].op == 'T' || p[i].op == 'F' || p[i].op == 'U')
            temp[p[i].i] = p[i].op;
        else if (p[i].op == '-')
            temp[p[i].i] = fan(temp[p[i].j]);
        else temp[p[i].i] = temp[p[i].j];
    }
    for (int i = 1; i <= n; i++)
        if (temp[i] != b[i]) return false;
    return true;
}
int minn = 1e9;
void dfs(int step, int cnt){
    if (step > n){
        if (check()){
            minn = min(minn, cnt);
        }
        return;
    }
    b[step] = 'T';
    dfs(step + 1, cnt);
    b[step] = 'F';
    dfs(step + 1, cnt);
    b[step] = 'U';
    dfs(step + 1, cnt + 1);
}
void Work1and2(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> p[i].op >> p[i].i;
        if (p[i].op == '-' || p[i].op == '+') cin >> p[i].j;
    }
    minn = 1e9;
    dfs(1, 0);
    cout << minn << endl;
}
int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    if (c == 1 || c == 2){
        while (t--){
            Work1and2();
        }
        return 0;
    }
    if (3 <= c && c <= 4){
        while (t--){
            Work3and4();
        }
        return 0;
    }
    if (7 <= c && c <= 8){
        while (t--){
            Work7and8();
        }
        return 0;
    }
    return 0;
}

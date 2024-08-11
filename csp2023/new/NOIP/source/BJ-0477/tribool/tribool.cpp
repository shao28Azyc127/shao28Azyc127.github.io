#include <bits/stdc++.h>
using namespace std;

int c, t, n, m, ans = 114514;
vector <int> tri = {0};

struct cxd{
    char type;
    int a, b;
}op[14];

bool check(){
    vector <int> tmp = tri;
    for (int i = 1; i <= m;++i){
        if (op[i].type == '+'){
            tmp[op[i].a] = tri[op[i].b];
        }
        if (op[i].type == '-'){
            if (tri[op[i].b] == 1) tmp[op[i].a] = 0;
            if (tri[op[i].b] == 0) tmp[op[i].a] = 1;
            if (tri[op[i].b] == 2) tmp[op[i].a] = 2;
        }
        if (op[i].type == 'T'){
            tmp[op[i].a] = 1;
        }
        if (op[i].type == 'U'){
            tmp[op[i].a] = 2;
        }
        if (op[i].type == 'F'){
            tmp[op[i].a] = 0;
        }
    }
    return tri == tmp;
}

void dfs(int dep){
    if (dep == n){
        if (check() == 1){
            int tot = 0;
            //for (int i = 1;i <= n;++i) cout << tri[i] << " ";
            //cout << endl;
            for (int i = 1;i <= n;++i) if (tri[i] == 2) tot ++;
            ans = min(ans, tot);
        }
        return;
    }
    tri.push_back(0);
    dfs(dep + 1);
    tri.pop_back();
    tri.push_back(1);
    dfs(dep + 1);
    tri.pop_back();
    tri.push_back(2);
    dfs(dep + 1);
    tri.pop_back();
}

void solve1(){
    while (t--){
        cin >> n >> m;
        ans = 114514;
        for (int i = 1;i <= m;++i){
            cin >> op[i].type;
            if (op[i].type == '+' || op[i].type == '-')
                cin >> op[i].a >> op[i].b;
            else cin >> op[i].a;
        }
        dfs(0);
        cout << ans << endl;
    }
}

int const N = 1e5 + 10;
int a[N];

void solve2(){
    while (t--){
        cin >> n >> m;
        ans = 114514;
        for (int i = 1;i <= m;++i){
            cin >> op[i].type >> op[i].a;
            if (op[i].type == 'U') a[op[i].a] = 1;
            else a[op[i].a] = 0;
        }
        int tot = 0;
        for (int i = 1;i <= n;++i) if (a[i] == 1) tot ++;
        cout << tot << endl;
    }
}

int main(){
    freopen("tribool.in","r", stdin);
    freopen("tribool.out","w", stdout);
    cin >> c >> t;
    if (c == 1 || c == 2) solve1();
    if (c == 3 || c == 4) solve2();
    return 0;
}

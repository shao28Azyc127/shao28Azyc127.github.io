# include <vector>
# include <iostream>
using namespace std;

vector <int> x;
vector <int> y;
vector <int> tx;
vector <int> ty;
int c, n, m, q;

bool dfs(int sx, int sy, vector <int> &l, vector <int> &r, bool op){
    if (sx > n || sy > m)
        return false;
    if (l[sx] == r[sy])
        return false;
    if (!((l[sx] < r[sy]) ^ op))
        return false;
    if (sx == n && sy == m)
        return true;
    return dfs(sx + 1, sy, l, r, op) || dfs(sx, sy + 1, l, r, op) || dfs(sx + 1, sy + 1, l, r, op);
}

void solve(vector <int> &l, vector <int> &r){
    if (c <= 2)
        cout << !((l[1] < r[1]) ^ (l[n] < r[m]));
    if (c <= 4)
        cout << dfs(1, 1, l, r, l[1] > r[1]);
}

int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    int tmp;
    x.resize(n + 1), y.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> tmp;
        x[i] = tmp;
    }
    for (int i = 1; i <= m; i++){
        cin >> tmp;
        y[i] = tmp;
    }
    solve(x, y);
    tx.resize(n + 1), ty.resize(n + 1);
    while (q--){
        tx = x, ty = y;
        int kx, ky;
        cin >> kx >> ky;
        for (int i = 1; i <= kx; i++){
            int p, v;
            cin >> p >> v;
            tx[p] = v;
        }
        for (int i = 1; i <= ky; i++){
            int p, v;
            cin >> p >> v;
            ty[p] = v;
        }
        solve(tx, ty);
    }
    return 0;
}
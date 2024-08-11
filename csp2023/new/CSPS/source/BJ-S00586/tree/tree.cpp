# include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10;
long long n, a[MAXN], b[MAXN], c[MAXN];
vector <long long> vec[MAXN], son[MAXN];
long long mx[MAXN];
void dfs(long long nod, long long fa) {
    for (long long to : vec[nod]) {
        if (to == fa) continue;
        son[nod].push_back(to);
        dfs(to, nod);
        mx[nod] = max(mx[nod], mx[to]);
    }
}
priority_queue <pair <long long, long long> > q;
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        mx[i] = ceil(1.0 * a[i] / (max(b[i] + c[i], 1ll)));
    }
    //bool flag = 1;
    for (long long i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    //   if (u != i || v != i + 1) flag = 0;
    }
    long long ans = 0;
    dfs(1, 0);
    long long day = 1;
    q.push(make_pair(mx[1], 1));
    while (!q.empty()) {
        long long nod = q.top().second;
        q.pop();
        ans = max(ans, day + mx[nod] - 1);
        for (long long to : son[nod]) {
            q.push(make_pair(mx[to], to));
        }
    }
    cout << ans << endl ;
    return 0;
}
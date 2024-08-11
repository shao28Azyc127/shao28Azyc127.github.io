#include<bits/stdc++.h>
using namespace std;
const int MX = 100005;
typedef long long LL;
int c, t, n, m, I[MX], J[MX], val[MX], b[MX], ans;
char v[MX];
map<char, int> mp;
void dfs(int p, int cnt)
{
    if (cnt >= ans) return;
    if (p > n) {
        bool flag = 1;
        for (int i = 1; i <= n; i++) b[i] = val[i];
        for (int i = 1; i <= m; i++) {
            if (v[i] >= 'A' && v[i] <= 'Z') b[I[i]] = mp[v[i]];
            else if (v[i] == '+') b[I[i]] = b[J[i]];
            else b[I[i]] = 2 - b[J[i]];
        }
        for (int i = 1; i <= n; i++)
            if (b[i] != val[i]) flag = 0;
        if (flag) ans = cnt;
        return;
    }
    val[p] = 0;
    dfs(p + 1, cnt);
    val[p] = 2;
    dfs(p + 1, cnt);
    val[p] = 1;
    dfs(p + 1, cnt + 1);
}
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    mp['T'] = 2;
    mp['F'] = 0;
    mp['U'] = 1;
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> c >> t;
    while (t--) {
        cin >> n >> m;
        ans = MX + 1;
        for (int i = 1; i <= m; i++) {
            cin >> v[i] >> I[i];
            if (v[i] < 'A' || v[i] > 'Z') cin >> J[i];
        }
        if (c <= 2) dfs(1, 0);
        if (c == 3 || c == 4) {
            ans = 0;
            for (int i = 1; i <= m; i++) val[I[i]] = mp[v[i]];
            for (int i = 1; i <= n; i++) ans += (val[i] == 1);
        }
        if (c == 7 || c == 8) {
            ans = 0;
            for (int i = 1; i <= m; i++) {
                if (v[i] == '+') val[I[i]] = val[J[i]];
                else val[I[i]] = 2 - val[J[i]];
            }
            memcpy(b, val, sizeof(val));
            for (int i = 1; i <= m; i++)
                if (v[i] == '+') b[I[i]] = b[J[i]];
                else b[I[i]] = 2 - b[J[i]];
            for (int i = 1; i <= n; i++) ans += (b[i] != val[i]);
        }
        cout << ans << endl;
    }
    return 0;
}

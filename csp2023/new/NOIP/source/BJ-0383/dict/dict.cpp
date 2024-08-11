#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 5;
int n, m, ans[maxn];
struct Node {
    string s;
    int id;
    inline bool operator< (const Node &r) const {
        return s < r.s;
    }
} a[maxn];
char t[maxn];
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].s; a[i].id = i;
    }
    sort(a+1, a+n+1);
    // for (int i = 1; i <= n; i++) cout << a[i].s << '\n';
    string tmp;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) t[j] = a[i].s[j];
        sort(t, t+m);
        tmp = "";
        for (int j = 0; j < m; j++) tmp += t[j];
        int l = 1, r = n, res = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (tmp < a[mid].s) {
                r = mid - 1, res = mid;
            } else {
                l = mid + 1;
            }
        }
        if (res == 1 || (res == 2 && i == 1)) ans[a[i].id] = 1;
    }
    for (int i = 1; i <= n; i++) printf("%d", ans[i]);
    return 0;
}

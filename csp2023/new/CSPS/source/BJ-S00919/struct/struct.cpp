#include <bits/stdc++.h>
#define int long long
using namespace std;

void Max(int &x, int y) {if (x < y) x = y; }
const int N = 110, M = 15, K = 10010;
char t[K];
int T, n, m, tot;
string a[N];
map<string, int> mp;
struct node{
    int type; string nam;
};
struct st{
    int siz, mx;
    vector<node> g;
    st() {
        siz = mx = 0;
        g.clear();
    }
}s[N];
struct ele{
    node x;
    int l, r;
    ele() {l = r = 0; }
}p[N];

signed main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    n = 4;
    s[1].siz = s[1].mx = 1;
    s[2].siz = s[2].mx = 2;
    s[3].siz = s[3].mx = 4;
    s[4].siz = s[4].mx = 8;
    a[1] = "byte", a[2] = "short", a[3] = "int", a[4] = "long";
    mp["byte"] = 1, mp["short"] = 2, mp["int"] = 3, mp["long"] = 4;
    scanf("%lld", &T);
    while (T--) {
        int op; scanf("%lld", &op);
        if (op == 1) {
            string str; int k;
            cin >> str; scanf("%lld", &k);
            mp[str] = ++n;
            a[n] = str;
            for (int i=1; i<=k; ++i) {
                string type, nam;
                cin >> type >> nam;
                int x = mp[type];
                s[n].g.push_back((node) {x, nam});
                Max(s[n].mx, s[x].mx);
            }
            s[n].siz = s[n].mx * k;
            printf("%lld %lld\n", s[n].siz, s[n].mx);
        } else if (op == 2) {
            string type, nam;
            cin >> type >> nam;
            int x = mp[type];
            int mx = s[x].mx, siz = s[x].siz;
            ++m;
            p[m].x = (node) {x, nam};
            int l = (tot + mx - 1) / mx * mx;
            int r = l + siz - 1;
            p[m].l = l, p[m].r = r;
            tot = r + 1;
            printf("%lld\n", p[m].l);
        } else if (op == 3) {
            scanf("%s", t + 1);
            int len = strlen(t + 1), ans = 0, pos = 0;
            string nam = "";
            for (int i=1; i<=len; ++i) {
                if (t[i] == '.') {
                    if (pos == 0) {
                        for (int j=1; j<=m; ++j) {
                            if (p[j].x.nam == nam) {
                                ans = p[j].l, pos = p[j].x.type; break;
                            }
                        }
                    } else {
                        for (auto j : s[pos].g) {
                            if (j.nam == nam) {
                                pos = j.type; break;
                            } else ans += s[pos].mx;
                        }
                    }
                    nam = "";
                } else nam += t[i];
            }
            if (pos == 0) {
                for (int j=1; j<=m; ++j) {
                    if (p[j].x.nam == nam) {
                        ans = p[j].l, pos = p[j].x.type; break;
                    }
                }
            } else {
                for (auto j : s[pos].g) {
                    if (j.nam == nam) {
                        pos = j.type; break;
                    } else ans += s[pos].mx;
                }
            }
            printf("%lld\n", ans);
        } else {
            int val; scanf("%lld", &val);
            string res = "";
            int pos = 0;
            while (2) {
                if (pos && pos <= 4) {
                    if (val >= s[pos].siz) printf("ERR\n");
                    else cout << res << "\n";
                    break;
                }
                if (pos == 0) {
                    bool flag = true;
                    for (int j=1; j<=m; ++j) {
                        if (p[j].l <= pos) {
                            if (pos > p[j].r) {
                                printf("ERR\n");
                                flag = false; break;
                            }
                            res += p[j].x.nam;
                            val -= p[j].l;
                            pos = p[j].x.type;
                            break;
                        }
                    }
                    if (!flag) break;
                } else {
                    bool flag = true;
                    for (auto j : s[pos].g) {
                        if (val < s[pos].mx) {
                            if (val < s[j.type].siz) {
                                pos = j.type;
                                res += "."; res += j.nam;
                                break;
                            }
                            else {
                                printf("ERR\n"); flag = false;
                                break;
                            }
                        } else val -= s[pos].mx;
                    }
                    if (!flag) break;
                }
            }
        }
    }
    return 0;
}

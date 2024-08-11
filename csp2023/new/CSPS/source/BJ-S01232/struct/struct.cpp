#include <bits/stdc++.h>
#define int long long

using namespace std;

const int NR = 105;

struct Str { 
    int mx, cnt, siz, s[NR], p[NR];
    map < string, int > name;
    string t[NR];
} a[NR];

int n, tot, lst, sum, stp[NR];
map < string, int > mp, vtp, vst;
string na[NR];

inline string getstr(int x, string y) {
    string ans;
    for (int i = x; i < y.size() && y[i] != '.'; ++i) ans.push_back(y[i]);
    return ans;
}

signed main() {
    ios :: sync_with_stdio(false), cin.tie(0);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    mp["byte"] =  1, mp["short"] = 2, mp["int"] =  3, mp["long"] = 4, tot = 4;
    a[1].mx = a[1].siz = 1, a[2].mx = a[2].siz = 2, a[3].mx = a[3].siz = 4, a[4].mx = a[4].siz = 8;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int op; cin >> op;
        if (op == 1) { 
            string s, t; int m; cin >> s >> m;
            mp[s] = ++ tot;
            while (m --) {
                cin >> s >> t;
                a[tot].cnt ++, a[tot].name[t] = a[tot].cnt, a[tot].t[a[tot].cnt] = t, a[tot].s[a[tot].cnt] = mp[s], a[tot].p[a[tot].cnt] = a[tot].siz;
                int tmp = a[a[tot].s[a[tot].cnt]].mx;
                a[tot].p[a[tot].cnt] = (a[tot].p[a[tot].cnt] / tmp + (a[tot].p[a[tot].cnt] % tmp != 0)) * tmp;
                a[tot].mx = max(a[tot].mx, tmp), a[tot].siz = (a[tot].siz / tmp + (a[tot].siz % tmp != 0)) * tmp + a[a[tot].s[a[tot].cnt]].siz;
            }
            a[tot].siz = (a[tot].siz / a[tot].mx + (a[tot].siz % a[tot].mx != 0)) * a[tot].mx;
            cout << a[tot].siz << ' ' << a[tot].mx << '\n';
        }
        if (op == 2) {
            string s, t; cin >> s >> t, sum ++, na[sum] = t;
            vtp[t] = mp[s];
            int tmp = a[vtp[t]].mx;
            vst[t] = (lst / tmp + (lst % tmp != 0)) * tmp, lst = vst[t] + a[vtp[t]].siz;
            cout << vst[t] << '\n';
        }
        if (op == 3)  {
            string s, t; cin >> s;
            int p = 0, st = -1, tp;
            while (p < s.size()) {
                t = getstr(p, s), p += t.size() + 1;
                if (st == -1) st = vst[t], tp = vtp[t];
                else st = st + a[tp].p[a[tp].name[t]], tp = a[tp].s[a[tp].name[t]];
            }
            cout << st << '\n';
        }
        if (op == 4) {
            int x, typ; cin >> x;
            string s, t; bool flg = 0;
            for (int i = 1; i <= sum; ++i) 
                if (vst[na[i]] <= x && vst[na[i]] + a[vtp[na[i]]].siz > x) {
                    typ = vtp[na[i]], s = na[i], flg = 1, x -= vst[na[i]];
                    break;
                }
            if (!flg) {
                cout << "ERR\n";
                continue;
            }
            bool err = 0;
            while (typ > 4) {
                flg = 0;
                for (int i = 1; i <= a[typ].cnt; ++i)
                    if (a[typ].p[i] <= x && a[typ].p[i] + a[a[typ].s[i]].siz > x) {
                        s.push_back('.'), s += a[typ].t[i], x -= a[typ].p[i], typ = a[typ].s[i], flg = 1;
                        break;
                    }
                if (!flg) {
                    err = 1; 
                    break;
                }
            }
            if (err) cout << "ERR\n";
            else cout << s << '\n';
        }
    }
    return 0;
}
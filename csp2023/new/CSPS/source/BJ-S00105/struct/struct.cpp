#include <bits/stdc++.h>
#define int long long
using namespace std;
int T, op;

struct type {
    int k, base, sz, o[105];
    string t[105], n[105];
    map<string, int> idx;
    inline void read(void) {
        base = sz = 0;
        idx.clear();
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> t[i] >> n[i];
            idx[n[i]] = i;
        }
    }
} tmp;

string s;
map<string, type> mp;

int cnt;

struct node {
    int st;
    type t;
    inline void read(void) {
        string name;
        cin >> name; t = mp[name];
        st = ceil(1.0 * cnt / t.base) * t.base;
        cnt = st + t.sz;
    }
} p;

vector<pair<node, string>> v;
map<string, node> q;

int Solve(int l, type tp) {
    int mid = -1;
    string t;
    for (int i = l; i < s.size(); i++) {
        if (s[i] == '.') {
            mid = i;
            break;
        }
        else t.push_back(s[i]);
    }
    if (mid > 0) {
        int id = tp.idx[t];
        return tp.o[id] + Solve(mid + 1, mp[tp.t[id]]);
    }
    return tp.o[tp.idx[t]];
}

string Check(string name, type tp, int addr) {
    if (tp.k == 0) return name;
    int l = 1, r = tp.k, mid, ans;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (tp.o[mid] <= addr) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    if (tp.o[ans] + mp[tp.t[ans]].sz < addr) return "ERR";
    string res = Check(tmp.n[ans], mp[tp.t[ans]], addr - tp.o[ans]);
    if (res == "ERR") return res;
    return name + '.' + res;
}

signed main(void) {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);

    tmp.sz = 1, tmp.base = 1;
    mp["byte"] = tmp;
    tmp.sz = 2, tmp.base = 2;
    mp["short"] = tmp;
    tmp.sz = 4, tmp.base = 4;
    mp["int"] = tmp;
    tmp.sz = 8, tmp.base = 8;
    mp["long"] = tmp;

    cin >> T;
    while (T--) {
        cin >> op;
        if (op == 1) {
            cin >> s; tmp.read();
            for (int i = 1; i <= tmp.k; i++)
                tmp.base = max(tmp.base, mp[tmp.t[i]].base);
            tmp.o[1] = 0;
            for (int i = 2; i <= tmp.k; i++)
                tmp.o[i] = ceil(1.0 * (tmp.o[i - 1] + mp[tmp.t[i - 1]].sz) / mp[tmp.t[i]].base) * mp[tmp.t[i]].base;
            tmp.sz = ceil(1.0 * (tmp.o[tmp.k] + mp[tmp.t[tmp.k]].sz) / tmp.base) * tmp.base;
            mp[s] = tmp;
            cout << tmp.sz << ' ' << tmp.base << endl;
        }
        else if (op == 2) {
            p.read();
            cin >> s;
            q[s] = p; v.push_back({p, s});
            cout << p.st << endl;
        }
        else if (op == 3) {
            cin >> s;

            int mid = -1;
            string t;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '.') {
                    mid = i;
                    break;
                }
                else t.push_back(s[i]);
            }
            if (mid == -1) cout << q[t].st << endl;
            else cout << q[t].st + Solve(mid + 1, q[t].t) << endl;
        }
        else {
            int addr;
            cin >> addr;
            if (v.size() == 0) {
                cout << "ERR" << endl;
                continue;
            }
            int l = 0, r = v.size() - 1, mid, ans;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (v[mid].first.st <= addr) ans = mid, l = mid + 1;
                else r = mid - 1;
            }
            cout << Check(v[ans].second, v[ans].first.t, addr - v[ans].first.st) << endl;
        }
    }
    return 0;
}

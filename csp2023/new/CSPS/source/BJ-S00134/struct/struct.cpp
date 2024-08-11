#include<bits/stdc++.h>
#define int long long
using namespace std;

const int NR = 100;

int n, bn;
map<string, int> mp, mp2;
//mp struct -> id(int)
//mp2 element -> id(int)
vector<pair<int, int> > v;
//v 类型与首地址
vector<string> str;

struct Struct {
    int pn, s, a;
    map<string, int> mp;
    vector<int> p, o;
    vector<string> str;
} b[NR + 5];

signed main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    mp["byte"] = 1;
    b[1].s = 1;
    b[1].a = 1;
    mp["short"] = 2;
    b[2].s = 2;
    b[2].a = 2;
    mp["int"] = 3;
    b[3].s = 4;
    b[3].a = 4;
    mp["long"] = 4;
    b[4].s = 8;
    b[4].a = 8;
    bn = 4;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        //cout << "started: " << i << '\n';
        int op;
        cin >> op;
        if(op == 1) {
            string s;
            int k;
            cin >> s >> k;
            //cout << "read1: " << s << ' ' << k << '\n';
            mp[s] = ++bn;
            Struct &q = b[bn];
            q.p.resize(k + 1);
            q.o.resize(k + 1);
            q.str.resize(k + 1);
            q.a = 0;
            for(int j = 1; j <= k; j++) {
                string s1, s2;
                cin >> s1 >> s2;
                //cout << "member: " << j << ' ' << s1 << ' ' << s2 << '\n';
                int i1 = mp[s1];
                q.p[j] = i1;
                q.str[j] = s2;
                q.mp[s2] = j;
                q.a = max(q.a, b[i1].a);
            }
            q.o[1] = 0;
            for(int j = 2; j <= k; j++) {
                int i1 = q.p[j - 1], i2 = q.p[j];
                q.o[j] = q.o[j - 1] + b[i1].s;
                while(q.o[j] % b[i2].a != 0) {
                    q.o[j]++;
                }
            }
            q.s = q.o[k] + b[q.p[k]].s;
            while(q.s % q.a != 0) {
                q.s++;
            }
            //cout << "data: " << bn << '\n';
            //for(int j = 1; j <= k; j++) {
            //    cout << q.p[j] << ' ';
            //}
            //cout << '\n';
            //for(int j = 1; j <= k; j++) {
            //    cout << q.str[j] << ' ';
            //}
            //cout << '\n';
            //for(int j = 1; j <= k; j++) {
            //    cout << q.o[j] << ' ';
            //}
            //cout << '\n';
            cout << q.s << ' ' << q.a << '\n';
        }
        else if(op == 2) {
            string tp, nm;
            cin >> tp >> nm;
            //cout << "read2: " << tp << ' ' << nm << '\n';
            int tpn = mp[tp];
            //cout << "tpn: " << tpn << '\n';
            str.emplace_back(nm);
            mp2[nm] = v.size();
            if(v.empty()) {
                v.emplace_back(make_pair(tpn, 0));
                cout << "0\n";
                continue;
            }
            int tpl = v.back().first, stl = v.back().second;
            int st = stl + b[tpl].s;
            while(st % b[tpn].a != 0) {
                st++;
            }
            v.emplace_back(make_pair(tpn, st));
            cout << st << '\n';
        }
        else if(op == 3) {
            string s, t = "";
            int tpn = -1, stn = -1;
            cin >> s;
            s += '.';
            for(char c : s) {
                if(c == '.') {
                    if(tpn == -1) {
                        int id = mp2[t];
                        tpn = v[id].first;
                        stn = v[id].second;
                    }
                    else {
                        Struct &q = b[tpn];
                        int id = q.mp[t];
                        tpn = q.p[id];
                        stn += q.o[id];
                    }
                    t = "";
                }
                else {
                    t += c;
                }
            }
            cout << stn << '\n';
        }
        else {
            int addr;
            cin >> addr;
            //cout << "read4: " << addr << '\n';
            int tp = -1, st = -1, tpn = -1, stn = -1;
            string start;
            bool f = 1;
            for(int j = 0; j < v.size(); j++) {
                int tpi = v[j].first, sti = v[j].second;
                if(sti <= addr && sti + b[tpi].s > addr) {
                    tp = tpi;
                    st = sti;
                    start = str[j];
                    break;
                }
            }
            if(tp == -1) {
                cout << "ERR\n";
                continue;
            }
            tpn = tp;
            stn = st;
            //cout << tpn << ' ' << stn << '\n';
            while(tpn > 4) {
                Struct &q = b[tpn];
                bool f2 = 0;
                for(int j = 1; j < q.p.size(); j++) {
                    int tpj = q.p[j], oj = q.o[j];
                    if(stn + oj <= addr && stn + oj + b[tpj].s > addr) {
                        tpn = tpj;
                        stn += oj;
                        f2 = 1;
                        break;
                    }
                }
                if(!f2) {
                    f = 0;
                    break;
                }
                //cout << tpn << ' ' << stn << '\n';
            }
            if(!f) {
                cout << "ERR\n";
                continue;
            }
            tpn = tp;
            stn = st;
            cout << start;
            while(tpn > 4) {
                Struct &q = b[tpn];
                int k = q.p.size() - 1;
                for(int j = 1; j <= k; j++) {
                    int tpj = q.p[j], oj = q.o[j];
                    if(stn + oj <= addr && stn + oj + b[tpj].s > addr) {
                        tpn = tpj;
                        stn += oj;
                        cout << '.' << q.str[j];
                        break;
                    }
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
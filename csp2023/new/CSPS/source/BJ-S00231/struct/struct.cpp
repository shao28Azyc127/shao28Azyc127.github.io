#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;

struct Struct {
    ll sz, smx, rsz;
    struct Data {
        ll sz;
        string type, name;
    };
    vector<Data> dt;
};

struct Hasher {
    ll operator () (const string& x) const {
        ll ret = 0;
        for (int i = 0; i < x.size(); ++i) {
            ret = ret * 26 + x[i] - 'a';
        }
        return ret;
    }
};

unordered_map<string, Struct, Hasher> sm;
unordered_map<string, pair<ll, string>, Hasher> gm;

inline bool isbasic(const string& x) {
    return x == "byte" || x == "short" || x == "int" || x == "long";
}
inline ll getsz(const string& x) {
    if (x == "byte") return 1;
    else if (x == "short") return 2;
    else if (x == "int") return 4;
    else if (x == "long") return 8;
    return sm[x].rsz;
}
inline ll getszd(const string& x) {
    if (x == "byte") return 1;
    else if (x == "short") return 2;
    else if (x == "int") return 4;
    else if (x == "long") return 8;
    return sm[x].smx;
}

char tmp[11005];

bool find(Struct& s, ll addr, string& ans) {
    if (addr >= s.rsz) return false;
    vector<Struct::Data>& dts = s.dt;
    ll curaddr = 0, lac = 0;
    string name, type;
    for (int i = 0; i < dts.size(); ++i) {
        if (curaddr > addr) {
            break;
        }
        lac = curaddr;
        name = dts[i].name;
        type = dts[i].type;
        curaddr += s.smx;
    }
    ans += "." + name;
    if (isbasic(type)) {
        if (addr >= curaddr) return false;
        else return true;
    }
    addr -= lac;
    return find(sm[type], addr, ans);
}

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int q;
    scanf("%d", &q);
    ll lastaddr = 0;
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            char tmp1[15], tmp2[15];
            int k;
            scanf("%s%d", tmp1, &k);
            Struct& st = sm[tmp1];
            //st.sz = st.smx = 0;
            for (int i = 1; i <= k; ++i) {
                scanf("%s%s", tmp1, tmp2);
                ll sz = getsz(tmp1);
                st.dt.push_back({ sz, tmp1, tmp2 });
                st.sz += sz;
                st.smx = max(st.smx, getszd(tmp1));
            }
            st.rsz = st.sz;
            if (st.rsz % st.smx) st.rsz = ceil(1.0 * st.rsz / st.smx) * st.smx;
            printf("%lld %lld\n", st.rsz, st.smx);
        } else if (op == 2) {
            char tmp1[15], tmp2[15];
            scanf("%s%s", tmp1, tmp2);
            ll sz = 0;
            if (isbasic(tmp1)) sz = getsz(tmp1);
            else sz = sm[tmp1].smx;
            if (lastaddr % sz) lastaddr = ceil(1.0 * lastaddr / sz) * sz;
            printf("%lld\n", lastaddr);
            gm[tmp2] = { lastaddr, tmp1 };
            lastaddr += sz;
        } else if (op == 3) {
            scanf("%s", tmp);
            string s = tmp;
            int g = s.find('.');
            string nh;
            ll ans;
            if (g == -1) {
                nh = gm[s].second;
                ans = gm[s].first;
            } else {
                string gg = s.substr(0, g);
                nh = gm[gg].second;
                ans = gm[gg].first;
                s += '.';
                int la = g + 1, nx;
                while ((nx = s.find('.', la)) != string::npos) {
                    string th = s.substr(la, nx - la);
                    Struct& cs = sm[nh];
                    vector<Struct::Data>& dts = cs.dt;
                    for (int i = 0; i < dts.size(); ++i) {
                        //printf("%d %s %s %lld\n", i, dts[i].name.c_str(), dts[i].type.c_str(), dts[i].sz);
                        if (dts[i].name == th) {
                            nh = dts[i].type;
                            break;
                        }
                        ans += cs.smx;
                    }
                    //printf("%s(%lld) ", s.substr(la, nx - la).c_str(), ans);
                    la = nx + 1;
                }
                //printf("\n");
            }
            printf("%lld\n", ans);
        } else {
            ll addr;
            scanf("%lld", &addr);
            string ans, typ;
            ll lo = 0;
            for (auto& i : gm) {
                if (i.second.first > addr) {
                    break;
                }
                ans = i.first;
                lo = i.second.first;
                typ = i.second.second;
            }
            addr -= lo;
            if (isbasic(typ)) {
                ll sz = getsz(typ);
                if (addr > sz) printf("ERR\n");
                else printf("%s\n", ans.c_str());
                continue;
            }
            if (find(sm[typ], addr, ans)) printf("%s\n", ans.c_str());
            else printf("ERR\n");
        }
    }
    return 0;
}
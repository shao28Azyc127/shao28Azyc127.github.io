#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
int n, cnt = 3;
string idtos[105];
map<string, int> id, pos;
struct Str {
    int SZ, a;
    map<string, int> pos;
    vector<tuple<int, int, string>> vec; // delta pos, id, name
} s[105];
vector<tuple<int, int, string>> fulvec;
vector<string> tmp;
string ans;
void dfs(int sid, int addr) {
    if (sid <= 3) {
        if (addr >= s[sid].SZ) ans = "ERR";
        return;
    }
    if (!s[sid].vec.size()) {
        ans = "ERR"; return;
    }
    ans += '.';
    int l = 0, r = s[sid].vec.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (get<0>(s[sid].vec[mid]) > addr) r = mid - 1;
        else l = mid;
    }
    ans += get<2>(s[sid].vec[l]);
    dfs(get<1>(s[sid].vec[l]), addr - get<0>(s[sid].vec[l]));
}
signed main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    string Tmp = "byte"; idtos[0] = Tmp;
    id[Tmp] = 0; s[0].SZ = s[0].a = 1;
    Tmp = "short"; idtos[1] = Tmp;
    id[Tmp] = 1; s[1].SZ = s[1].a = 2;
    Tmp = "int"; idtos[2] = Tmp;
    id[Tmp] = 2; s[2].SZ = s[2].a = 4;
    Tmp = "long"; idtos[3] = Tmp;
    id[Tmp] = 3; s[3].SZ = s[3].a = 8;
    int fulo = 0;
    rep(i, 1, n) {
        int cmd, addr;
        string typ, name, tmptyp, tmpname;
        cin >> cmd;
        if (cmd == 1) {
            cin >> typ >> addr; // k
            id[typ] = ++cnt; idtos[cnt] = typ;
            rep(j, 1, addr) {
                cin >> tmptyp >> tmpname;
                int idd = id[tmptyp];
                s[cnt].vec.emplace_back(0, idd, tmpname);
                s[cnt].a = max(s[cnt].a, s[idd].a);
                s[cnt].pos[tmpname] = s[cnt].vec.size() - 1;
            }
            int nowo = 0;
            rep(j, 1, addr - 1) {
                int idnow = get<1>(s[cnt].vec[j]);
                nowo += s[get<1>(s[cnt].vec[j - 1])].SZ;
                while (nowo % s[idnow].a) ++nowo;
                get<0>(s[cnt].vec[j]) = nowo;
            }
            nowo += s[get<1>(s[cnt].vec.back())].SZ;
            while (nowo % s[cnt].a) ++nowo;
            s[cnt].SZ = nowo;
            cout << s[cnt].SZ << ' ' << s[cnt].a << '\n';
        } else if (cmd == 2) {
            cin >> typ >> name;
            int idd = id[typ];
            while (fulo % s[idd].a) ++fulo;
            fulvec.emplace_back(fulo, idd, name);
            cout << fulo << '\n';
            fulo += s[idd].SZ;
            pos[name] = fulvec.size() - 1;
        } else if (cmd == 3) {
            tmp.clear();
            cin >> name;
            int lst = 0, pos = 0, sz = name.length();
            while (pos < sz) {
                if (name[pos] != '.') ++pos;
                else {
                    // lst ~ pos - 1
                    tmp.emplace_back(name.substr(lst, pos - lst));
                    ++pos;
                    lst = pos;
                }
            }
            tmp.emplace_back(name.substr(lst));
            int sid = ::pos[tmp[0]], now = get<0>(fulvec[sid]);
            sid = get<1>(fulvec[sid]);
            sz = tmp.size();
            rep(i, 1, sz - 1) {
                int poss = s[sid].pos[tmp[i]];
                now += get<0>(s[sid].vec[poss]);
                sid = get<1>(s[sid].vec[poss]);
            }
            cout << now << '\n';
        } else {
            cin >> addr;
            if (!fulvec.size()) {
                cout << "ERR\n";
                continue;
            }
            ans = "";
            int l = 0, r = fulvec.size() - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (get<0>(fulvec[mid]) > addr) r = mid - 1;
                else l = mid;
            }
            int sid = get<1>(fulvec[l]);
            ans += get<2>(fulvec[l]);
            dfs(sid, addr - get<0>(fulvec[l]));
            cout << ans << '\n';
            // cerr << endl;
        }
    }
    // for (auto &tmp: s[id["b"]].vec) cerr << "qwq: " << get<0>(tmp) << endl;
    return 0;
}
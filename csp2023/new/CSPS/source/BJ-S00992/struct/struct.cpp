#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, string> pis;
const int N = 1005;
map <string, int> tyid;
struct per2 {
    LL St; pis tp;
};
struct per1 {
    vector <per2> vec;
} p[N];
LL sz[N], fac[N];
string tname[N];
vector <per2> var;
LL Last = 0;
LL Up(LL x, LL y) { return (x + y - 1) / y * y; }
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(0);
    int ttot = 0;
    tyid["byte"] = ++ttot; fac[ttot] = sz[ttot] = 1; tname[ttot] = "byte";
    tyid["short"] = ++ttot; fac[ttot] = sz[ttot] = 2; tname[ttot] = "short";
    tyid["int"] = ++ttot; fac[ttot] = sz[ttot] = 4; tname[ttot] = "int";
    tyid["long"] = ++ttot; fac[ttot] = sz[ttot] = 8; tname[ttot] = "long";
    int T; cin >> T;
    for (int op; T--; ) {
        cin >> op;
        if (op == 1) {
            string S; int k; cin >> S >> k;
            tyid[S] = ++ttot; tname[ttot] = S;
            for (int i = 1; i <= k; i++) {
                string T; cin >> T;
                int tid = tyid[T];
                cin >> T;
                if (i > 1) sz[ttot] = Up(sz[ttot], fac[p[ttot].vec.back().tp.first]);
                sz[ttot] = Up(sz[ttot], fac[tid]);
                p[ttot].vec.push_back({sz[ttot], pis(tid, T)});
                sz[ttot] += sz[tid];
                fac[ttot] = max(fac[ttot], fac[tid]);
            }
            cout << Up(sz[ttot], fac[ttot]) << ' ' << fac[ttot] << '\n';
            // printf("%lld %lld\n", sz[ttot], fac[ttot]);
        } else if (op == 2) {
            string S, T; cin >> S >> T;
            int tid = tyid[S];
            Last = Up(Last, fac[tid]);
            var.push_back({Last, pis(tid, T)});
            cout << Last << '\n';
            // printf("%lld\n", Last);
            // Last += sz[tid];
            Last += Up(sz[tid], fac[tid]);
        } else if (op == 3) {
            string S, T = ""; cin >> S;
            S.push_back('.');
            LL now = 0;
            int tpos = 0;
            for (int i = 0; i < S.size(); i++) {
                if (S[i] == '.') { tpos = i; break; }
                T.push_back(S[i]);
            }
            int ntid = 0;
            for (auto v : var) if (T == v.tp.second) { now = v.St; ntid = v.tp.first; break; }
            T = "";
            for (int i = tpos + 1; i < S.size(); i++) {
                if (S[i] == '.') {
                    // assert(ntid > 4);
                    for (auto v : p[ntid].vec) {
                        if (T == v.tp.second) { now += v.St; ntid = v.tp.first; break; }
                    }
                    T = "";
                } else T.push_back(S[i]);
            }
            cout << now << '\n';
            // printf("%lld\n", now);
        } else if (op == 4) {
            LL Q; cin >> Q;
            if (var.empty()) { cout << "ERR" << '\n'; continue; }

            int ntid = 0; bool flag = 1;
            string S = "";
            for (int i = 0; i < var.size(); i++) {
                if (i + 1 == var.size() || Q < var[i + 1].St) {
                    if (var[i].St + sz[var[i].tp.first] <= Q) flag = 0;
                    else Q -= var[i].St, ntid = var[i].tp.first, S = var[i].tp.second;
                    break;
                }
            }
            // cout << "Q = " << Q << ", ntid = " << ntid << endl;
            if (!flag) { cout << "ERR" << '\n'; continue; }
            while (ntid > 4) {
                auto &pt = p[ntid].vec;
                for (int i = 0; i < pt.size(); i++) {
                    // cout << "de: i = " << i << ", St = " << pt[i].St << endl;
                    if (i + 1 == pt.size() || Q < pt[i + 1].St) {
                        // cout << "i = " << i << ", St = " << pt[i + 1].St << endl;
                        if (pt[i].St + sz[pt[i].tp.first] <= Q) flag = 0;
                        else Q -= pt[i].St, ntid = pt[i].tp.first, S.push_back('.'), S = S + pt[i].tp.second;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (!flag) { cout << "ERR" << '\n'; continue; }
            cout << S << '\n';
        }
    }
    return 0;
}
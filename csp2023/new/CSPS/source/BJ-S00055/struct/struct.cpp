

#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#define pii pair<int, int>
#define pss pair<string, string>
#define FR first
#define SE second
#define mp make_pair
#define ll long long

const int MAXN = 1e2+9;
using namespace std;

struct Type {
    int amt;
    unordered_map<string, int> h;
    vector<pss> var;
}def[MAXN];

int Q, cur = -1;
int siz[MAXN], tot;
unordered_map<string, int> h, hn;
int cnt, start[MAXN];
string type[MAXN], name[MAXN];
set<pii > st;

int main () {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    tot = 4;
    h["byte"] = 1, h["short"] = 2, h["int"] = 3, h["long"] = 4;
    siz[1] = 1, siz[2] = 2, siz[3] = 4, siz[4] = 8;

    cin >> Q;
    int op, k;
    string str, v, n;
    while (Q--) {
        cin >> op;
        if (op == 1) {
            cin >> str >> k;
            h[str] = ++tot;

            int maxn = 0;
            for (int i = 1; i < k+1; i++) {
                cin >> v >> n;
                def[tot].var.push_back(mp(v, n));
                def[tot].h[n] = i-1;
                maxn = max(maxn, siz[h[v]]);
            }
            siz[tot] = maxn*k;
            def[tot].amt = maxn;

            cout << siz[tot] << ' ' << maxn << '\n';
        }
        else if (op == 2) {
            cin >> type[++cnt] >> n;
            v = type[cnt], name[cnt] = n;

            hn[n] = cnt;
            start[cnt] = cur+1;
            cur += siz[h[v]];
            st.insert(mp(cur, cnt));
            cout << start[cnt] << '\n';
        }
        else if (op == 3) {
            cin >> str;
            n = "";
            vector<string> nm, tp;
            for (int i = 0; i < (int)str.length(); i++) {
                if (str[i] == '.') {
                    if (nm.size() == 0) tp.push_back(type[hn[n]]);
                    else tp.push_back(def[h[tp[tp.size()-1]]].var[def[h[tp[tp.size()-1]]].h[n]].FR);
                    nm.push_back(n), n = "";
                    continue;
                }
                n += str[i];
            }
            nm.push_back(n);
            if (nm.size() == 0) tp.push_back(type[hn[n]]);
            else tp.push_back(def[h[tp[tp.size()-1]]].var[def[h[tp[tp.size()-1]]].h[n]].FR);
            // for (int i = 0; i < nm.size(); i++) cerr << nm[i] << ' ';
            // cerr << '\n';
            // for (int i = 0; i < tp.size(); i++) cerr << tp[i] << ' ';
            // cerr << '\n';
            int res = start[hn[nm[0]]];
            if (nm.size() == 1) {
                cout << res << '\n';
                continue;
            }
            for (int i = 1; i < (int)nm.size(); i++) {
                n = nm[i], v = tp[i-1];
                res += (def[h[v]].h[n]) * def[h[v]].amt;
            }
            cout << res << '\n';
        }
        else {
            cin >> k;
            if (k > cur) cout << "ERR\n";
            else {
                if (st.empty()) {cout << "ERR\n";continue;}
                vector<string> res;
                set<pii>::iterator it = st.upper_bound(mp(k, 2e9));
                n = name[(*it).SE], v = type[(*it).SE];
                k -= start[hn[n]];
                res.push_back(n);
                while (h[v] > 4) {
                    int t = k / def[h[v]].amt;
                    res.push_back(def[h[v]].var[t].SE);
                    k %= def[h[v]].amt;
                    v = def[h[v]].var[t].FR;
                }
                if (k >= siz[h[v]]) cout << "ERR\n";
                else {
                    for (int i = 0; i < res.size()-1; i++) cout << res[i] << '.';
                    cout << res[res.size()-1] << '\n';
                }
            }
        }
    }

    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
5
1 a 2
short aa
int ab
1 b 2
a ba
long bb
2 b x
3 x.ba.ab
4 10
*/
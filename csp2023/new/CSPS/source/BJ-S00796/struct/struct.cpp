#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#define maxn 205
#define mod 998244353
#define ll long long
#define eps 1e-7
using namespace std;
int T, now = 4;
map <string, int> id;
struct node {
    string name;
    int m;
    int tp[maxn];
    string nam[maxn];
    map <string, int> id;
    ll siz, st[maxn]; int req;
} t[maxn];
int E = 0;
ll addr = 0;
struct elem {
    string name;
    int tp;
    ll st;
} e[maxn];
map <string, int> El;
ll st[maxn];
ll calc (ll x, int y) {
    if (x == 0) return 0;
    return 1ll * ((x + y - 1) / y) * y;
}
string TT[maxn];
int main () {
    freopen ("struct.in", "r", stdin);
    freopen ("struct.out", "w", stdout);
    id["byte"] = 1, id["short"] = 2, id["int"] = 3, id["long"] = 4;
    t[1].req = t[1].siz = 1, t[2].req = t[2].siz = 2;
    t[3].req = t[3].siz = 4, t[4].req = t[4].siz = 8;
    t[1].name = "byte", t[2].name = "short", t[3].name = "int", t[4].name = "long";
    scanf ("%d", &T);
    int op;
    string TYPE, NAME;
    while (T--) {
        scanf ("%d", &op);
        if (op == 1) {
            now++;
            cin >> t[now].name >> t[now].m;
            id[t[now].name] = now;
            t[now].siz = t[now].req = 0;
            for (int i = 1; i <= t[now].m; i++) {
                cin >> TYPE >> NAME;
                int typ = id[TYPE];
                t[now].st[i] = calc(t[now].siz, t[typ].req);
                t[now].siz = calc (t[now].siz, t[typ].req) + t[typ].siz;
                t[now].req = max (t[now].req, t[typ].req);
                t[now].tp[i] = typ, t[now].nam[i] = NAME;
                t[now].id[NAME] = i;
            }
            t[now].siz = calc (t[now].siz, t[now].req);
            printf ("%lld %d\n", t[now].siz, t[now].req);
        } else if (op == 2) {
            cin >> TYPE >> NAME;
            E++, e[E].name = NAME, e[E].tp = id[TYPE];
            e[E].st = calc (addr, t[e[E].tp].req);
            addr = e[E].st + t[e[E].tp].siz;
            st[E] = e[E].st; El[NAME] = E;
            printf ("%lld\n", st[E]);
        } else if (op == 3) {
            cin >> NAME;
            int len = NAME.length(); ll ans = 0;
            int N = 0, lst = 0;
            for (int i = 0; i < len; i++) {
                if (NAME[i] == '.') {
                    TT[++N] = NAME.substr(lst, i-lst);
                    lst = i+1;
                }
            }
            TT[++N] = NAME.substr(lst, len-lst);
            int ind = El[TT[1]]; ans = st[ind];
            int TYP = e[ind].tp;
            for (int i = 2; i <= N; i++) {
                int _ = t[TYP].id[TT[i]];
                ans += t[TYP].st[_];
                TYP = t[TYP].tp[_];
            }
            printf ("%lld\n", ans);
        } else {
            ll ADDR;
            scanf ("%lld", &ADDR);
            int ind = upper_bound (st+1, st+E+1, ADDR) - st - 1, TYP;
            ADDR -= st[ind], TYP = e[ind].tp;
            int N = 1; TT[N] = e[ind].name;
            while (TYP > 4) {
                ind = upper_bound (t[TYP].st+1, t[TYP].st+t[TYP].m+1, ADDR) - t[TYP].st - 1;
                TT[++N] = t[TYP].nam[ind], ADDR -= t[TYP].st[ind];
                TYP = t[TYP].tp[ind];
            }
            if (ADDR < t[TYP].siz) {
                for (int i = 1; i <= N; i++) {
                    cout << TT[i];
                    if (i != N) cout << '.';
                }
                cout << endl;
            } else cout << "ERR" << endl;
        }
    }
    return 0;
}
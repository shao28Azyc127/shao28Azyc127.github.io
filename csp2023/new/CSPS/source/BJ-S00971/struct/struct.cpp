#include <bits/stdc++.h>
#define Cl(x, y) ((x) / (y) + !!((x) % (y))) * (y)
using namespace std;
struct son {
    string n;//name
    int i;//typeid
    int sz;//size
    int al;//align
};
struct type {
    string n;//name
    vector<son> cn;//sons
    int sz;//size
    int al;//align
};
vector<type> tv;//typeid->type
map<string, int> tp;//typename->typeid
void nwtp(string n, int s) {//newtype(name,type)
    type t; t.n = n; t.sz = t.al = s;
    tp[t.n] = tv.size(); tv.push_back(t);
}
void nwtp() {//newtype(op1)
    int k; cin >> k; type t; cin >> t.n;
    while (k--) {
        son c; string tn;
        cin >> tn >> c.n; c.i = tp[tn];
        c.sz = tv[c.i].sz; c.al = tv[c.i].al;
        t.sz = Cl(t.sz, c.al) + c.sz; t.al = max(t.al, c.al);
    }
    t.sz = Cl(t.sz, t.al);
    tp[t.n] = tv.size(); tv.push_back(t);
}
long long S;
struct elem {//element
    string n;//name
    type t;//type
    int st;//start position
};
vector<elem> ev;//element id->element
map<string, int> ep;//element name->element id
void nwel() {//new element
    string tn; elem e; cin >> tn >> e.n; e.t = tv[tp[tn]];
    e.st = Cl(S, e.t.al); S = e.st + e.t.sz;
    ep[e.n] = ev.size(); ev.push_back(e);
}
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    nwtp("byte", 1); nwtp("short", 2); nwtp("int", 4); nwtp("long", 8);
    int n; cin >> n;
    while (n--) {
        int op; cin >> op;
        if (op == 1) nwtp();
        if (op == 2) nwel();
        if (op == 3) {

        }
    }
    return 0;
}
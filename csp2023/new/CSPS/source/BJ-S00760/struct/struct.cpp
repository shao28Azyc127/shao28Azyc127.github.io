#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map <ll, string> mem;
unordered_map <string, vector <string> > stk;
unordered_map <string, ll> id;
ll cnt = 0;
ll up(ll x, ll d) {
    ll mod = x % d;
    if(mod == 0) mod = d;
    return x + d - mod;
}
void define_basic(string type_name, string name, int d, ll sz) {
    cnt = up(cnt, d), sz = up(sz, d);
    mem[cnt] = name, id[name] = cnt;
    cnt += sz;
}
pair <string, string> divide(string x) {
    string type_name = "", name2 = ""; int len = x.size(), pos = 0;
    for(int i = 0; i < len; i++) {
        if(x[i] == ' ') { pos = i + 1; break; }
        type_name += x[i];
    }
    for(int i = pos; i < len; i++) name2 += x[i];
    return {type_name, name2};
}
ll define_struct(string pre, string name) {
    ll sz = 0, mx = 1;
    for(auto x : stk[name]) {
        pair <string, string> p = divide(x);
        string type_name = p.first, name2 = p.second;
        string real_name = pre + "." + name2;
        if(type_name == "byte")
            { define_basic(type_name, real_name, 1, 1); sz += 1, mx = max(mx, 1ll); }
        else if(type_name == "short")
            { define_basic(type_name, real_name, 2, 2); sz += 2, mx = max(mx, 2ll); }
        else if(type_name == "int")
            { define_basic(type_name, real_name, 4, 4); sz += 4, mx = max(mx, 4ll); }
        else if(type_name == "long")
            { define_basic(type_name, real_name, 8, 8); sz += 8, mx = max(mx, 8ll); }
        else sz += define_struct(real_name, type_name);
    }
    cnt = up(cnt, mx), sz = up(cnt, mx);
    id[name] = cnt; cnt += sz;
    return sz;
}
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n; cin >> n;
    while(n--) {
        int op; cin >> op;
        if(op == 1) {
            string name; cin >> name; int m; cin >> m;
            while(m--) {
                string x; getline(cin, x);
                stk[name].push_back(x);
            }
        }
        else if(op == 2) {
            string type_name, name; cin >> type_name >> name;
            if(type_name == "byte")
                define_basic(type_name, name, 1, 1);
            else if(type_name == "short")
                define_basic(type_name, name, 2, 2);
            else if(type_name == "int")
                define_basic(type_name, name, 4, 4);
            else if(type_name == "long")
                define_basic(type_name, name, 8, 8);
            else define_struct(name, type_name);
        }
        else if(op == 3) {
            string name; cin >> name;
            cout << id[name] << endl;
        }
        else {
            ll p; cin >> p;
            if(mem[p] != "") cout << mem[p] << endl;
            else cout << "ERR" << endl;
        }
    }
    return 0;
}
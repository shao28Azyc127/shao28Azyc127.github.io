#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define nrep(i, a, b) for(int i = (a); i >= (b); --i)
#define put(x) printf("%lld ", x)
#define putl(x) printf("%lld ", x)
#define endl() putchar('\n')
using namespace std;

typedef long long ll;
inline ll read() {
    ll x;
    cin >> x;
    return x;
}

const int N = 1e5 + 10;

struct var {
    string type, name;
    ll pos;
};

string A = "_";
vector<var> vec[N];
map<string, int> id;
map<string, ll> siz, need;
int top;

vector<string> lst;

bool sub4();

inline void calc(ll &x, ll mod) {
    ll k = x % mod;
    if(k) x += mod - k;
}

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    siz["byte"] = 1;
    siz["short"] = 2;
    siz["int"] = 4;
    siz["long"] = 8;
    need["byte"] = 1;
    need["short"] = 2;
    need["int"] = 4;
    need["long"] = 8;

    id[A] = ++top;

    cin.tie(0);
    int n = read();
    while(n--) {
        int op = read();
        // endl(), put(n), put(op), endl();
        if(op == 1) {
            string x; cin >> x;
            id[x] = ++top;
            int k = read(); ll maxs = 0;
            rep(i, 1, k) {
                string type, name;
                cin >> type >> name;
                vec[top].push_back({type, name});
                maxs = max(maxs, need[type]);
            }
            ll pos = 0;
            for(auto &v : vec[top]) {
                calc(pos, need[v.type]);
                v.pos = pos;
                pos += siz[v.type];
            }
            calc(pos, maxs);
            siz[x] = pos;
            need[x] = maxs;
            putl(pos), putl(maxs), endl();
        }
        if(op == 2) {
            string type, name;
            cin >> type >> name;
            string x = A;
            ll maxs = max(need[x], need[type]);
            vec[1].push_back({type, name});
            ll pos = 0;
            for(auto &v : vec[1]) {
                calc(pos, need[v.type]);
                v.pos = pos;
                pos += siz[v.type];
            }
            calc(pos, maxs);
            siz[x] = pos;
            need[x] = maxs;
            putl(vec[1].back().pos), endl();
        }
        if(op == 3) {
            string str, cur = ""; cin >> str;
            str.push_back('.');
            lst.clear();
            for(char c : str) {
                if(c != '.') cur.push_back(c);
                else lst.push_back(cur), cur = "";
            }
            string now = A; ll pos = 0;
            for(auto &name : lst) {
                int i = id[now];
                for(auto &v : vec[i]) if(v.name == name) {
                    pos += v.pos;
                    now = v.type;
                }
            }
            putl(pos), endl();
        }
        if(op == 4) {
            if(!sub4()) puts("ERR");
        }
    }
    return 0;
}

bool sub4() {
    ll pos = read();
    string now = A, ans = "";
    int i;
    while((i = id[now])) {
        bool flag = 0;
        for(auto &v : vec[i]) {
            if(pos >= v.pos && pos < v.pos + siz[v.type]) {
                pos -= v.pos;
                ans.append(v.name + '.');
                now = v.type;
                flag = 1;
                break;
            }
        }
        if(!flag) return 0;
    }
    ans.pop_back();
    cout << ans << endl;
    return 1;
}

























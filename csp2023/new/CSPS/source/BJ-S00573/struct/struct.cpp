#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef long long LL;

struct node {
    string name;
    string tp;
    node() {

    }
    node(string s1, string s2) {
        tp = s1;
        name = s2;
        return;
    }
};

inline LL max(LL a, LL b) {
    return a > b ? a : b;
}

inline bool check(string &s) {
    return s == "byte" || s == "short" || s == "int" || s == "long";
}

inline string getnxt(string &str, int &pos, int &len) {
    string res;
    while (pos < len && str[pos] != '.') {
        res += str[pos++];
    }
    pos++;
    return res;
}

int n;
LL tot;
map<string, LL> qu;
map<string, LL> Type;
map<string, vector<node> > mp;
vector<node> ls;
vector<string> res;

void print() {
    int len = res.size();
    cout << res[0];
    for (register int i = 1; i < len; i++) {
        cout << '.' << res[i];
    }
    cout << endl;
    res.clear();
    return;
}

void PRINT() {
    for (map<string, LL> :: iterator it = qu.begin(); it != qu.end(); it++) {
        cout << it -> first << ' ' << it -> second << endl;
    }
    cout << endl;
    for (map<string, LL> :: iterator it = Type.begin(); it != Type.end(); it++) {
        cout << it -> first << ' ' << it -> second << endl;
    }
    cout << endl;
    for (map<string, vector<node> > :: iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it -> first << endl;
        for (register int i = 0; i < (it -> second).size(); i++) {
            cout << (it -> second)[i].tp << ' ' << (it -> second)[i].name << endl;
        }
    }
    cout << endl;
    for (register int i = 0; i < ls.size(); i++) {
        cout << ls[i].tp << ' ' << ls[i].name << endl;
    }
    cout << endl;
    return;
}

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Type["byte"] = 1;
    Type["short"] = 2;
    Type["int"] = 4;
    Type["long"] = 8;
    qu["byte"] = 1;
    qu["short"] = 2;
    qu["int"] = 4;
    qu["long"] = 8;
    cin >> n;
    bool flag;
    int op, k, num, pos;
    LL sz, mx, ans;
    string str, s1, s2;
    vector<node> vct;
    while (n--) {
        cin >> op;
        if (op == 1) {
            cin >> str >> k;
            mx = sz = 0;
            vct.clear();
            for (register int i = 0; i < k; i++) {
                cin >> s1 >> s2;
                vct.push_back(node(s1, s2));
                mx = max(mx, qu[s1]);
                if (sz % qu[s1]) {
                    sz += qu[s1] - sz % qu[s1];
                }
                sz += Type[s1];
            }
            if (sz % mx) {
                sz += mx - sz % mx;
            }
            cout << sz << ' ' << mx << endl;
            qu[str] = mx;
            Type[str] = sz;
            mp[str] = vct;
        }
        else if (op == 2) {
            cin >> s1 >> s2;
            cout << tot << endl;
            ls.push_back(node(s1, s2));
            if (tot % qu[s1]) {
                tot += qu[s1] - tot % qu[s1];
            }
            tot += Type[s1];
        }
        else if (op == 3) {
            cin >> str;
            ans = pos = 0;
            k = str.size();
            s1 = getnxt(str, pos, k);
            num = 0;
            while (ls[num].name != s1) {
                if (ans % qu[ls[num].tp]) {
                    ans += qu[ls[num].tp] - ans % qu[ls[num].tp];
                }
                ans += Type[ls[num++].tp];
            }
            if (ans % qu[ls[num].tp]) {
                ans += qu[ls[num].tp] - ans % qu[ls[num].tp];
            }
            s2 = ls[num].tp;
            if (check(s2)) {
                cout << ans << ' ' << op << endl;
                break;
            }
            vct = mp[s2];
            while (pos < k) {
                s1 = getnxt(str, pos, k);
                num = 0;
                while (vct[num].name != s1) {
                    if (ans % qu[vct[num].tp]) {
                        ans += qu[vct[num].tp] - ans % qu[vct[num].tp];
                    }
                    ans += Type[vct[num++].tp];
                }
                if (ans % qu[vct[num].tp]) {
                    ans += qu[vct[num].tp] - ans % qu[vct[num].tp];
                }
                s2 = vct[num].tp;
                if (check(s2)) {
                    break;
                }
                vct = mp[s2];
            }
            cout << ans << endl;
        }
        else {
            cin >> mx;
            ans = pos = 0;
            k = ls.size();
            flag = 1;
            while (mx >= ans && pos < k) {
                if (ans % qu[ls[pos].tp]) {
                    ans += qu[ls[pos].tp] - ans % qu[ls[pos].tp];
                    if (mx < ans) {
                        break;
                    }
                }
                if (mx < ans + Type[ls[pos].tp]) {
                    flag = 0;
                    res.push_back(ls[pos].name);
                    break;
                }
                ans += Type[ls[pos++].tp];
            }
            if (flag) {
                cout << "ERR\n";
                continue;
            }
            s1 = ls[pos].tp;
            if (check(s1)) {
                print();
                continue;
            }
            vct = mp[s1];
            while (mx >= ans) {
                pos = 0;
                k = vct.size();
                flag = 1;
                while (pos < k) {
                    if (ans % qu[vct[pos].tp]) {
                        ans += qu[vct[pos].tp] - ans % qu[vct[pos].tp];
                        if (mx < ans) {
                            cout << "ERR\n";
                            break;
                        }
                    }
                    if (mx < ans + Type[vct[pos].tp]) {
                        flag = 0;
                        break;
                    }
                    ans += Type[vct[pos++].tp];
                }
                if (flag) {
                    cout << "ERR\n";
                    break;
                }
                s1 = vct[pos].tp;
                s2 = vct[pos].name;
                res.push_back(s2);
                if (check(s1)) {
                    print();
                    break;
                }
                vct = mp[s1];
            }
        }
        // PRINT();
    }
    return 0;
}
#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<vector>
#include<unordered_map>
using namespace std;

#define int long long

int n;

#define mp make_pair

unordered_map<string, vector<pair<string, string> > > vals;
unordered_map<string, int> typesiz;
unordered_map<string, int> duiqi;
unordered_map<string, int> pos;
unordered_map<string, string> valtype;

bool isBasic(string s) {
    return (s == "int" || s == "short" || s == "long" || s == "byte");
}

int anspos = 0, nowpos = 0;

vector<string> pths;

void getAdd(string nowtype) {
    for (int i = 1;i < pths.size();i++) {
        for (int j = 0;j < vals[nowtype].size();j++) {
            string nxt = pths[i];
            if (vals[nowtype][j].second != nxt) {
                anspos = ceil((anspos * 1.0) / duiqi[vals[nowtype][j].first]) * duiqi[vals[nowtype][j].first];
                anspos += typesiz[vals[nowtype][j].first];
            }
            else {
                nowtype = vals[nowtype][j].first;
                break;
            }
        }
    }
    anspos = ceil((anspos * 1.0) / duiqi[nowtype]) * duiqi[nowtype];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    typesiz["byte"] = duiqi["byte"] = 1;
    typesiz["short"] = duiqi["short"] = 2;
    typesiz["int"] = duiqi["int"] = 4;
    typesiz["long"] = duiqi["long"] = 8;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int op;
        cin >> op;
        if (op == 1) {
            string s;
            int k;
            cin >> s >> k;
            vector<pair<string, string> > now;
            int nowduiqi, nowsiz;
            nowduiqi = nowsiz = 0;
            for (int i = 1;i <= k;i++) {
                string t, name;
                cin >> t >> name;
                nowduiqi = max(nowduiqi, typesiz[t]);
                nowsiz = ceil((nowsiz * 1.0) / duiqi[t]) * duiqi[t];
                nowsiz += typesiz[t];
                now.push_back(mp(t, name));
            }
            vals[s] = now;
            duiqi[s] = nowduiqi;
            typesiz[s] = nowsiz;
            cout << nowsiz << ' ' << nowduiqi << endl;
        }
        if (op == 2) {
            string t, name;
            cin >> t >> name;
            valtype[name] = t;
            nowpos = ceil((nowpos * 1.0) / duiqi[t]) * duiqi[t];
            cout << nowpos << endl;
            pos[t] = nowpos;
            nowpos += typesiz[t];
        }
        if (op == 3) {
            string s;
            cin >> s;
            s += '.';
            pths.clear();
            string now = "";
            for (int i = 0;i < s.size();i++) {
                if (s[i] == '.') {
                    pths.push_back(now);
                    now = "";
                }
                else {
                    now += s[i];
                }
            }
            anspos = pos[now];
            getAdd(valtype[pths[0]]);
            cout << anspos << endl;
        }
    }
    return 0;
}


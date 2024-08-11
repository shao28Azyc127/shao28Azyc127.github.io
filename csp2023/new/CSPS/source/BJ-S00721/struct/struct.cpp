#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<string, pair<ll, ll>> mp1;
map<pair<ll, ll>, string> mp2;
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n;
    cin >> n;
    int op;
    ll addr, curr = 0;
    string t, x, s;
    while (n--) {
        cin >> op;
        if (op == 2) {
            cin >> t >> x;
            cout << curr << '\n';
            if (t == "byte") {
                mp1[x] = {curr, curr};
                mp2[{curr, curr}] = x;
                curr++;
            } else if (t == "short") {
                mp1[x] = {curr, curr + 1};
                mp2[{curr, curr + 1}] = x;
                curr += 2;
            } else if (t == "int") {
                mp1[x] = {curr, curr + 3};
                mp2[{curr, curr + 3}] = x;
                curr += 4;
            } else {
                mp1[x] = {curr, curr + 7};
                mp2[{curr, curr + 7}] = x;
                curr += 8;
            }
        } else if (op == 3) {
            cin >> s;
            cout << mp1[s].first << '\n';
        } else {
            cin >> addr;
            bool hasFind = 0;
            for (map<pair<ll, ll>, string> :: iterator it = mp2.begin(); it != mp2.end(); it++) {
                pair<ll, ll> p = it -> first;
                string str = it -> second;
                if (addr >= p.first && addr <= p.second) {
                    cout << str << '\n';
                    hasFind = 1;
                    break;
                }
            }
            if (!hasFind) {
                cout << "ERR\n";
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, now;
string a[1000010];
map< string, int > mp;
int fun(int len) {
    int p = 0;
    for (int i = 0; i <= now + 10; i++) {
        if (p >= len) return i + 1 - p;
        if (a[i] == "") {
            if (i % len != 0) continue;
            p++;
        } else p = 0;
    }
}
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int k;
            string s, tt, nn;
            cin >> s >> k;
            for (int j = 1; j <= k; j++) cin >> tt >> nn;
        } else if (op == 2) {
            string t, ni;
            cin >> t >> ni;
            int qi;
            if (t == "byte") {
                qi = fun(1);
                mp[ni] = qi;
                a[qi] = ni;
                now++;
            } else if (t == "short") {
                qi = fun(2);
                mp[ni] = qi;
                a[qi] = ni;
                a[qi+1] = ni;
                now += 2;
            } else if (t == "int") {
                qi = fun(4);
                mp[ni] = qi;
                for (int i = qi; i <= qi + 3; i++) a[i] = ni;
                now += 4;
            } else {
                qi = fun(8);
                mp[ni] = qi;
                for (int i = qi; i <= qi + 7; i++) a[i] = ni;
                now += 8;
            }
        } else if  (op == 3) {
            string s;
            cin >> s;
            cout << mp[s] << "\n";
        } else {
            int addr;
            cin >> addr;
            if (a[addr] == "") cout << "ERR\n";
            else cout << a[addr] << "\n";
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s;
map <pair <int, string>, bool> m;

bool is(string x) {
    for (int i = 0; i < x.size() / 2; i++) {
        if (x[i] != x[x.size() - i - 1]) return false;
    }
    return true;
}
bool f(int b, string x) {
    int l = x.size();
    pair <int, string> p1; p1.first = b; p1.second = x;
    if (m[p1]) {
        return true;
    }
    if (l > 2 && is(x) && l % 2 == 0) {
        if (m[p1] == false) {
            ans++;
            m[p1] = true;
        }
        return true;
    }
    for (int k = 1; k <= l - 2; k++) {
        bool bfir, bsec;
        string fir = x.substr(0, k + 1);
        string sec = x.substr(k + 1, n - k - 1);
        pair <int, string> pf; pf.first = 0; pf.second = fir;
        pair <int, string> ps; ps.first = k + 1; ps.second = sec;
        bfir = f(b, fir);
        bsec = f(b + k + 1, sec);
        if (bfir && bsec) {
            if (m[p1] == false) {
                ans++;
                m[p1] = true;
            }
            return true;
        }
    }
    return false;
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        pair <int, string> p; p.first = i; p.second = s.substr(i,1);
        m[p] = false;
        string temp = s.substr(i,2);
        if (temp[0] == temp[1]) {
            ans++;
            pair <int, string> p2; p2.first = i; p2.second = temp;
            m[p2] = true;
        } else {
            pair <int, string> p2; p2.first = i; p2.second = temp;
            m[p2] = false;
        }
    }
    f(0, s);
    cout << ans << endl;
    return 0;
}

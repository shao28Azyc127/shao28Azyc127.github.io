

#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

typedef long long ll;
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define per(i, s, t) for (int i = t; i >= s; i++)

ll QuickPow (ll num, ll index, ll mod) {

    ll res = 1;

    while (index) {
        if (index & 1) {
            res = res * num % mod;
        }

        res = res * res % mod;
        index >>= 1;
    }

    return res;

}

const int MAXN = 3e6 + 9;
string a[MAXN];
map<string, ll> myMap;
map<string, ll> mp;
ll cur = 0;

void Solve1 () {

    string s;
    int k;

    cin >> s >> k;

    ll limit = 0;
    ll size = 0;

    rep (i, 1, k) {
        string t, n;

        cin >> t >> n;

        limit = max(limit, myMap[t]);
        size += myMap[t];
    }

    if (size % limit != 0) {
        size = (size / limit + 1) * limit;
    }

    cout << size << ' ' << limit << '\n';

}

void Solve2 () {

    string t, n;

    cin >> t >> n;

    mp[n] = cur;
    
    rep (i, cur, cur + myMap[t]) {
        a[i] = n;
    }

    cout << cur << '\n';

    cur += myMap[t];

}

void Solve3 () {

    string s;

    cin >> s;

    cout << mp[s] << '\n';

}

void Solve4 () {

    int addr;
    cin >> addr;
    if (a[addr] != "") {
        cout << a[addr] << '\n';
    }

    else {
        cout << "ERR" << '\n';
    }

}

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);

    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    int n;

    cin >> n;

    myMap["byte"] = 1;
    myMap["short"] = 2;
    myMap["int"] = 4;
    myMap["long"] = 8;

    while (n--) {
        int op;

        cin >> op;

        if (op == 1) {
            Solve1();
        }

        else if (op == 2) {
            Solve2();
        }

        else if (op == 3) {
            Solve3();
        }

        else {
            Solve4();
        }
    }

    return 0;

}
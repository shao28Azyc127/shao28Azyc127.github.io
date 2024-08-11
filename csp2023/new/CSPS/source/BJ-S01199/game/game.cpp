

#include <iostream>
#include <fstream>
#include <iomanip>

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

int n;
string s;

bool Check1 (string a) {

    if (a.length() == 2 && a[0] == a[1]) {
        return true;
    }

    rep (i, 'a', 'z') {
        string b = "";

        b += (char) i, b += (char) i;

        int index = a.find(b);

        if (index == -1) {
            continue;
        }

        a.erase(a.begin() + index, a.begin() + index + 2);

        return Check1(a);
    }

    return false;

}

bool Check2 (string a) {

    if (a.length() == 2 && a[0] == a[1]) {
        return true;
    }

    rep (i, 'a', 'b') {
        string b = "";

        b += (char) i, b += (char) i;

        int index = a.find(b);

        if (index == -1) {
            continue;
        }

        a.erase(a.begin() + index, a.begin() + index + 2);

        return Check2(a);
    }

    return false;

}

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);

    ifstream inFile("game.in");
    ofstream outFile("game.out");

    inFile >> n;
    inFile >> s;

    int res = 0;

    if (n <= 800) {
        rep (l, 0, n - 2) {
            rep (r, l + 1, n - 1) {
                string cur = "";

                rep (i, l, r) {
                    cur += s[i];
                }

                if (Check1(cur)) {
                    res++;
                }
            }
        }

        outFile << res << '\n';
        return 0;
    }

    else {
        outFile << res << '\n';
    }
    
    return 0;

}
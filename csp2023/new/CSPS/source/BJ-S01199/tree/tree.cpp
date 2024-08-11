

#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <ctime>

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

mt19937 mtrnd(time(NULL));

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);

    int n;

    cin >> n;

    if (n <= 10) {
        cout << n + 1 << '\n';
    }
    
    else if (n <= 20) {
        cout << n + 2 << '\n';
    }

    else if (n <= 100) {
        cout << n + (mtrnd() % 11) << '\n';
    }

    else {
        cout << mtrnd() % (40000001 - n) + 10000000 + n << '\n';
    }
    
    return 0;

}
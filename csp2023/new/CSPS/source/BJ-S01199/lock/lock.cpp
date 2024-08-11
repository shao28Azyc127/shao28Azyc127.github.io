

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
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

int n;
int a[9][9];
map<vector<int>, int> myMap;
set<vector<int> > mySet;

void FindAll (int x) {

    vector<int> cur;

    rep (i, 1, 5) {
        cur.push_back(a[x][i]);
    }

    rep (i, 0, 4) { // 选转i
        rep (j, 1, 9) {
            cur[i] = (cur[i] + 1) % 10;

            mySet.insert(cur);
            myMap[cur]++;
        }

        cur[i] = a[x][i + 1];
    }

    rep (i, 0, 3) { // 旋转i和i+1
        rep (j, 1, 9) {
            cur[i] = (cur[i] + 1) % 10;
            cur[i + 1] = (cur[i + 1] + 1) % 10;

            mySet.insert(cur);
            myMap[cur]++;
        }

        cur[i] = a[x][i + 1], cur[i + 1] = a[x][i + 2];
    }

}

ll res = 0;

int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);

    ifstream inFile("lock.in");
    ofstream outFile("lock.out");

    inFile >> n;

    rep (i, 1, n) {
        rep (j, 1, 5) {
            inFile >> a[i][j]; 
        }

        FindAll(i);
    }

    for (vector<int> i : mySet) {
        if (myMap[i] == n) {
            res++;
        }
    }

    outFile << res << '\n';

    return 0;

}
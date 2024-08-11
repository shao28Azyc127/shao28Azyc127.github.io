#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

string mst[105];
ll mz[105];
ll mtp, mts;
map<string, ll> stop;

int getsz(string s) {
    if (s == "byte") return 1;
    if (s == "short") return 2;
    if (s == "int") return 4;
    if (s == "long") return 8;
    return 0;
}

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
        // no op=1 (special A)
        } else if (op == 2) {
            string ts, ns;
            cin >> ts >> ns;
            mst[++mtp] = ns;
            stop[ns] = mts;
            mz[mtp] = mts + getsz(ts);
            mts += getsz(ts);
        } else if (op == 3) {
            string s;
            cin >> s;
            cout << stop[s] << endl;
        } else {
            ll adr;
            cin >> adr;
            int p = upper_bound(mz + 1, mz + mtp + 1, adr) - mz;
            if (p > mtp) cout << "ERR" << endl;
            else cout << mst[p] << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 10, dnU  = -2, dU = -1;

int d[MAX_N]; // none = -3, T, F = -2, U = -1, other = i
bool o[MAX_N]; // '+'=1, '-'=0, none=-1
map<int, bool> r; // head, U=1 or nU=0

int c,t,n,m,p,q;
char op;

int main()
{
    freopen("tribool2.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        r.clear();
        for (int i=0; i<MAX_N; i++) d[i] = -3;
        for (int i=0; i<MAX_N; i++) o[i] = -1;
        cin >> n >> m;
        while (m--) {
            cin >> op;
            if (op == '-' || op == '+') {
                bool f = (op == '+')? 1: 0;
                cin >> p >> q;
                if (d[q] == -3) {
                    d[p] = q;
                    o[p] = f;
                    r[q] = 0;
                }
                else if (d[q] >= 0) {
                    d[p] = d[q];
                    o[p] = !(f^o[q]);
                }
                else {
                    d[p] = d[q];
                }
            }
            else { // TFU
                cin >> p;
                d[p] = (op == 'T' || op == 'F')? dnU: dU;
            }
        }

        for (int i=1; i<=n; i++) {
            if (d[i] == i && o[i] == 0) {
                r[i] = 1;
            }
            if (d[i] == dU && r.count(i)) {
                r[i] = 1;
            }
        }

        for (int i=1; i<=n; i++) {
            if (r[d[i]] == 1) {
                d[i] = dU;
            }
        }

        int cnt = 0;
        for (int i=1; i<=n; i++) {
            if (d[i] == dU) {
                cnt++;
            }
        }

        cout << cnt << endl;

    }
    return 0;
}

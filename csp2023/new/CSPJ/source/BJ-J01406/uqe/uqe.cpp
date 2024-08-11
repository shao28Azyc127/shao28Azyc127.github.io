#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    long long t, m, a, b, c, d;
    double tmp;

    cin >> t >> m;

    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c;

        d = b * b - 4 * a * c;

        if (d < 0) {
            cout << "NO";
        } else {
            tmp = sqrt(d);
            if (tmp = int(tmp) && (-b + int(tmp)) % (2 * a) == 0) {
                cout << -b + int(tmp) / 2 / a;
            }
        }
        cout << "\n";
    }

    return 0;
}
//want to get 50pts
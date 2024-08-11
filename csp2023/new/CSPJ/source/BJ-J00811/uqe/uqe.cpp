#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int T, M;
int wanq[1010];

int main () {
    freopen ("uqe.in", "r", stdin);
    freopen ("uqe.out", "w", stdout);
    ios::sync_with_stdio(false);

    for (int i = 0; i <= 1e3; i ++ ) {
        wanq[i] = i * i;
    }

    cin >> T >> M;
    while (T -- ) {
            //cout << T << endl;
        int a, b, c;
        cin >> a >> b >> c;
        if (b == 0 && c == 0 )  {
            cout << "0" << endl;
            continue;
        }
        int dirta = b * b - 4 * a * c;
        //cout << dirta << endl;
        if (dirta < 0) {
            cout << "NO" << endl;
            continue;
        }

        int l = 0, r = 1000;
        while (l < r) {
            int mid = l+ r >> 1;
            if (wanq[mid] >= dirta) r = mid;
            else l = mid +1;
        }

        if (wanq[l] == dirta) {
            int sx1 = l - b;
            int sx2 = 0 - b - l;
            if (dirta == 0) {
                if (sx1 % (2 * a) == 0) {
                    cout << sx1 / (2 * a) << endl;
                    continue;
                }
                else {
                    int p = __gcd(abs (sx1), abs (2 * a));
                    cout << sx1 / p << "/" << (2 * a) / p << endl;
                }
            }
            else {
                if (sx1 % (2 * a) == 0 && sx2 % (2 * a) == 0) {
                    cout << max (sx1 / (2 * a), sx2 / (2 * a)) << endl;
                }
                else if (sx1 % (2 * a) == 0 || sx2 % (2 * a) == 0) {
                    if (sx2 % (2 * a) == 0) swap (sx1, sx2);
                    double tmp = sx2 / (2 * a);
                    if (tmp > (double)sx1) {
                        int p = __gcd (abs (sx2), abs (2 * a));
                        cout << sx2 / p << "/" << (2 * a) / p << endl;
                    }
                    else {
                        cout << sx1 / (2 * a) << endl;
                    }
                }
            }
        }
    }

    return 0;
}

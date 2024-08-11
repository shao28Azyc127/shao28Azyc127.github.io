#include<iostream>
#include<cstdio>
using namespace std;

int n, lo[8][5], ans = 0;
bool ok;

int cc(int a, int b, bool up) { // a -> b, up?
    if (up)
        if (b > a)
            return b - a;
        else
            return 9 - a + b + 1;
    else
        if (b < a)
            return a - b;
        else
            return 9 - b + a + 1;
}

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < 5;j++)
            cin >> lo[i][j];

    for (int i = 0;i <= 99999;i++) {
        ok = true;
        int a = i / 10000, b = i / 1000 % 10, c = i / 100 % 10, d = i / 10 % 10, e = i % 10;

        for (int j = 0;j < n;j++) {
            int bt = (lo[j][0] != a) + (lo[j][1] != b) + (lo[j][2] != c) + (lo[j][3] != d) + (lo[j][4] != e);
            if (bt > 2 || bt == 0) {
                ok = false;
                break;
            }
            else if (bt == 2) {
                if ((lo[j][0] != a) && (lo[j][1] != b) && ( cc(a, lo[j][0], true) == cc(b, lo[j][1], true) || cc(a, lo[j][0], false) == cc(b, lo[j][1], false) ) ||
                    (lo[j][1] != b) && (lo[j][2] != c) && ( cc(b, lo[j][1], true) == cc(c, lo[j][2], true) || cc(b, lo[j][1], false) == cc(c, lo[j][2], false) ) ||
                    (lo[j][2] != c) && (lo[j][3] != d) && ( cc(c, lo[j][2], true) == cc(d, lo[j][3], true) || cc(c, lo[j][2], false) == cc(d, lo[j][3], false) ) ||
                    (lo[j][3] != d) && (lo[j][4] != e) && ( cc(d, lo[j][3], true) == cc(e, lo[j][4], true) || cc(d, lo[j][3], false) == cc(e, lo[j][4], false) ) )
                    ok = true;
                else {
                    ok = false;
                    break;
                }
            }
            else
                ok = true;
        }

        if (ok)
            ans++;
    }

    cout << ans;
    return 0;
}

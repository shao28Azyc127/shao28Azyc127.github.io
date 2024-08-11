#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int t = n, delnum = 0, step = 0, step2 = 0, t2 = n, delnum2 = 0;
    while ((t + delnum + 1) / 3 > 0) {
        if (t % 3 == 1) delnum = (t + 2) / 3;
        else delnum = (t + 1) / 3;
        t -= delnum;
        step++;
    }
    while (t2 % 3 != 1) {
        delnum2 = (t2 + 1) / 3;
        t2 -= delnum2;
        step2++;
    }
    step2++;
    cout << step << " " << step2 << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,ans1 = 0,ans2 = 0;
int main () {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    int d = 0;
    while (n) {
        d++;
        if (ans2 == 0 && n % 3 == 1) {
            ans2 = d;
        }
        int m = (n + 2) / 3;
        n -= m;
    }
    ans1 = d;
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}

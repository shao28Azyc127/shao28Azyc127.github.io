#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;

int main () {
    freopen ("apple.in", "r", stdin);
    freopen ("apple.out", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> n;

    int ans = 0, ans1 = -1;
    while (n) {
        ans ++ ;
        if (n % 3 == 1 && ans1 == -1) ans1 = ans;
        n -= (n % 3 == 0 ? n / 3 : (n + 3) / 3);
    }

    cout << ans << " " << ans1 << endl;

    return 0;
}

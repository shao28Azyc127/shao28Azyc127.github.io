

#include <iostream>

#define int long long
#define endl '\n'

using namespace std;

int n;
int ans, cnt = 0;
bool flag = 0;

signed main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    cin >> n;

    while (n) {
        cnt++;
        if (!flag && n % 3 == 1) ans = cnt, flag = 1;
        n -= (n + 2) / 3;
    }

    cout << cnt << ' ' << ans << endl;

    return 0;
}

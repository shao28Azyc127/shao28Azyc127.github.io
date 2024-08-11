#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int n, a[N][6], ans = 0;
int roll(int x, int y) {
    return (y + 10 - x) % 10;
}
bool check(int x, int id) {
    int ti = 0, last = 0;
    // last=0: same  last>0:last one is diff  last=-1:must same
    for (int i = 1; i <= 5; ++i) {
        ti = ti * 10 + a[id][i];
    }
    if (ti == x) return false;
    for (int i = 1; i <= 5; ++i) {  // get this roll
        int tmpx = x % 10, t = ti % 10;
        x /= 10, ti /= 10;
//        cout<<i<<" "<<tmpx<<" "<<t<<" "<<last<<endl;
        int r = roll(tmpx, t);
        if (last == -1) {
            if (tmpx != t) return false;
        } else if (last == 0) {
            if (tmpx != t) {
                last = r;
            }
        } else if (last > 0) {
            if (r != last && tmpx != t) return false;
            last = -1;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= 5; ++j)
            cin >> a[i][j];
    for (int x = 0; x <= 99999; ++x) {
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            if (!check(x, i)) {
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    }
    cout << ans;
    return 0;
}

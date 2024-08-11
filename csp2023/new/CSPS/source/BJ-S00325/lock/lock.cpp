#include <bits/stdc++.h>
using namespace std;
int n;
map<int, bool> a[5];
long long ans;
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            int tmp;
            cin >> tmp;
            a[j][tmp] = 1;
        }
    }
    if (n == 1) {
        cout << 81 << '\n';
        return 0;
        //都是45个一个轮盘+36个两个轮盘
    }
    for (int i = 0; i < 5; i++) {
        if (a[i].size() != 1) {
            //一个轮盘
            ans += 10 - a[i].size();
            //两个轮盘
            if (i < 4) {
                if (a[i + 1].size() > 1) ans += max(a[i].size(), a[i + 1].size()) * 2;
                else ans += a[i].size();
            }
        }else {
            if (i < 4 && a[i + 1].size() > 1) ans += a[i + 1].size();
        }
    }
    cout << ans << endl;
    return 0;
}
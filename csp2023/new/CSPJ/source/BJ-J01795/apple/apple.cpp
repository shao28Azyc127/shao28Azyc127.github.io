#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5;

int n, cnt, days, ans;
bool flag[N];

int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n; cnt = n;
    int now = 0;
    while (cnt) {
        days++;
        now = 0;
        for (int i = 1; i <= n; i++) {
            if (flag[i] == false) {
                now++;
            }
            if (now % 3 == 1 && flag[i] == false) {
                if (i == n) {
                    ans = days;
                }
                cnt--;
                flag[i] = true;
            }
        }
    }
    cout << days << " " << ans << endl;
    return 0;
}

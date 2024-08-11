#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5;
int n;
int ans[N];
int last[105];
int mx = 1;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    ans[1] = 1;
    last[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= mx; j++) {
            int cnt = 0;
            for (int k = last[j] + 1; k < i; k++) {
                cnt += ans[k] > j;
            }
            if (cnt >= 2) {
                ans[i] = j;
                last[j] = i;
                break;
            }
        }
        if (!ans[i]) {
            ans[i] = ++mx;
            last[mx] = i;
        }
    }
    // for (int i = 1; i <= n; i++)
        // cout << ans[i] << " ";
    // cout << endl;
    cout << mx << " " << ans[n] << endl;
    return 0;
}

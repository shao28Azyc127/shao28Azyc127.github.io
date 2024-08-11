#include <bits/stdc++.h>
using namespace std;
int n, a[6];
struct node {
    int a[6];
    node(int _a[6]) {
        for (int j = 1; j <= 5; j++)
            a[j] = _a[j];
    }
    inline bool operator < (const node &cmp) const {
        for (int i = 1; i <= 5; i++) {
            if (a[i] < cmp.a[i])
                return 1;
            else if (a[i] > cmp.a[i])
                return 0;
        }
        return 0;
    }
};
map<node, int> mp;
int main(void) {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++)
            cin >> a[j];
        for (int j = 1; j <= 5; j++)
            for (int k = 1; k <= 9; k++) {
                a[j] = (a[j] + k) % 10;
                node tmp(a);
                mp[tmp]++;
                a[j] = (a[j] - k + 10) % 10;
            }
        for (int j = 1; j < 5; j++)
            for (int k = 1; k <= 9; k++) {
                a[j] = (a[j] + k) % 10, a[j + 1] = (a[j + 1] + k) % 10;
                node tmp(a);
                mp[tmp]++;
                a[j] = (a[j] - k + 10) % 10, a[j + 1] = (a[j + 1] - k + 10) % 10;
            }
    }
    int ans = 0;
    for (pair<node, int> t : mp)
        if (t.second == n)
            ans++;
    cout << ans << endl;
    return 0;
}

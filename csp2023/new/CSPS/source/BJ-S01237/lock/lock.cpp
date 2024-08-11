#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10;
const int L = 5;
const int X = 10;
int n, ans, a[maxn][maxn], c[maxn];
bool solve() {
    for (int k = 1; k <= n; k++) {
        int cnt = 0;
        for (int i = 1; i <= L; i++)
            if (a[k][i] != c[i]) ++cnt;
        if (cnt > 2) return false;
        if (cnt == 1) continue;
        bool found = false;
        for (int i = 2; i <= L; i++) if (a[k][i] != c[i] && a[k][i - 1] != c[i - 1]) {
            found = true;
            if ((a[k][i] + 10 - c[i]) % 10 != (a[k][i - 1] + 10 - c[i - 1]) % 10) return false;
        } if (!found) return false;
    } return true;
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= L; j++)
            cin >> a[i][j];
    for (int mask = 0; mask < 100000; mask++) {
        int cur = mask, tot = 0;
        for (int i = 1; i <= L; i++) c[i] = 0;
        while (cur) c[++tot] = cur % 10, cur /= 10;
        reverse(c + 1, c + L + 1);
        if (solve()) ++ans;
    }
    cout << ans << '\n';
    return 0;
}
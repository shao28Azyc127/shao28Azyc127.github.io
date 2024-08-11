#include <bits/stdc++.h>
using namespace std;

int n, ans, a[2000005], cnt;
char s[2000005];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) a[i] = 1;
    while (true) {
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i] == ' ') continue;
            if (s[i] == s[i + a[i]]) {
                ans++;
                s[i] = ' ', s[i + a[i]] = ' ';
                flag = 0;
                a[i - 1] = a[i] + 2;
                cnt += 2;
            }
        }
        if (flag) break;
    }
    if (cnt == n) ans++;
    printf("%d\n", ans);
    return 0;
}

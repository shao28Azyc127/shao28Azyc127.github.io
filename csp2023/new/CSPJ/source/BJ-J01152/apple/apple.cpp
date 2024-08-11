#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, cnt, a[1000005], now = 1, day;
    memset(a, 1, sizeof(a));
    scanf("%d", &n);
    cnt = n;
    while (cnt) {
        int cc = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) continue;
            if (cc % 3 == 1) {
                if (i == n) day = now;
                a[i] = 0;
                cnt--;
            }
            cc++;
        }
        if (cnt) now++;
        else break;
    }
    printf("%d %d", now, day);
    return 0;
}

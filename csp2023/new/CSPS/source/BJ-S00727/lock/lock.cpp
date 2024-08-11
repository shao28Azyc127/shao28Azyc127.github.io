#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, ans, a[10][6], num[N];
int calc(int x) {
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        sum = sum * 10 + a[x][i];
    }
    return sum;
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%d%d", &a[i][1], &a[i][2], &a[i][3], &a[i][4], &a[i][5]);
        num[calc(i)] = -1;
        for (int j = 1; j <= 5; j++) {
            for (int k = 0; k <= 9; k++) {
                if (a[i][j] == k) continue;
                int tmp = a[i][j];
                a[i][j] = k, num[calc(i)]++, a[i][j] = tmp;
            }
        }
        for (int j = 1; j <= 4; j++) {
            for (int k = 0; k <= 9; k++) {
                if (a[i][j] == k) continue;
                int d = ((k - a[i][j]) % 10 + 10) % 10;
                int tmp1 = a[i][j], tmp2 = a[i][j + 1];
                a[i][j] = k, a[i][j + 1] = (a[i][j + 1] + d) % 10;
                num[calc(i)]++;
                a[i][j] = tmp1, a[i][j + 1] = tmp2;
            }
        }
    }
    for (int i = 0; i <= 99999; i++) {
        if (num[i] == n) ans++;
    }
    printf("%d", ans);
    return 0;
}
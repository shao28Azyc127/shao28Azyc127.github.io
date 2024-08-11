#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int cnt[maxn][10][2];
int x[5], y[5];

int get() {
    int res = 0;
    for (int i = 0; i < 5; i++) {
        res = res * 10 + y[i];
    }
    return res;
}

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &x[j]);
            y[j] = x[j];
        }
        for (int j = 0; j < 5; j++) {
            for (int k = 1; k <= 9; k++) {
                y[j] = (y[j] + 1) % 10;
                cnt[get()][i][0]++;
            }
            y[j] = x[j];
        }
        for (int j = 0; j < 4; j++) {
            for (int k = 1; k <= 9; k++) {
                y[j] = (y[j] + 1) % 10;
                y[j + 1] = (y[j + 1] + 1) % 10;
                cnt[get()][i][1]++;
            }
            y[j] = x[j];
            y[j + 1] = x[j + 1];
        }
    }
    int ans = 0;
    for (int i = 0; i < 100000; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            tmp += (cnt[i][j][0] || cnt[i][j][1]);
        }
        ans += (tmp == n);
    }
    printf("%d\n", ans);
    return 0;
}

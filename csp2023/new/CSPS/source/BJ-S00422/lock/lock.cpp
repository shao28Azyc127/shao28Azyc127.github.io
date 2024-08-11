#include <bits/stdc++.h>
using namespace std;
int n, cnt, ans;
int a[15][15], d[15][15];
bool flag[15];
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 5; j++) {
            scanf("%d", &a[i][j]);
            d[i][j] = a[i][j] - a[i][j - 1];
            if (d[i][j] < 0) d[i][j] += 10;
            if (a[i][j] != a[i - 1][j] && i != 0) {
                flag[j] = 1;
            }
        }
    }
    for (int i = 1; i <= 5; i++) {
        if (flag[i] != 0) cnt++;
    }
    //cout << cnt;
    if (n == 1) {
        printf("81");
        return 0;
    }
    if (n == 2) {
        if (cnt == 1) {
            int q;
            //1
            ans += 8;
            //2
            for (int i = 1; i <= 5; i++) {
                if (flag[i] != 0) q = i;
            }
            if (q == 1 || q == 5) ans += 2;
            else ans += 4;
        }
        if (cnt == 2) {
            //1
            ans += 2;
            //2
            bool q[2], f1;
            int p;
            for (int i = 1; i <= 5; i++) {
                if (flag[i] != 0) q[p++] = 1;
            }
            if (q[2] - q[1] == 1) {
                for (int i = 1; i < n; i++) {
                    if (d[i][q[2]] != d[i - 1][q[2]]) f1 = 1;
                }
                if (f1 == 0) ans += 8;
                else ans += 4;
            } else {
                int s1 = a[0][q[1]] - a[1][q[1]];
                int s2 = a[0][q[2]] - a[1][q[2]];
                if (s1 == s2 || abs(s1 - s2) == 10) ans += 2;
            }

        }
    } else {
        if (cnt == 1) {
            ans += 10 - n;
        } else ans = 1;
    }

    printf("%d", ans);
    return 0;
}

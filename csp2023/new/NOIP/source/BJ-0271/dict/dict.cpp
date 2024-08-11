#include <bits/stdc++.h>
using namespace std;
int n, m;
char str[3005][3005];
char mn[3005], mx[3005];
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    if (n == 1) {
        puts("1");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        scanf("%s", str[i] + 1);
    char mnc, mxc;
    for (int i = 1; i <= n; ++i) {
        mnc = 'z' + 1, mxc = 'a' - 1;
        for (int j = 1; j <= m; ++j) {
            if (str[i][j] < mnc)
                mnc = str[i][j];
            if (str[i][j] > mxc)
                mxc = str[i][j];
        }
        mn[i] = mnc, mx[i] = mxc;
    }
    bool flag;
    for (int i = 1; i <= n; ++i) {
        flag = true;
        for (int j = 1; j <= n; ++j) {
            if (j == i)
                continue;
            if (mn[i] >= mx[j]) {
                flag = false;
                break;
            }
        }
        if (flag)
            printf("1");
        else
            printf("0");
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 3010;
int n, m, mn[N], mx[N];
char s[N][N];
void Min(int &x, int y) {if (x > y) x = y; }
void Max(int &x, int y) {if (x < y) x = y; }

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    memset(mx, -1, sizeof(mx));
    memset(mn, 0x3f, sizeof(mn));
    for (int i=1; i<=n; ++i) {
        scanf("%s", s[i] + 1);
        for (int j=1; j<=m; ++j) {
            Max(mx[i], s[i][j] - 'a');
            Min(mn[i], s[i][j] - 'a');
        }
    }
    for (int i=1; i<=n; ++i) {
        bool flag = true;
        for (int j=1; j<=n; ++j) {
            if (i == j) continue;
            if (mx[j] <= mn[i]) {
                flag = false; break;
            }
        }
        if (flag) putchar('1');
        else putchar('0');
    }
    putchar(10);
    return 0;
}

// 100pts
#include <bits/stdc++.h>
using namespace std;
const int N = 3009;
int n, m;
bool chk(char *s, char *t) { // s<t -> 1
    for (int i = 1; i <= m; i++) {
        if (s[i] != t[i]) return s[i] < t[i];
    }
    return 0;
}
char s[N][N], mn[N][N], mx[N][N];
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++) {
            mn[i][j] = mx[i][j] = s[i][j];
        }
        sort(mn[i] + 1, mn[i] + m + 1);
        sort(mx[i] + 1, mx[i] + m + 1, greater<char>());
    }
    for (int i = 1; i <= n; i++) {
        int fl = 1;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (!chk(mn[i], mx[j])) {
                fl = 0; break;
            }
        }
        printf("%d", fl);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
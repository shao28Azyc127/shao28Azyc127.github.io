#include <bits/stdc++.h>
using namespace std;
int n, a[10][6], t[6], d[6];
int ans = 0;
bool check() {
    int cnt, d1, d2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 5; ++j) {
            d[j] = a[i][j] - t[j];
            d[j] = (d[j] + 10) % 10;
        }
        cnt = 0, d1 = d2 = -1;          //d1, d2: pos
        for (int j = 1; j <= 5; ++j) 
            if (d[j] != 0) {
                ++cnt;
                if (d1 == -1)
                    d1 = j;
                else 
                    d2 = j;
            }
        if (!cnt || cnt > 2)
            return false;
        if (cnt == 2) {
            if (d2 == d1 + 1 && d[d1] == d[d2]);
            else 
                return false;
        }
    }
    return true;
}
void dfs(int step) {
    if (step == 6) {
        if (check())
            ++ans;
        return;
    }
    for (int i = 0; i < 10; ++i) {
        t[step] = i;
        dfs(step + 1);
    }
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= 5; ++j)
            scanf("%d", &a[i][j]);
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
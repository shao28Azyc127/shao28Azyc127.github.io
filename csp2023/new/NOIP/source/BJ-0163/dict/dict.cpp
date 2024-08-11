#include<cstdio>
#include<cstring>
using namespace std;
char w[3005][3005];
char mx[3005], mn[3005];
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == 1) {
        puts("1");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%s", w[i] + 1);
        mx[i] = mn[i] = w[i][1];
        for (int j = 2; j <= m; ++j) if (w[i][j] > mx[i]) mx[i] = w[i][j];
        for (int j = 2; j <= m; ++j) if (w[i][j] < mn[i]) mn[i] = w[i][j];
    }
    int mn1id = 1, mn2id = 1;
    for (int i = 2; i <= n; ++i) {
        if (mx[i] < mx[mn2id]) {
            mn2id = i;
            if (mx[mn1id] > mx[mn2id]) mn2id = mn1id, mn1id = i;
        }
    }
    // printf("%d %d\n", mn1id, mn2id);
    for (int i = 1; i <= n; ++i) {
        if (i == mn1id) {
            printf("%d", mn[i] < mx[mn2id]);
        } else {
            printf("%d", mn[i] < mx[mn1id]);
        }
    }
    puts("");
    return 0;
}
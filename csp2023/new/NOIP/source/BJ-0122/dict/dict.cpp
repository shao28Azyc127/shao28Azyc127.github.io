#include <bits/stdc++.h>
using namespace std;

const int maxn = 3333;

int tot[maxn][26], ans[maxn], f[maxn];
int mins;

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    memset(tot, 0, sizeof(tot));
    memset(f, 0x3f, sizeof(f));
    mins = 0;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;
            scanf(" %c", &ch);
            tot[i][ch - 'a']++;
            f[i] = min(f[i], ch - 'a');
        }
    }
    tot[0][25] = m;
    for (int i = 1; i <= n; i++) {
        int sum1 = 0, sum2 = 0;
        for (int j = 25; j >= 0; j--) {
            sum1 += tot[mins][j];
            sum2 += tot[i][j];
           // printf("point1:i=%d, j=%d, mins=%d, ch=%c, sum1=%d, sum2=%d\n", i, j, mins, 'a' + j, sum1, sum2);
            if (sum2 < sum1) {
            //    printf("point2:i=%d, j=%d, mins=%d, ch=%c, sum1=%d, sum2=%d\n", i, j, mins, 'a' + j, sum1, sum2);
                mins = i;
                break;
            } else if (sum2 > sum1) {
                break;
            }
        }
    }
    bool tag = true;
    for (int i = 1; i <= n; i++) {
        if (i == mins) {
            continue;
        }
        bool xxxx = true;
        for (int j = 0; j < 26; j++) {
            if (tot[i][j] != tot[mins][j]) {
                xxxx = false;
                break;
            }
        }
        if (xxxx) {
            tag = false;
        }
    }
  //  printf("mins=%d\n", mins);
    for (int i = 1; i <= n; i++) {
        if (i == mins && tag) {
            ans[i] = 1;
          //  printf("point1:i=%d, ans=%d\n", i, ans[i]);
            continue;
        }
        int sum = 0;
        for (int j = 25; j > f[i]; j--) {
            sum += tot[mins][j];
        }
        ans[i] = (sum > 0);
       // printf("point2:i=%d, sum=%d, ans=%d\n", i, sum, ans[i]);
        /*
        if (sum > 0) {
            ans[i] = 1;
        } else if (tot[i][f[i]]) {

        }
        */
    }
    for (int i = 1; i <= n; i++) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}

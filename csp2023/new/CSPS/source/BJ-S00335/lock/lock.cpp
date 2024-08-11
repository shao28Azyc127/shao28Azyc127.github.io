#include <cstdio>
using namespace std;

int n;
int a[5], s[10][5];

int ans = 0;

void dfs(int step) {
    if (step == 5) {
        for (int i = 1; i <= n; i++) {
            int diff_cnt = 0;
            for (int j = 0; j < 5; j++)
                diff_cnt += (a[j] != s[i][j]);
            if (diff_cnt <= 0 || diff_cnt >= 3)
                return;
            else if (diff_cnt == 2) {
                int pos[2], cur = 0;
                for (int j = 0; j < 5; j++)
                    if (a[j] != s[i][j])
                        pos[cur++] = j;
                if (pos[1] - pos[0] != 1)
                    return;
                if ((a[pos[0]] - s[i][pos[0]] + 10) % 10 != (a[pos[1]] - s[i][pos[1]] + 10) % 10)
                    return;
            }
        }
        ans++;
        return;
    }

    for (int i = 0; i <= 9; i++) {
        a[step] = i;
        dfs(step + 1);
    }
}

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 5; j++)
            scanf("%d", &s[i][j]);
    dfs(0);
    printf("%d\n", ans);
    return 0;
}


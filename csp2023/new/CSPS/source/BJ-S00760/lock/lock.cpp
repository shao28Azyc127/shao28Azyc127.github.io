#include <bits/stdc++.h>
using namespace std;
const int N = 6e4 + 5;
int n, all[10][100][5], cnt[10], num[6], ans;
// int n, tot, all[N][6], cnt[N], num[6]; set <int> s[];
// void dfs(int x) {
//     if(x == 6) {
//         tot++;
//         for(int i = 1; i <= 5; i++)
//             all[tot][i] = num[i];
//         return ;
//     }
//     for(int i = 0; i < 9; i++) {
//         num[x] = i;
//         dfs(x + 1);
//     }
// }
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    // dfs(1);
    scanf("%d", &n);
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= 5; i++) scanf("%d", &num[i]);
        for(int i = 1; i <= 5; i++) {
            for(int j = 0; j <= 9; j++) {
                if(num[i] == j) continue ;
                cnt[k]++;
                for(int l = 1; l <= 5; l++)
                    if(i != l) all[k][cnt[k]][l] = num[l];
                all[k][cnt[k]][i] = j;
            }
        } // one circle
        for(int i = 1; i <= 4; i++) {
            for(int j = 1; j <= 9; j++) {
                cnt[k]++;
                for(int l = 1; l <= 5; l++)
                    all[k][cnt[k]][l] = num[l];
                all[k][cnt[k]][i] = (num[i] + j) % 10,
                all[k][cnt[k]][i+1] = (num[i+1] + j) % 10;
            }
        } // two circle
        // 10 circle %%%%%%
    }
    // for(int i = 1; i <= cnt[2]; i++) {
    //     for(int j = 1; j <= 5; j++) printf("%d ", all[1][i][j]);
    //     printf("\n");
    // }
    for(int i = 1; i <= cnt[1]; i++) {
        bool flag = true;
        for(int j = 1; j <= n; j++) {
            bool flag2 = false;
            for(int k = 1; k <= cnt[j]; k++) {
                bool flag3 = true;
                for(int l = 1; l <= 5; l++)
                    if(all[1][i][l] != all[j][k][l])
                        flag3 = false;
                if(flag3) flag2 = true;
            }
            if(!flag2) flag = false;
        }
        // for(int j = 1; j <= 5; j++) printf("%d ", all[1][i][j]);
        // if(flag) printf("OK\n");
        // else printf("FAIL\n");
        if(flag) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
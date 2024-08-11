#include <cstdio>
#include <cstring>
using namespace std;

bool vis[10][10][10][10][10], res[10][10][10][10][10], vis_not_password[10][10][10][10][10];

int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    scanf("%d", &n);
    memset(res, 1, sizeof(res));
    for (int i = 1; i <= n; i++){
        int a, b, c, d, e;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        vis_not_password[a][b][c][d][e] = true;
        memset(vis, 0, sizeof(vis));
        for (int j = 0; j <= 9; j++){
            vis[j][b][c][d][e] = true;
            vis[a][j][c][d][e] = true;
            vis[a][b][j][d][e] = true;
            vis[a][b][c][j][e] = true;
            vis[a][b][c][d][j] = true;
            vis[j][((j + b - a) % 10 + 10) % 10][c][d][e] = true;
            vis[a][j][((j + c - b) % 10 + 10) % 10][d][e] = true;
            vis[a][b][j][((j + d - c) % 10 + 10) % 10][e] = true;
            vis[a][b][c][j][((j + e - d) % 10 + 10) % 10] = true;
        }
        for (int i1 = 0; i1 <= 9; i1++){
            for (int i2 = 0; i2 <= 9; i2++){
                for (int i3 = 0; i3 <= 9; i3++){
                    for (int i4 = 0; i4 <= 9; i4++){
                        for (int i5 = 0; i5 <= 9; i5++){
                            res[i1][i2][i3][i4][i5] &= vis[i1][i2][i3][i4][i5];
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 9; i++){
        for (int j = 0; j <= 9; j++){
            for (int k = 0; k <= 9; k++){
                for (int l = 0; l <= 9; l++){
                    for (int r = 0; r <= 9; r++){
                        if (!vis_not_password[i][j][k][l][r] && res[i][j][k][l][r]){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

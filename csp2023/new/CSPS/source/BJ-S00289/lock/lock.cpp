#include<cstdio>
#include<cstring>
using namespace std;
const int N = 10, M = 6;
int n;
int a[N][M];
bool f[8][N][N][N][N][N];//1e5
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int k = 0; k < N; k++){
            f[i - 1][k][a[i][2]][a[i][3]][a[i][4]][a[i][5]] = 1;
            f[i - 1][a[i][1]][k][a[i][3]][a[i][4]][a[i][5]] = 1;
            f[i - 1][a[i][1]][a[i][2]][k][a[i][4]][a[i][5]] = 1;
            f[i - 1][a[i][1]][a[i][2]][a[i][3]][k][a[i][5]] = 1;
            f[i - 1][a[i][1]][a[i][2]][a[i][3]][a[i][4]][k] = 1;

            f[i - 1][(a[i][1] + k) % 10][(a[i][2] + k) % 10][a[i][3]][a[i][4]][a[i][5]] = 1;
            f[i - 1][a[i][1]][(a[i][2] + k) % 10][(a[i][3] + k) % 10][a[i][4]][a[i][5]] = 1;
            f[i - 1][a[i][1]][a[i][2]][(a[i][3] + k) % 10][(a[i][4] + k) % 10][a[i][5]] = 1;
            f[i - 1][a[i][1]][a[i][2]][a[i][3]][(a[i][4] + k) % 10][(a[i][5] + k) % 10] = 1;
        }
        f[i - 1][a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]] = 0;
    }
    int ans = 0;
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            for(int c = 0; c < N; c++){
                for(int d = 0; d < N; d++){
                    for(int e = 0; e < N; e++){
                        int t = 1;
                        for(int i = 1; i <= n; i++) t &= f[i - 1][a][b][c][d][e];
                        ans += t;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}


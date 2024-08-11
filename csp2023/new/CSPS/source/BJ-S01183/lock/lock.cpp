

#include <cstdio>

using namespace std;

int N;
int A[9][9];
bool chk[100009][9];
int res;

int main () {
    bool ans;
    int t;

    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= 5; j++) scanf("%d", &A[i][j]);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 5; j++) {
            for (int k = 0; k < 10; k++) {
                if (k == A[i][j]) continue;
                t = 0;
                for (int l = 1; l <= 5; l++) t = t * 10 + ((l == j) ? k : A[i][l]);
                chk[t][i] = true;
            }
            if (j + 1 <= 5)
                for (int k = 1; k < 10; k++) {
                    t = 0;
                    for (int l = 1; l <= 5; l++) t = t * 10 + ((l == j || l == j + 1) ? ((A[i][l] + k) % 10) : A[i][l]);
                    chk[t][i] = true;
                }
        }
    }
    for (int i = 0; i <= 99999; i++) {
        ans = 1;
        for (int j = 1; j <= N; j++) ans &= chk[i][j];
        res += ans;
    }
    printf("%d\n", res);
    fclose(stdin), fclose(stdout);
    return 0;
}
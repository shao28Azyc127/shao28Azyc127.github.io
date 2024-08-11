#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool Can[10][N];
int A[6], pow10[5] = {1, 10, 100, 1000, 10000};
bool vis[N];
inline int Get(int x, int p) { return (x / pow10[p]) % 10; }
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int num = 0;
        for (int j = 0; j < 5; j++) {
            scanf("%d", A + j);
            num += pow10[j] * A[j];
        }
        for (int j = 0; j < 5; j++) {
            for (int k = 1; k < 10; k++) {
                int num = 0;
                for (int t = 0; t < 5; t++) {
                    num += pow10[t] * (t == j ? ((A[t] + k) % 10) : A[t]);
                }
                Can[i][num] = 1;
            }
        }
        for (int j = 0; j < 4; j++) {
            for (int k = 1; k < 10; k++) {
                int num = 0;
                for (int t = 0; t < 5; t++) {
                    num += pow10[t] * ((t == j || t == j + 1) ? ((A[t] + k) % 10) : A[t]);
                }
                Can[i][num] = 1;
            }
        }
        Can[i][num] = 0;
    }
    int Ans = 0;
    for (int i = 0; i < 100000; i++) {
        int flag = 1;
        for (int j = 1; j <= n; j++) flag &= Can[j][i];
        // if (flag) printf("%d ", i);
        Ans += flag;
    }
    printf("%d\n", Ans);
    return 0;
}
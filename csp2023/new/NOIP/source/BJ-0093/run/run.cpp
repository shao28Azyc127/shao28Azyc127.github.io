#include <bits/stdc++.h>

#define getchar getchar_unlocked

using namespace std;

template<typename T = int>
inline T read() {
    int x = 0, f = 1;
    char ch = 0;
    while(!isdigit(ch = getchar())) {
        if (ch == '-') f = -1;
    }
    do x = x * 10 + ch - '0';
    while (isdigit(ch = getchar()));
    return x * f;
}

const int N = 1005;
int C, T, n, m, k, d;
int64_t up[N][N], f[N][N];

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    C = read(), T = read();
    while(T--) {
        memset(f, -0x3f, sizeof(f));
        memset(up, 0, sizeof(up));
        n = read(), m = read(), k = read(), d = read();
        for (int i = 1; i <= m; i++) {
            int x = read(), y = read(), v = read();
            for (int j = y; j <= k; j++) up[x][j] += v;
        }
        int64_t maxf = 0;
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i][0] = maxf;
            for (int j = 1; j <= min(i, k); j++)
                f[i][j] = max(f[i][j], f[i - 1][j - 1] - d) + up[i][j];
            maxf = LONG_MIN;
            for (int j = 0; j <= min(i, k); j++) maxf = max(maxf, f[i][j]);
        }
        printf("%ld\n", maxf);
        // for (int i = 1; i <= n; i++) {
        //     printf("Line %d:", i);
        //     for (int j = 0; j <= k; j++) printf("[%d]%ld ", j, f[i][j]);
        //     puts("");
        // }
    }
    return 0;
}
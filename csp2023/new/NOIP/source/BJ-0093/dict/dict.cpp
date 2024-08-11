// 12th Gen Intel(R) Core(TM) i5-12500
// 4GB RAM
#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const int64_t MOD = 1e18 + 31, BASE = 41;
int n, m;
int64_t hs1[N][N], hs2[N][N];
char s1[N][N], s2[N][N];

bool check(int i, int j) {
    int L = 0, R = m;
    while (L < R - 1) {
        int mid = (L + R + 1) >> 1;
        // cout << "q " << hs1[i][mid] << " " << hs2[j][mid] << endl;
        if (hs1[i][mid] != hs2[j][mid]) R = mid;
        else L = mid;
        // cout << "d " << L << " " << R << endl;
    }
    if (s1[i][R] < s2[j][R]) return true;
    return false;
}

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    mt19937 mrand(time(0));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s1[i] + 1);
        shuffle(s1[i] + 1, s1[i] + m + 1, mrand);
        sort(s1[i] + 1, s1[i] + m + 1);
        memcpy(s2[i] + 1, s1[i] + 1, sizeof(char) * (m + 1));
        reverse(s2[i] + 1, s2[i] + m + 1);
        // cout << s1[i] + 1 << " " << s2[i] + 1 << endl;
        for (int j = 1; j <= m; j++) {
            hs1[i][j] = (__int128(1) * hs1[i][j - 1] * BASE + s1[i][j] - 'a') % MOD;
            hs2[i][j] = (__int128(1) * hs2[i][j - 1] * BASE + s2[i][j] - 'a') % MOD;
        }
        // for (int j = 1; j <= m; j++) cout << hs1[i][j] << " ";
        // cout << endl;
        // for (int j = 1; j <= m; j++) cout << hs2[i][j] << " ";
        // cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        bool fg = true;
        for (int j = 1; j <= n && fg; j++) {
            if (i != j && !check(i, j)) {
                fg = false;
                // cout << i << " failed at " << j << endl;
            }
            // cout << "ok " << j << endl;
        }
        putchar(fg + '0');
    }
    puts("");
    fflush(stdout);
    return 0;
}
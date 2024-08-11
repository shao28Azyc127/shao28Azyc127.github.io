#include <cstdio>
#include <bitset>
using namespace std;

typedef long long LL;

inline int read() {
    int s = 0;
    char ch = getchar();
    while (ch < 48 || ch > 57) {
        ch = getchar();
    }
    while (ch > 47 && ch < 58) {
        s = (s << 3) + (s << 1) + (ch ^ 48);
        ch = getchar();
    }
    return s;
}

char str[8015];
int n, ans;
bitset<8015> f[8015];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    n = read();
    str[0] = getchar();
    for (register int i = 1; i < n; i++) {
        str[i] = getchar();
        if (str[i] == str[i - 1]) {
            if (i > 1) {
                f[i] = f[i - 2];
            }
            f[i].set(i - 1, 1);
        }
        for (register int j = i - 2; ~j; j--) {
            if (str[i] == str[j] && f[i - 1].test(j + 1)) {
                f[i].set(j, 1);
                for (register int k = 0; k < j - 1; k++) {
                    if (!f[i].test(k) && f[j - 1].test(k)) {
                        f[i].set(k, 1);
                    }
                }
            }
        }
        ans += f[i].count();
    }
    printf("%d\n", ans);
    return 0;
}
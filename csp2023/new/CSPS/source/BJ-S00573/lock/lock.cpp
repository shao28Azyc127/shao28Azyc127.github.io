#include <cstdio>
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

int n, ans, dig[6], s[8][6];

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    n = read();
    for (register int i = 0; i < n; i++) {
        for (register int j = 0; j < 5; j++) {
            s[i][j] = read();
        }
    }
    bool flag;
    int a, b;
    for (dig[0] = 0; dig[0] < 10; dig[0]++) {
        for (dig[1] = 0; dig[1] < 10; dig[1]++) {
            for (dig[2] = 0; dig[2] < 10; dig[2]++) {
                for (dig[3] = 0; dig[3] < 10; dig[3]++) {
                    for (dig[4] = 0; dig[4] < 10; dig[4]++) {
                        flag = 1;
                        for (register int i = 0; i < n; i++) {
                            a = b = -1;
                            for (register int j = 0; j < 5; j++) {
                                if (s[i][j] != dig[j]) {
                                    if (~a && ~b) {
                                        flag = 0;
                                        break;
                                    }
                                    if (~a) {
                                        b = j;
                                        if (a != b - 1) {
                                            flag = 0;
                                            break;
                                        }
                                    }
                                    else {
                                        a = j;
                                    }
                                }
                            }
                            if (!flag) {
                                break;
                            }
                            if (~a && ~b) {
                                if ((dig[b] - dig[a] + 10) % 10 != (s[i][b] - s[i][a] + 10) % 10) {
                                    flag = 0;
                                }
                            }
                            else if (a < 0 && b < 0) {
                                flag = 0;
                            }
                            if (!flag) {
                                break;
                            }
                        }
                        if (flag) {
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
#include <bits/stdc++.h>
using namespace std;
bool p[11][11][11][11][11];
int n;
int a[10], b[10];
int dcnt() {
    int ret = 0;
    for (int i = 1; i <= 5; i++) {
        if (a[i] != b[i]) {
            ret++;
        }
    }
    return ret;
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (b[1] = 0; b[1] <= 9; b[1]++) {
        for ( b[2] = 0; b[2] <= 9; b[2]++) {
            for ( b[3] = 0; b[3] <= 9; b[3]++) {
                for ( b[4] = 0; b[4] <= 9; b[4]++) {
                    for ( b[5] = 0; b[5] <= 9; b[5]++) {
                        p[b[1]][b[2]][b[3]][b[4]][b[5]] = 1;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            scanf("%d", &a[j]);
        }
        for ( b[1] = 0; b[1] <= 9; b[1]++) {
        for ( b[2] = 0; b[2] <= 9; b[2]++) {
            for ( b[3] = 0; b[3] <= 9; b[3]++) {
                for ( b[4] = 0; b[4] <= 9; b[4]++) {
                    for ( b[5] = 0; b[5] <= 9; b[5]++) {
                        int delta = dcnt();
                        if (delta > 2) {
                            p[b[1]][b[2]][b[3]][b[4]][b[5]] = false;
                            continue;
                        }
                        if (delta == 1) {
                            continue;
                        }
                        if (delta == 0) {
                            p[b[1]][b[2]][b[3]][b[4]][b[5]] = false;
                        }
                        int ind = -11, tarind = 0;
                        for (int j = 1; j <= 5; j++) {
                            if (tarind && j - tarind > 1 && a[j] != b[j]) {
                                p[b[1]][b[2]][b[3]][b[4]][b[5]] = false;
                                break;
                            }
                            if (a[j] != b[j] && a[j] - b[j] != ind && a[j] - b[j] + 10 != ind && a[j] - b[j] - 10 != ind && ind != -11) {
                                p[b[1]][b[2]][b[3]][b[4]][b[5]] = false;
                                break;
                            }
                            if (a[j] != b[j]) {
                                ind = a[j] - b[j];
                                tarind = j;
                            }
                        }
                    }
                }
            }
        }
    }
    }
    int ans = 0;
    for ( b[1] = 0; b[1] <= 9; b[1]++) {
        for ( b[2] = 0; b[2] <= 9; b[2]++) {
            for ( b[3] = 0; b[3] <= 9; b[3]++) {
                for ( b[4] = 0; b[4] <= 9; b[4]++) {
                    for ( b[5] = 0; b[5] <= 9; b[5]++) {
                        if (p[b[1]][b[2]][b[3]][b[4]][b[5]] == 1) {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    printf("%d", ans);//jianqu yuanben de
    return 0;
}


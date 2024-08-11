#include <bits/stdc++.h>
using namespace std;
int T, a, b, c, m;
int get(int x) {
    int ans = 1, dd = x;
    if(x < 0) {
        x = -x;
    }
    for(int i = 2; i < dd; i++) {
        int thth = 0;
        if(dd % i == 0) {
            while(dd % i == 0) {
                dd /= i, thth++;
            }
        }

        ans *= pow(i, thth / 2 * 2);
    }
    return ans;
}
int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &T, &m);
    while(T--) {
        scanf("%d%d%d", &a, &b, &c);
        int tmp = b * b - 4 * a * c;
        if(tmp < 0) {
            printf("NO\n");
        } else if(tmp == 0) {
            int GCD = __gcd(2 * a, -b);
            GCD = (GCD < 0 ? -GCD : GCD);
            int ghgh = -b / (a * 2);
            if(ghgh * a * 2 == -b) {
                printf("%d\n", ghgh);
            } else {
                if(2 * a / GCD == 1) {
                    printf("%d\n", -b / GCD);
                } else {
                    printf("%d/%d\n", -b / GCD, 2 * a / GCD);
                }
            }
        } else {
            int gh = int(sqrt(tmp)) * int(sqrt(tmp));
            if(a > 0) {
                if(gh == tmp) {
                    int GCD = __gcd(((int)sqrt(tmp) - b), a * 2);
                    if((int)sqrt(gh) == b) {
                        printf("0\n");
                    } else {
                        if(a * 2 / GCD == 1) {
                            printf("%d\n", ((int)sqrt(tmp) - b) / GCD);
                        } else {
                            printf("%d/%d\n", ((int)sqrt(tmp) - b) / GCD, 2 * a / GCD);
                        }
                    }
                } else {
                    int tgh = get(tmp);
                    tmp /= tgh, tgh = (int)sqrt(tgh);
                    int GCD = __gcd(-b, a * 2);
                    GCD = (GCD < 0 ? -GCD : GCD);
                    if(-b != 0) {
                        if(a * 2 / GCD == 1) {
                            printf("%d+", -b / GCD);
                        } else {
                            printf("%d/%d+", -b / GCD, 2 * a / GCD);
                        }
                    }
                    GCD = __gcd(a * 2, tgh);
                    GCD = (tgh / GCD < 0 ? -GCD : GCD);
                    if(tgh / GCD == 1) {
                        if(a * 2 / GCD == 1) {
                            printf("sqrt(%d)\n", tmp);
                        } else {
                            printf("sqrt(%d)/%d\n", tmp, a * 2 / GCD);
                        }
                    } else {
                        if(a * 2 / GCD == 1) {
                            printf("%d*sqrt(%d)\n", tgh / GCD, tmp);
                        } else {
                            printf("%d*sqrt(%d)/%d\n", tgh / GCD, tmp, a * 2 / GCD);
                        }
                    }
                }
            } else {
                if(gh == tmp) {
                    int GCD = __gcd(-(int)sqrt(gh) - b, a * 2);
                    GCD = (GCD > 0 ? -GCD : GCD);
                    if((int)sqrt(gh) == -b) {
                        printf("0\n");
                    } else {
                        if(a * 2 / GCD == 1) {
                            printf("%d\n", (-(int)sqrt(gh) - b) / GCD);
                        } else {
                            printf("%d/%d\n", (-(int)sqrt(gh) - b) / GCD, 2 * a / GCD);
                        }
                    }
                } else {
                    int tgh = get(tmp);
                    tmp /= tgh, tgh = (int)sqrt(tgh);
                    int GCD = __gcd(-b, a * 2);
                    int ghgh = -b / (a * 2);
                    if(ghgh * a * 2 == -b) {
                        printf("%d+", ghgh);
                    } else {
                        if(-b != 0) {
                            if(a * 2 / GCD == 1) {
                                printf("%d+", -b / GCD);
                            } else {
                                printf("%d/%d+", -b / GCD, 2 * a / GCD);
                            }
                        }
                    }
                    GCD = __gcd(a * 2, -tgh);
                    if(-tgh / GCD == 1) {
                        if(a * 2 / GCD == 1) {
                            printf("sqrt(%d)\n", tmp);
                        } else {
                            printf("sqrt(%d)/%d\n", tmp, a * 2 / GCD);
                        }
                    } else {
                        if(a * 2 / GCD == 1) {
                            printf("%d*sqrt(%d)\n", -tgh / GCD, tmp);
                        } else {
                            printf("%d*sqrt(%d)/%d\n", -tgh / GCD, tmp, a * 2 / GCD);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

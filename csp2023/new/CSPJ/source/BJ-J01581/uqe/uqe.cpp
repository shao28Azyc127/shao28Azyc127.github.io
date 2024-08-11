#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    for (int i = 1; i < a; i++) {
        int tmpa = a / i, tmpb = b / i;
        if (a / i - tmpa == 0 && a / i - tmpb == 0) {
            break;
        }
    }
    return 0;
}

void output(double v){
    int p, q;
    if (v < 0) {
        for (p = 0; p >= v / 2; p--) {
            q = p / v;
            if (gcd(p, q) == 1) {
                break;
            }
        }
    }
    else if (v == 0) {
        printf("0");
    }
    else {
        for (p = 0; p <= v / 2; p++) {
            q = p / v;
            if (gcd(p, q) == 1) {
                break;
            }
        }
    }
    printf("%d/%d", p, q);
}

void uqe(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        printf("NO");
    }
    else {
        if (a < 0) {
            double q1, q2;
            int r;
            q1 = -b / (2 * a);
            for (double i = 1; i < sqrt(delta); i++) {
                int tmp = delta / (i*i);
                if (delta / (i*i) - tmp == 0) {
                    q2 = -tmp;
                    r = delta / (i*i);
                }
            }
            q2 /= (2 * a);
            if (q1 != 0) {
                output(q1);
                putchar('+');
            }
            if (q2 == 1) {
                printf("sqrt(%d)", r);
                return;
            }
            int tmp = q2;
            if (q2 - tmp == 0) {
                printf("%d*sqrt(%d)", tmp, r);
                return;
            }
            double q3 = 1 / q2;
            tmp = q3;
            if (q3 - tmp == 0) {
                printf("sqrt(%d)/%d", r, tmp);
                return;
            }
            else {
                int p, q;
                if (q2 < 0) {
                    for (p = 0; p >= q2 / 2; p--) {
                        q = p / q2;
                        if (gcd(p, q) == 1) {
                            break;
                        }
                    }
                }
                else if (q2 == 0) {
                    printf("0");
                }
                else {
                    for (p = 0; p <= q2 / 2; p++) {
                        q = p / q2;
                        if (gcd(p, q) == 1) {
                            break;
                        }
                    }
                }
                printf("%d*sqrt(%d)/%d", p, r, q);
                return;
            }
        }
        else {
            double q1, q2;
            int r;
            q1 = -b / (2 * a);
            for (double i = 0; i < sqrt(delta); i++) {
                int tmp = delta / (i*i);
                if (delta / (i*i) - tmp == 0) {
                    q2 = tmp;
                    r = delta / (q2 * q2);
                }
            }
            q2 /= (2 * a);
            if (q1 != 0) {
                output(q1);
                putchar('+');
            }
            if (q2 = 1) {
                printf("sqrt(%d)", r);
                return;
            }
            int tmp = q2;
            if (q2 - tmp == 0) {
                printf("%d*sqrt(%d)", tmp, r);
                return;
            }
            double q3 = 1 / q2;
            tmp = q3;
            if (q3 - tmp == 0) {
                printf("sqrt(%d)/%d", r, tmp);
                return;
            }
            else {
                int p, q;
                if (q2 < 0) {
                    for (p = 0; p >= q2 / 2; p--) {
                        q = p / q2;
                        if (gcd(p, q) == 1) {
                            break;
                        }
                    }
                }
                else if (q2 == 0) {
                    printf("0");
                }
                else {
                    for (p = 0; p <= q2 / 2; p++) {
                        q = p / q2;
                        if (gcd(p, q) == 1) {
                            break;
                        }
                    }
                }
                printf("%d*sqrt(%d)/%d", p, r, q);
                return;
            }
        }
    }
}

int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    scanf("%d %d", &t, &m);
    while (t--) {
        uqe();
    }
    
    return 0;
}
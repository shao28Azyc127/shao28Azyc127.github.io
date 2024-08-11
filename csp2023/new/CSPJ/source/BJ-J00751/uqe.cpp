#include <bits/stdc++.h>
using namespace std;
int T, M, a, b, c, jiao, shang, xia;

void pr_out(int son, int mom) {
    bool f = false;
    if (son < 0 && mom < 0) son = -son, mom = -mom;
    if (son == 0) {
            printf("0");
            return ;
    }
    if (son < 0) {
        printf("-");
        f = true;
        son = -son;
    }
    if (mom < 0) {
        printf("-");
        mom = -mom;
    }
    if (son % mom == 0) {
        printf("%d", son / mom);
        return;
    }
    for (int i = 2; i <= max(son, mom); i++) {
        while (son % i == 0 && mom % i == 0) {
            son /= i;
            mom /= i;
        }
    }
    printf("%d/%d", son, mom);
}

void sq_out(int son, int mom) {
    mom = max(mom, -mom);
    int bei = 1;
    for (int i = 2; i * i <= son; i++) {
        while (son % (i * i) == 0) {
            son /= (i * i);
            bei *= i;
        }
    }
    for (int i = 2; i <= max(bei, mom); i++) {
        while (bei % i == 0 && mom % i == 0) {
            bei /= i;
            mom /= i;
        }
    }

    if (bei != 1) {
        printf("%d*", bei);
    }
    printf("sqrt(%d)", son);
    if (mom != 1) {
        printf("/%d", mom);
    }
}

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &T, &M);
    while (T--) {
        scanf("%d%d%d", &a, &b, &c);
        jiao = (b * b) - (4 * a * c);
        if (jiao < 0) {
            printf("NO\n");
            continue;
        }
        if ((int)(sqrt(jiao)) * (int)(sqrt(jiao)) == jiao) {
            shang = (-b) + sqrt(jiao);
            xia = 2 * a;
            if (a < 0) shang = (-b) - sqrt(jiao);
            pr_out(shang, xia);
        } else {
            if (-b != 0) {
                shang = -b;
                xia = 2 * a;
                pr_out(shang, xia);
                printf("+");
            }
            sq_out(jiao, 2 * a);
        }
        printf("\n");
    }
    return 0;
}

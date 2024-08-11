#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int check(int x) {
    int temp = sqrt(x);
    for(int i = max(0, temp - 5); i <= temp + 5; i++)
        if(i * i == x) return i;
    return -1;
}

int hj1(int x, int y) {
    if(y < 0) {
        x = -x;
        y = -y;
    }
    for(int i = 2; i <= y; i++) {
        while(x % i == 0 && y % i == 0) {
            x /= i;
            y /= i;
        }
    }
    return x;
}

int hj2(int x, int y) {
    if(y < 0) {
        x = -x;
        y = -y;
    }
    for(int i = 2; i <= y; i++) {
        while(x % i == 0 && y % i == 0) {
            x /= i;
            y /= i;
        }
    }
    return y;
}

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    scanf("%d%d", &t, &m);
    while(t--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int temp = b * b - 4 * a * c;
        if(temp < 0) {
            printf("NO\n");
            continue;
        }
        int chk = check(temp);
        //cout << "!" << chk << endl;
        if(chk != -1) {
            int bx1 = -b + chk, cx1 = 2 * a;
            int bx2 = -b - chk, cx2 = 2 * a;
            int bx, cx;
            if(bx1 * cx2 > cx1 * bx2) {
                bx = bx1;
                cx = cx1;
            }
            else {
                bx = bx2;
                cx = cx2;
            }
            if(bx % cx == 0)
                printf("%d\n", bx / cx);
            else {
                int bx_ = hj1(bx, cx), cx_ = hj2(bx, cx);
                printf("%d/%d\n", bx_, cx_);
            }
        }
        else {
            int bq1 = -b, cq1 = 2 * a;
            int bq2 = 1, cq2 = 2 * a;
            int r = temp;
            for(int i = 2; i * i <= r; i++) {
                while(r % (i * i) == 0) {
                    bq2 *= i;
                    r /= i * i;
                }
            }
            if(bq1 != 0 && cq1 != 0) {
                if(bq1 % cq1 == 0)
                    printf("%d+", bq1 / cq1);
                else {
                    int bq1_ = hj1(bq1, cq1), cq1_ = hj2(bq1, cq1);
                    printf("%d/%d+", bq1_, cq1_);
                }
            }
            if(abs(bq2) == abs(cq2)) {
                printf("sqrt(%d)\n", r);
            }
            else if(bq2 % cq2 == 0) {
                printf("%d*sqrt(%d)\n", abs(bq2 / cq2), r);
            }
            else {
                int bq2_ = bq2, cq2_ = cq2;
                bq2 = hj1(bq2_, cq2_);
                cq2 = hj2(bq2_, cq2_);
                if(abs(bq2) == 1) {
                    printf("sqrt(%d)/%d\n", r, cq2);
                }
                else {
                    printf("%d*sqrt(%d)/%d\n", abs(bq2), r, cq2);
                }
            }
        }
    }
    return 0;
}

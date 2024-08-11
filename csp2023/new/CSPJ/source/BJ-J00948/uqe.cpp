#include <bits/stdc++.h>

using namespace std;
int T, m, A, B, C;
void print(int a, int b){
    if (a == 0) printf("0");
    else if (b == 1 || b == -1) printf("%d", a / b);
    else{
        if (b < 0) a = -a, b = -b;
        printf("%d/%d", a, b);
    }
}
int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}
int GCD(int x, int y){
    int a = x, b = y;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    return gcd(a, b);
}
int calc(int x){
    for (int i = sqrt(x); i >= 1; i--)
        if (x % (i * i) == 0) return i;
}
bool cmp(int p1, int q1, int p2, int q2){
    int x1 = p1 * q2, x2 = p2 * q1;
    return x1 > x2;
}
void add(int p1, int q1, int p2, int q2){
    int x1 = p1 * q2 + p2 * q1, y1 = q1 * q2;
    int k = GCD(x1, y1);
    x1 /= k, y1 /= k;
    int x2 = p1 * q2 - p2 * q1, y2 = q1 * q2;
    k = GCD(x2, y2);
    x2 /= k, y2 /= k;
    if (cmp(x1, y1, x2, y2)) print(x1, y1);
    else print(x2, y2);
}
void solve(){
    int k;
    int derta = B * B - 4 * A * C;
    if (derta < 0){
        puts("NO");
        return;
    }
    // l
    int lz = -B, lm = 2 * A;
    k = GCD(lz, lm);
    lz /= k, lm /= k;
    if (derta == 0){
        print(lz, lm);
        puts("");
        return;
    }

    // r
    int r0 = derta;
    int q2 = calc(r0);
    int r = r0 / (q2 * q2), rm = 2 * A;
    k = GCD(q2, rm);
    q2 /= k, rm /= k;
    if (r == 1){
        add(lz, lm, q2, rm);
        puts("");
        return;
    }

    if (lz != 0){
        print(lz, lm);
        printf("+");
    }
    // q2 = q2 / rm...
    if ((abs(q2) == 1 && abs(rm) == 1)){
        printf("sqrt(%d)\n", r);
        return;
    }
    if (q2 % rm == 0){ //
        // cout << q2 << " " << rm << endl;
        int t = q2 / rm; if (t < 0) t = -t;
        printf("%d*sqrt(%d)\n", t, r);
        return;
    }
    if (rm % q2 == 0){
        int t = rm / q2; if (t < 0) t = -t;
        printf("sqrt(%d)/%d\n", r, t);
        return;
    }
    q2 = abs(q2), rm = abs(rm);
    printf("%d*sqrt(%d)/%d\n", q2, r, rm);
}
int main(){
    freopen("uqe.in", "r",  stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &T, &m);
    while (T--){
        scanf("%d%d%d", &A, &B, &C);
        solve();
    }
    return 0;
}

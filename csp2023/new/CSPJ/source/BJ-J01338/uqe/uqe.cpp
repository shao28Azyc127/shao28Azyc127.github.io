#include <bits/stdc++.h>
using namespace std;

int t, m;

int check(int n) {
    int ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % (i * i) == 0) ans = i;
    }
    return ans;
}
int ch(int n) {
    int ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % (i * i) == 0) ans = i;
    }
    return n / (ans * ans);
}
void pr(int b, int a) {
    if (abs(b) % abs(a) == 0) {
        printf("%d", b / a);
        return ;
    }
    printf("%d/%d", b / __gcd(abs(a), abs(b)), a / __gcd(abs(a), abs(b)));
}

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &t, &m);
    while (t--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a < 0) {
            a = -a;
            b = -b;
            c = -c;
        }
        int delta = (b * b - (4 * a * c));
        if (delta < 0) {
            printf("NO\n");
            continue;
        }
        int pfn = ch(delta);
        int pfw = check(delta);
        if (pfn == 1) {
            int up = pfw - b;
            pr(up, 2 * a);
        } else if (pfn == 0) {
            pr(-1 * b, 2 * a);
            printf("\n");
            continue;
        } else {
            if (!b == 0) {
                pr(-1 * b, 2 * a);
                printf("+");
            }
            int up = pfw / __gcd(pfw, abs(2 * a));
            int down = 2 * a / __gcd(pfw, abs(2 * a));
            if (up == 1 && down == 1) printf("sqrt(%d)", pfn);
            else if (up == 1) printf("sqrt(%d)/%d", pfn, down);
            else if (down == 1) printf("%d*sqrt(%d)", up, pfn);
            else {
                printf("%d*sqrt(%d)/%d", up, pfn, down);
            }
        }
        printf("\n");
    }
    return 0;
}

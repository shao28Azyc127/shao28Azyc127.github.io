#include <stdio.h>
#define ll long long
struct sta { int a[5]; };
int b[100005];
int si(sta x) {
    int y = 0;
    for (int i = 0; i < 5; i++) y = y * 10 + x.a[i];
    return y;
}
sta is(int y) {
    sta x;
    for (int i = 0; i < 5; i++, y /= 10) x.a[4-i] = y % 10;
    return x;
}
#define add(a, j) (a += j) >= 10 && (a -= 10)
void count(sta x) {
    ll ret = 0;
    for (int i = 0; i < 5; i++) {//count1
        int t = x.a[i];
        for (int j = 1; j < 10; j++) {
            add(x.a[i], j);
            b[si(x)]++;
            x.a[i] = t;
        }
    }
    for (int i = 0; i < 4; i++) {//count2
        int s = x.a[i], t = x.a[i+1];
        for (int j = 1; j < 10; j++) {
            add(x.a[i], j); add(x.a[i+1], j);
            b[si(x)]++;
            x.a[i] = s; x.a[i+1] = t;
        }
    }
}
sta read() {
    sta x;
    for (int i = 0; i < 5; i++) scanf("%d", &x.a[i]);
    return x;
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) count(read());
    int ans = 0;
    for (int i = 0; i < 100000; i++) ans += (b[i] == n);
    printf("%d\n", ans);
    return 0;
}